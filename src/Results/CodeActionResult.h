#pragma once

#include <vector>

#include "../Types/CodeAction.h"
#include <nlohmann/json.hpp>

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class CodeActionResult
///
/// @brief Represents the result of a code action request.
///
//////////////////////////////////////////////////////////////
class CodeActionResult
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a CodeActionResult with the given list
    ///        of code actions.
    ///
    /// @param codeActions
    ///
    //////////////////////////////////////////////////////////////
    CodeActionResult(const std::vector<CodeAction> &codeActions) : m_codeActions(codeActions){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the CodeActionResult object into a
    ///        JSON representation.
    ///
    /// @return A nlohmann::json object representing the CodeActionResult.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief A vector of CodeAction objects that are included in the result.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> m_codeActions;
};

} // namespace justanlsp
