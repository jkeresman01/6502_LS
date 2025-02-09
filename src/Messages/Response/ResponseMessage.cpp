#include "ResponseMessage.h"
#include <ostream>

namespace justanlsp
{

ResponseMessage::ResponseMessage(const std::string &jsonRpc, int64_t id) : Message(jsonRpc), m_id(id){};

ResponseMessage::ResponseMessage(const std::string &jsonRpc, const int64_t id,
                                 const ResponseError &responseError)
    : Message(jsonRpc), m_id(id), m_responseError(responseError){};

nlohmann::json ResponseMessage::toJson() const
{
    nlohmann::json result = {{"jsonrpc", m_jsonRPC}, {"id", m_id}};

    if (m_responseError)
    {
        result["error"] = m_responseError->toJson();
    }

    return result;
}

std::ostream &operator<<(std::ostream &os, const ResponseMessage &responseMessage)
{
    nlohmann::json jsonRPC = responseMessage.toJson();

    os << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}

} // namespace justanlsp
