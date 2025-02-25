#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <ostream>

#include "../../Params/PublishDiagnosticsParams.h"
#include "NotificationMessage.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class PublishDiagnosticsNoticifation
///
/// @brief Represents a notification message for publishing diagnostics
///        in the language server protocol (LSP).
///        This message is sent to notify the client about diagnostics
///        related to a specific document.
///
//////////////////////////////////////////////////////////////
class PublishDiagnosticsNoticifation : public NotificationMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a PublishDiagnosticsNoticifation with the
    ///        specified method and diagnostics parameters.
    ///
    /// @param [in] method
    /// @param [in] diagnosticsParams
    ///
    //////////////////////////////////////////////////////////////
    PublishDiagnosticsNoticifation(const std::string &method,
                                   const std::shared_ptr<PublishDiagnosticsParams> &diagnosticsParams);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the notification to a JSON object.
    ///
    /// @return A JSON representation of the notification.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const override;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the stream insertion operator to print
    ///        the PublishDiagnosticsNoticifation.
    ///
    /// @param [in,out] os
    /// @param [in] publishDiagsnosticsNotification
    ///
    /// @return Reference to the output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream &operator<<(std::ostream &os,
                                    const PublishDiagnosticsNoticifation &publishDiagsnosticsNotification);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the diagnostics parameters.
    ///
    /// @return Shared pointer to the diagnostics parameters.
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<PublishDiagnosticsParams> getParams() const { return m_diagnosticsParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The diagnostics parameters associated with this notification.
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<PublishDiagnosticsParams> m_diagnosticsParams;
};

} // namespace ls6502
