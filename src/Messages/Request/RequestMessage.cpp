////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "RequestMessage.h"
#include <nlohmann/json.hpp>

#include "../Message.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
RequestMessage::RequestMessage(const nlohmann::json& jsonRPC) : Message("2.0")
{
    setId(jsonRPC);
    setMethod(jsonRPC);
}


////////////////////////////////////////////////////////////
void RequestMessage::setId(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("id");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("Can't construct Request message, there is no id in request");
        return;
    }

    m_id = jsonRPC["id"];
}


////////////////////////////////////////////////////////////
void RequestMessage::setMethod(const nlohmann::json& jsonRPC)
{
    auto it = jsonRPC.find("method");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("Can't construct Request message, there is no method in request");
        return;
    }

    m_method = jsonRPC["method"];
}


} // namespace ls6502
