#pragma once

#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

#include "../Enums/CodeActionKind.h"
#include "WorkspaceEdit.h"

namespace ls6052
{
//////////////////////////////////////////////////////////////
///
/// @class CodeAction
///
/// @brief Represents a code action as defined by LSP
///
//////////////////////////////////////////////////////////////
class CodeAction
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation
    ///
    //////////////////////////////////////////////////////////////
    CodeAction() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a CodeAction with given parameters.
    ///
    /// @param title
    /// @param codeActionKind
    /// @param isPreffered
    /// @param edit
    ///
    //////////////////////////////////////////////////////////////
    CodeAction(const std::string &title, const CodeActionKind &codeActionKind, const bool isPreffered,
               const WorkspaceEdit &edit);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the CodeAction to a string representation.
    ///
    /// @return A string representation of the CodeAction.
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the CodeAction to a JSON representation.
    ///
    /// @return A JSON object representing the CodeAction.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @class Builder
    ///
    /// @brief Builder class for constructing CodeAction objects.
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
      public:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the title of the CodeAction.
        ///
        /// @param title
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withTitle(const std::string &title);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the kind of the CodeAction.
        ///
        /// @param codeActionKind
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCodeActionKind(const CodeActionKind &codeActionKind);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets whether this code action is preferred.
        ///
        /// @param isPreffered
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withPrefferedFix(bool isPreffered);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the workspace edit associated with the CodeAction.
        ///
        /// @param workspaceEdit
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withWorkspaceEdit(const WorkspaceEdit &workspaceEdit);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Builds and returns a CodeAction object.
        ///
        /// @return The constructed CodeAction.
        ///
        //////////////////////////////////////////////////////////////
        CodeAction build();

      private:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Title of the code action.
        ///
        //////////////////////////////////////////////////////////////
        std::string m_title;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief The kind of code action.
        ///
        //////////////////////////////////////////////////////////////
        CodeActionKind m_codeActionKind;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Whether this action is preferred.
        ///
        //////////////////////////////////////////////////////////////
        bool m_isPreffered;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Associated workspace edit.
        ///
        //////////////////////////////////////////////////////////////
        WorkspaceEdit m_workspaceEdit;
    };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Title of the code action.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_title;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The kind of code action.
    ///
    //////////////////////////////////////////////////////////////
    CodeActionKind m_codeActionKind;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Whether this action is preferred.
    ///
    //////////////////////////////////////////////////////////////
    bool m_isPreffered;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Associated workspace edit.
    ///
    //////////////////////////////////////////////////////////////
    WorkspaceEdit m_workspaceEdit;
};
} // namespace ls6052
