////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Ls6502Client.h"
#include <memory>

#include "../Utils/Logger.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
Ls6502Client::Ls6502Client(const ClientInfo& clientInfo, const std::shared_ptr<ClientCapabilities>& clientCapabilites)
{
    saveInfo(clientInfo);
    registerCapabilites(clientCapabilites);
}


////////////////////////////////////////////////////////////
void Ls6502Client::saveInfo(const ClientInfo& clientInfo)
{
    m_clientInfo = clientInfo;
}


////////////////////////////////////////////////////////////
void Ls6502Client::registerCapabilites(const std::shared_ptr<ClientCapabilities>& clientCapabilites)
{
    m_clientCapabilities = clientCapabilites;
}


////////////////////////////////////////////////////////////
void Ls6502Client::addDocument(const std::string& URI, const std::string& document)
{
    m_documentsByURI.emplace(URI, document);

    LS_6502_DEBUG(
        STR("Added text document with URI: %s, for client: %s", URI.c_str(), m_clientInfo.toString().c_str()));
}


////////////////////////////////////////////////////////////
std::optional<std::string> Ls6502Client::getDocumentByURI(const std::string& URI) const
{
    DocumentsMapT::const_iterator it = m_documentsByURI.find(URI);

    if (it == m_documentsByURI.end())
    {
        LS_6502_ERROR(STR("There are no documents with URI: %s !", URI.c_str()));
        return std::nullopt;
    }

    return std::make_optional(it->second);
}


////////////////////////////////////////////////////////////
void Ls6502Client::updateDocumentWithURI(const std::string& URI, const std::string& document)
{
    m_documentsByURI[URI] = document;

    LS_6502_DEBUG(
        STR("Updated text document with URI: %s, for client: %s", URI.c_str(), m_clientInfo.toString().c_str()));
}


} // namespace ls6502
