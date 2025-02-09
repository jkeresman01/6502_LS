#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <ostream>

#include "../../Params/PublishDiagnosticsParams.h"
#include "NotificationMessage.h"

namespace justanlsp
{
class PublishDiagnosticsNoticifation : public NotificationMessage
{
  public:
    PublishDiagnosticsNoticifation(const std::string &method,
                                   const std::shared_ptr<PublishDiagnosticsParams> &diagnosticsParams);
    nlohmann::json toJson() const override;

    friend std::ostream &operator<<(std::ostream &os,
                                    const PublishDiagnosticsNoticifation &publishDiagsnosticsNotification);

    std::shared_ptr<PublishDiagnosticsParams> getParams() const { return m_diagnosticsParams; };

  private:
    std::shared_ptr<PublishDiagnosticsParams> m_diagnosticsParams;
};
} // namespace justanlsp
