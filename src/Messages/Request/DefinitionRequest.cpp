#include "DefinitionRequest.h"

#include "../../Utils/Logger.h"

namespace ls6502
{
DefintionRequest::DefintionRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void DefintionRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No params in textDocument/definition request");
        return;
    }

    m_hoverParams = std::make_shared<DefinitionParams>(jsonRPC["params"]);
}

} // namespace ls6502
