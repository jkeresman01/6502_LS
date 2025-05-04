////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "TextDocumentPositionParams.h"

#include "../Utils/Logger.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
TextDocumentPositionParams::TextDocumentPositionParams(const nlohmann::json& jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC["textDocument"]);
    setPosition(jsonRPC["position"]);
}


////////////////////////////////////////////////////////////
void TextDocumentPositionParams::setPosition(const nlohmann::json& jsonRPC)
{
    m_position.line      = jsonRPC["line"];
    m_position.character = jsonRPC["character"];
}


////////////////////////////////////////////////////////////
void TextDocumentPositionParams::setTextDocumentIdentifier(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No text docuemnt identifier in TextDocumentPositionParams");
        return;
    }

    m_textDocument.URI = jsonRPC["uri"];
}


} // namespace ls6502
