#include "PublishDiagnosticsNotification.h"

namespace justanlsp
{

PublishDiagnosticsNoticifation::PublishDiagnosticsNoticifation(
    const std::string &method, const std::shared_ptr<PublishDiagnosticsParams> &diagnosticsParams)
    : NotificationMessage(method), m_diagnosticsParams(diagnosticsParams)
{
}

nlohmann::json PublishDiagnosticsNoticifation::toJson() const
{
    return {{"jsonrpc", m_jsonRPC}, {"method", m_method}, {"params", m_diagnosticsParams->toJson()}};
}

std::ostream &operator<<(std::ostream &os,
                         const PublishDiagnosticsNoticifation &publishDiagsnosticsNotification)
{
    nlohmann::json jsonRPC = publishDiagsnosticsNotification.toJson();

    os << "Content-Length: " << jsonRPC.dump().size() << "\r\n\r\n";
    os << jsonRPC.dump() << std::endl;

    return os;
}

} // namespace justanlsp
