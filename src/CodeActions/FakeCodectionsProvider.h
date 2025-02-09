#pragma once

#include "../Types/CodeAction.h"
#include "ICodeActionsProvider.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class FakeCodeActionsProvider
///
/// @brief A mock implementation of the ICodeActionsProvider
///        interface, providing fake code actions for testing
///        and demonstration purposes.
///
//////////////////////////////////////////////////////////////
class FakeCodeActionsProvider : public ICodeActionsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of fake code actions for a given URI.
    ///
    /// @param URI
    /// @return A vector of CodeAction objects representing the
    ///         fake code actions.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> getCodeActions(const std::string &URI) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Populates the provided vector with fake code actions.
    ///
    /// @param codeAction
    /// @param URI
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeCodeActions(std::vector<CodeAction> &codeAction, const std::string &URI);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Logs the list of generated fake code actions.
    ///
    /// @param codeAction
    ///
    //////////////////////////////////////////////////////////////
    void logCodeActions(std::vector<CodeAction> &codeAction);
};

} // namespace justanlsp
