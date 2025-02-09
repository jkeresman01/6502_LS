#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../../Results/CodeActionResult.h"
#include "ResponseMessage.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class CodeActionResponse
///
/// @brief Represents a response message for a code action request.
///
//////////////////////////////////////////////////////////////
class CodeActionResponse : public ResponseMessage
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a CodeActionResponse with given parameters.
    ///
    /// @param jsonRPC
    /// @param id
    /// @param hoverResult
    ///
    //////////////////////////////////////////////////////////////
    CodeActionResponse(const std::string &jsonRPC, const int64_t id,
                       const CodeActionResult &codeActionResult);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the CodeActionResponse to a JSON representation.
    ///
    /// @return A JSON object representing the CodeActionResponse.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the output stream operator for CodeActionResponse.
    ///
    /// @param os
    /// @param codeActionResponse
    ///
    /// @return The modified output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream &operator<<(std::ostream &os, const CodeActionResponse &codeActionResponse);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The code action result associated with this response.
    ///
    //////////////////////////////////////////////////////////////
    CodeActionResult m_codeActionResult;
};
} // namespace justanlsp
