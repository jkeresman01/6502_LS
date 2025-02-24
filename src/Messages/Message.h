#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>
#include <ostream>
#include <set>
#include <string>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class Message
///
/// @brief A general message as defined by JSON-RPC.
///
//////////////////////////////////////////////////////////////
class Message
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Message from jsonRPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit Message(const std::string &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Serializes the message to JSON format
    ///
    /// @return Returns serialized Message in JSON format
    ///
    //////////////////////////////////////////////////////////////
    virtual nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the output stream operator for ResponseMessage
    ///
    /// @param out
    /// @param responseMessage
    ///
    /// @return The modified output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream &operator<<(std::ostream &os, const Message &mesage);

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief RPC version, language server protocol always
    ///        uses "2.0" as the jsonrpc version
    ///
    //////////////////////////////////////////////////////////////
    std::string m_jsonRPC;
};

} // namespace ls6502
