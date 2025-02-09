#include "DidChangeTextDocumentRequest.h"

#include "../Utils/Logger.h"

namespace ls6052
{
DidChangeTextDocumentRequest::DidChangeTextDocumentRequest(const nlohmann::json &jsonRPC)
    : NotificationMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DidChangeTextDocumentRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No params in textDocument/didChange notification!");
        return;
    }

    m_didChangeTextDocumentParams = std::make_shared<DidChangeTextDocumentParams>(jsonRPC["params"]);
}
} // namespace ls6052
