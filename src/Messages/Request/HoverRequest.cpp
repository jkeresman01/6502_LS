#include "HoverRequest.h"

#include "../../Utils/Logger.h"

namespace ls6052
{
HoverRequest::HoverRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setParams(jsonRPC);
}

void HoverRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No params in textDocument/hover request");
        return;
    }

    m_hoverParams = std::make_shared<HoverParams>(jsonRPC["params"]);
}

} // namespace ls6052
