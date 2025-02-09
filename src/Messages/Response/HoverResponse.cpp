#include "HoverResponse.h"

namespace justanlsp
{
HoverResponse::HoverResponse(const std::string &jsonRPC, const int64_t id, const HoverResult &hoverResult)
    : ResponseMessage(jsonRPC, id), m_hoverResult(hoverResult)
{
}

nlohmann::json HoverResponse::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}, {"id", m_id}, {"result", m_hoverResult.toJson()}};
}

std::ostream &operator<<(std::ostream &os, const HoverResponse &hoverResponse)
{
    nlohmann::json jsonRPC = hoverResponse.toJson();

    os << "Content-length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}
} // namespace justanlsp
