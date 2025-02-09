#pragma once

#include <string>

#include "../Messages/Message.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class NotificationMessage
///
/// @brief Represents a notification message in the
///        language server protocol (LSP).
///        Notification messages are sent from the client to
///        the server or vice versa without requiring a response.
///
//////////////////////////////////////////////////////////////
class NotificationMessage : public Message
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a NotificationMessage with the specified
    ///        method and JSON-RPC version.
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit NotificationMessage(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a NotificationMessage with the specified
    ///        method
    ///
    /// @param method
    ///
    //////////////////////////////////////////////////////////////
    explicit NotificationMessage(const std::string &method);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a NotificationMessage with the specified
    ///        method
    ///
    /// @param method
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const override;

  protected:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The method of the notification, which describes the action or event.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_method;
};

} // namespace justanlsp
