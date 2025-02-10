#pragma once

#include "RequestMessage.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ShutdownRequest
///
/// @brief A general message as defined by JSON-RPC.
///
//////////////////////////////////////////////////////////////

class ShutdownRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Initialize request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit ShutdownRequest(const nlohmann::json &jsonRPC) : RequestMessage(jsonRPC){};
};
} // namespace ls6502
