////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "CompletionParams.h"

#include "../Utils/Logger.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
CompletionParams::CompletionParams(const nlohmann::json& jsonRPC)
{
    setCompletionContext(jsonRPC["context"]);
    setPosition(jsonRPC["position"]);
    setTextDocumentIdentifier(jsonRPC["textDocument"]);
}


////////////////////////////////////////////////////////////
void CompletionParams::setCompletionContext(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("triggerKind");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No trigger king was set in textDocument/comletion request");
        return;
    }

    m_completionContext.completionTriggerKind = jsonRPC["triggerKind"];
}


////////////////////////////////////////////////////////////
void CompletionParams::setPosition(const nlohmann::json& jsonRPC)
{
    m_position.character = jsonRPC["character"];
    m_position.line      = jsonRPC["line"];
}


////////////////////////////////////////////////////////////
void CompletionParams::setTextDocumentIdentifier(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No textDocumentIdentifier(UR) was set in textDocument/comletion request");
        return;
    }

    m_textDocumentIdentifier.URI = jsonRPC["uri"];
}


} // namespace ls6502
