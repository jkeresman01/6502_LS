#include "InitializeResponse.h"

#include <cstdint>
#include <sstream>
#include <string>

namespace justanlsp
{

InitializeResponse::InitializeResponse(const std::string &jsonRPC, const int64_t &id,
                                       const InitializeResult &initializeResult)
    : ResponseMessage(jsonRPC, id), m_initializeResut(initializeResult)
{
}

nlohmann::json InitializeResponse::toJson() const
{
    return {{"jsonrpc", m_jsonRPC},
            {"id", m_id},
            {"result",
             {{"serverInfo", m_initializeResut.getServerInfo().toJson()},
              {"capabilities", m_initializeResut.getServerCapabilities().toJson()}}}};
}

std::string InitializeResponse::toString() const
{
    std::stringstream ss;
    ss << "Initialization response from server { " << m_initializeResut.toString() << " }";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const InitializeResponse &initializeResponse)
{
    nlohmann::json jsonRPC = initializeResponse.toJson();

    os << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}

} // namespace justanlsp
