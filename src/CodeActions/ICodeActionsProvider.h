#pragma once

#include "../Types/CodeAction.h"

#include <vector>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ICodeActionsProvider
///
/// @brief Interface for providing code actions in response to
///        a given document URI.
///
//////////////////////////////////////////////////////////////
class ICodeActionsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Pure virtual function to retrieve code actions for
    ///        a specified document.
    ///
    /// @param URI
    ///
    /// @return A vector of CodeAction objects representing the
    ///         available code actions for the document.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<CodeAction> getCodeActions(const std::string &URI) = 0;
};

} // namespace justanlsp
