#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "../../Params/CompletionParams.h"
#include "RequestMessage.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class CompletionRequest
///
/// @brief The Completion request is sent from the client to
///        the Ls6502 server to compute completion items
///        at a given cursor position.
///
//////////////////////////////////////////////////////////////
class CompletionRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Completion request from JSON RPC
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit CompletionRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text document completion params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<CompletionParams> getParams() const { return m_completionParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for text document completion params
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/completion params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<CompletionParams> m_completionParams;
};
} // namespace justanlsp
