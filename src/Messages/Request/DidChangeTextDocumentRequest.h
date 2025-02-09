#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "../Notification/NotificationMessage.h"
#include "../Params/DidChangeTextDocumentParams.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class DidChangeTextDocumentRequest
///
/// @brief Represents a textDocument/didChange request in the LSP
///
//////////////////////////////////////////////////////////////
class DidChangeTextDocumentRequest : public NotificationMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs textDocument/didChange from a JSON-RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit DidChangeTextDocumentRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the parameters associated with this request.
    ///
    /// @return textDocument/didChange params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DidChangeTextDocumentParams> getParams() const { return m_didChangeTextDocumentParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for textDocument/didChange params
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/didChange parameters
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<DidChangeTextDocumentParams> m_didChangeTextDocumentParams;
};

} // namespace justanlsp
