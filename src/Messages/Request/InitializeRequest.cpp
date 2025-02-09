#include "InitializeRequest.h"

#include "../Utils/Logger.h"

namespace justanlsp
{

InitializeRequest::InitializeRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC)
{
    setInitializeParams(jsonRPC);
}

void InitializeRequest::setInitializeParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No initliaze params in initialize request");
        return;
    }

    m_initializeParams = std::make_shared<InitializeParams>(jsonRPC["params"]);
}

} // namespace justanlsp
