#include "NotificationMessage.h"

namespace ls6052
{

NotificationMessage::NotificationMessage(const nlohmann::json &jsonRPC)
    : Message("2.0"), m_method(jsonRPC["method"])
{
}

NotificationMessage::NotificationMessage(const std::string &method) : Message("2.0"), m_method(method) {}

nlohmann::json NotificationMessage::toJson() const
{
    return {Message::toJson(), "method", m_method};
}

} // namespace ls6052
