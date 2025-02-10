#include "DidChangeTextDocumentParams.h"

#include "../Utils/Logger.h"

namespace ls6502
{

DidChangeTextDocumentParams::DidChangeTextDocumentParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentIdentifier(jsonRPC["textDocument"]);
    setContentChanges(jsonRPC["contentChanges"][0]);
}

void DidChangeTextDocumentParams::setTextDocumentIdentifier(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No textDocument in textDocument/didChange notification!");
        return;
    }

    m_textDocument.URI = jsonRPC["uri"];
}

void DidChangeTextDocumentParams::setContentChanges(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("text");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No text changes in textDocument/didChange notification!");
        return;
    }

    m_contentChanges = jsonRPC["text"];
}
} // namespace ls6502
