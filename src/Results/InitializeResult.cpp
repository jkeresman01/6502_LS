#include "InitializeResult.h"

#include <sstream>
#include <string>

namespace justanlsp
{

InitializeResult::InitializeResult(const ServerInfo &serverInfo, const ServerCapabilities &serverCapabilites)
    : m_serverInfo(serverInfo), m_serverCapabilities(serverCapabilites)
{
}

nlohmann::json InitializeResult::toJson() const
{
    // TODO completionProvider and hoverProvider are hardoced for test purposes

    return {{"serverinfo", m_serverInfo.toJson()},
            {"capabilities",
             {{"textDocumentSync", m_serverCapabilities.toJson()},
              {"hoverProvider", true},
              {"completionProvider",
               {{"resolveProvider", false}, {"completionItem", {{"snippetSupport", true}}}}}}}};
}

std::string InitializeResult::toString() const
{
    std::stringstream ss;
    ss << "Initialization result for server { " << m_serverInfo.toString() << " }";
    return ss.str();
}

} // namespace justanlsp
