#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../ICodeActionsProvider.h"
#include "../Types/CodeAction.h"

namespace ls6502
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
    /// @param [in] URI
    ///
    /// @return A vector of CodeAction objects representing the
    ///         fake code actions.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> getCodeActions(const std::string& document, const std::string& URI) override;

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Populates the provided vector with fake code actions.
    ///
    /// @param [in] codeAction
    /// @param [in] URI
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeCodeActions(std::vector<CodeAction>& codeAction, const std::string& URI);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Logs the list of generated fake code actions.
    ///
    /// @param [in] codeAction
    ///
    //////////////////////////////////////////////////////////////
    void logCodeActions(std::vector<CodeAction>& codeAction);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates fake code action
    ///
    /// @param [in] label
    /// @param [in] workspaceEdit
    ///
    //////////////////////////////////////////////////////////////
    CodeAction createFakeCodeAction(const WorkspaceEdit& worskpaceEdit, const std::string& label);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Number of fake code actions that will be provided
    ///
    //////////////////////////////////////////////////////////////
    static constexpr uint32_t FAKE_CODE_ACTIONS_NO = 3;
};

} // namespace ls6502
