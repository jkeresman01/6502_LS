#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <cstdint>
#include <string>

#include "ResponseMessage.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ShutdownResponse
///
/// @brief Represents a response message for the "shutdown" request
///        in the JSON-RPC protocol.
///
//////////////////////////////////////////////////////////////
class ShutdownResponse : public ResponseMessage
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a ShutdownResponse message.
    ///
    /// @param [in] jsonRPC
    /// @param [in] id
    ///
    //////////////////////////////////////////////////////////////
    ShutdownResponse(const std::string& jsonRPC, int64_t id) : ResponseMessage(jsonRPC, id)
    {
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the ShutdownResponse to JSON format.
    ///
    /// @return The shutdown response in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const override
    {
        nlohmann::json json = ResponseMessage::toJson();
        json["result"]      = nullptr;
        return json;
    }
};

} // namespace ls6502
