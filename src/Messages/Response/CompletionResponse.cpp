#include "CompletionResponse.h"

namespace justanlsp
{

CompletionResponse::CompletionResponse(const std::string &jsonRPC, int64_t &id,
                                       const CompletionResult &completionResult)
    : ResponseMessage(jsonRPC, id), m_completionResult(completionResult)
{
}

nlohmann::json CompletionResponse::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}, {"id", m_id}, {"result", m_completionResult.toJson()}};
}

std::ostream &operator<<(std::ostream &os, const CompletionResponse &comletionResponse)
{
    nlohmann::json jsonRPC = comletionResponse.toJson();

    os << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}

} // namespace justanlsp
