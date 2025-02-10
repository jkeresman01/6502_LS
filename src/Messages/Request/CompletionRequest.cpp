#include "CompletionRequest.h"

#include "../../Utils/Logger.h"

namespace ls6502
{
CompletionRequest::CompletionRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void CompletionRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No params in request with method: textDocument/completion");
        return;
    }

    m_completionParams = std::make_shared<CompletionParams>(jsonRPC["params"]);
}

} // namespace ls6502
