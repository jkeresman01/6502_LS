#pragma once

#include <nlohmann/json.hpp>
#include <ostream>
#include <string>

#include "../Messages/Response/ResponseMessage.h"
#include "../Results/CompletionResult.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class CompletionResponse
///
/// @brief Represents a response message for a completion request
///        in the language server protocol.
///
//////////////////////////////////////////////////////////////
class CompletionResponse : public ResponseMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a CompletionResponse with the given JSON-RPC
    ///
    /// @param jsonRPC
    /// @param id
    /// @param completionResult
    ///
    //////////////////////////////////////////////////////////////
    CompletionResponse(const std::string &jsonRPC, int64_t &id, const CompletionResult &completionResult);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the completion response to JSON format.
    ///
    /// @return Returns a JSON object representing the completion response
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const override;

    friend std::ostream &operator<<(std::ostream &os, const CompletionResponse &completionResponse);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Holds the completion result data, which includes a list of
    ///        potential code completions for the client.
    ///
    //////////////////////////////////////////////////////////////
    CompletionResult m_completionResult;
};

} // namespace justanlsp
