////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "InitializeParams.h"
#include <string>

#include "../Utils/Logger.h"
#include "../Utils/TraceUtil.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
InitializeParams::InitializeParams(const nlohmann::json& jsonInitializeParams)
{
    setProccessId(jsonInitializeParams);
    setClientInfo(jsonInitializeParams);
}


////////////////////////////////////////////////////////////
void InitializeParams::setProccessId(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("processId");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No process id was set in request");
        return;
    }

    m_processId = jsonRPC["processId"];
}


////////////////////////////////////////////////////////////
void InitializeParams::setLocale(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("locale");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No locale value was set in Initialize request");
        return;
    }

    m_locale = jsonRPC["locale"];
}


////////////////////////////////////////////////////////////
void InitializeParams::setClientInfo(const nlohmann::json& jsonRPC)
{
    nlohmann::json clientInfoJson = jsonRPC["clientInfo"];

    m_clientInfo.name    = clientInfoJson["name"];
    m_clientInfo.version = clientInfoJson["version"];
}


////////////////////////////////////////////////////////////
void InitializeParams::setTraceLevel(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("trace");

    if (it == jsonRPC.end())
    {
        LS_6502_WARN("No trace value set in Initialize request, defaulting to TraceValue::OFF");

        m_traceValue = TraceValue::OFF;

        return;
    }

    m_traceValue = jsonRPC["trace"];
}


} // namespace ls6502
