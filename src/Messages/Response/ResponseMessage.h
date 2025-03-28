#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../Messages/Message.h"
#include "ResponseError.h"

#include <cstdint>
#include <nlohmann/json.hpp>
#include <optional>
#include <ostream>
#include <string>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ResponseMessage
///
/// @brief Represents a response message in the JSON-RPC protocol.
///        This message can either be a successful response or
///        an error response.
///
//////////////////////////////////////////////////////////////
class ResponseMessage : public Message
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a successful ResponseMessage.
    ///
    /// @param [in] jsonRpc
    /// @param [in] id
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage(const std::string &jsonRpc, const int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs an error ResponseMessage.
    ///
    /// @param [in] jsonRpc
    /// @param [in] id
    /// @param [in] responseError
    ///
    //////////////////////////////////////////////////////////////
    ResponseMessage(const std::string &jsonRpc, const int64_t id, const ResponseError &responseError);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the response message to JSON format.
    ///
    /// @return Returns the ResponseMessage in serialized JSON format.
    ///
    //////////////////////////////////////////////////////////////
    virtual nlohmann::json toJson() const override;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the output stream operator for ResponseMessage
    ///
    /// @param [in] out
    /// @param [in] responseMessage
    ///
    /// @return The modified output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream &operator<<(std::ostream &out, const ResponseMessage &responseMessage);

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unique identifier for the request associated
    ///        with the response.
    ///
    //////////////////////////////////////////////////////////////
    int64_t m_id;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Optional error message for error responses.
    ///
    /// @details Stores an error description when the response
    ///          is an error. If the response is successful,
    ///          this remains empty.
    ///
    //////////////////////////////////////////////////////////////
    std::optional<ResponseError> m_responseError;
};

} // namespace ls6502
