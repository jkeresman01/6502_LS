////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Message.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
Message::Message(const std::string& jsonRPC) : m_jsonRPC(jsonRPC)
{
}

////////////////////////////////////////////////////////////
nlohmann::json Message::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}};
}

////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Message& mesage)
{
    nlohmann::json jsonRPC = mesage.toJson();

    os << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}

} // namespace ls6502
