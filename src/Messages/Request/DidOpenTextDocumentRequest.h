#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../Notification/NotificationMessage.h"
#include "../Params/DidOpenTextDocumentParams.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class DidOpenTextDocumentRequest
///
/// @brief Represents a request message for the textDocument/didOpen request
///        in the Language Server Protocol (LSP).
///
//////////////////////////////////////////////////////////////
class DidOpenTextDocumentRequest : public NotificationMessage
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a DidOpenTextDocumentRequest from a JSON-RPC request.
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit DidOpenTextDocumentRequest(const nlohmann::json& jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for textDocument/didOpen params
    ///
    /// @param [in] textDocument/didOpen params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DidOpenTextDocumentParams> getParams() const
    {
        return m_params;
    };

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Sets the parameters for the textDocument/didOpen request.
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json& jsonRPC);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the parameters for the textDocument/didOpen request
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DidOpenTextDocumentParams> m_params;
};
} // namespace ls6502
