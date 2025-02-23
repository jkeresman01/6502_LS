#pragma once

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"
#include "IDiagnosticsAnalyzer.h"

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
    /// @param diagnostic
    /// @param document
    /// @param URI
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
    /// @brief Stores available code actions for the analyzer.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CodeAction> m_codeActions;
};

} // namespace ls6502
