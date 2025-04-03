#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"
#include "../Analyzers/Diagnostics/IDiagnosticsAnalyzer.h"

#include <string>
#include <vector>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class WrongInstructionUsageDiagnosticsAnalyzer
///
/// @brief A diagnostics analyzer that detects and provides
///        code actions for incorrect usage of instructions
///        in the document.
///
//////////////////////////////////////////////////////////////
class WrongInstructionUsageDiagnosticsAnalyzer : public IDiagnosticsAnalyzer
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Provides code actions based on a given diagnostic.
    ///
    /// @param [in] diagnostic
    /// @param [in] document
    /// @param [in] URI
    ///
    /// @return A vector of CodeAction objects representing possible
    ///         fixes or improvements for the diagnostic.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> provideCodeActions(const Diagnostic &diagnostic, const std::string &document,
                                               const std::string &URI) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates a code action based on the provided
    ///        workspace edit.
    ///
    /// @param [in] workspaceEdit
    ///
    /// @return A CodeAction object representing the suggested fix.
    ///
    //////////////////////////////////////////////////////////////
    CodeAction createCodeAction(const WorkspaceEdit &workspaceEdit);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Stores available code actions for the analyzer.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> m_codeActions;
};

} // namespace ls6502
