#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <nlohmann/json.hpp>

#include "../../Params/CodeActionParams.h"
#include "RequestMessage.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class CompletionRequest
///
/// @brief The Code actions request is sent from the client to
///        the Ls6502 server to provide code actions
///        for a given document
///
//////////////////////////////////////////////////////////////
class CodeActionRequest : public RequestMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the Code action request from JSON RPC
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit CodeActionRequest(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for text document code action params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<CodeActionParams> getParams() const { return m_codeActionParams; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for text document code action params
    ///
    //////////////////////////////////////////////////////////////
    void setParams(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief textDocument/codeAction params
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<CodeActionParams> m_codeActionParams;
};
} // namespace ls6502
