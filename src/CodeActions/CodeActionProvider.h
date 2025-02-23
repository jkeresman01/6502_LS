#pragma once

#include <memory>

#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Types/CodeAction.h"
#include "ICodeActionsProvider.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class CodeActionProvider
///
/// @brief Provides code actions based on document diagnostics
///
/////////////////////////////////////////////////////////////////////
class CodeActionProvider : public ICodeActionsProvider
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Constructor for CodeActionProvider
    ///
    /////////////////////////////////////////////////////////////////////
    CodeActionProvider();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves available code actions for a given document
    ///
    /// @param document
    /// @param URI
    ///
    /// @return A vector of available code actions
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<CodeAction> getCodeActions(const std::string &document, const std::string &URI) override;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for diagnostics provider
    ///
    /// @param diagnosticsProvider
    ///
    /////////////////////////////////////////////////////////////////////
    void setDiagnosticsProvider(const std::shared_ptr<IDiagnosticsProvider> &diagnosticsProvider);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates code actions for missing label diagnostic
    ///
    /// @param diagnostic
    /// @param document
    /// @param URI
    ///
    /////////////////////////////////////////////////////////////////////
    void createCodeActionsForMissingLabel(const Diagnostic &diagnostic, const std::string &document,
                                          const std::string &URI);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates code actions for unsupported instruction diagnostic
    ///
    /// @param diagnostic
    /// @param document
    /// @param URI
    ///
    /////////////////////////////////////////////////////////////////////
    void createCodeActionsForUnsupportedInstruction(const Diagnostic &diagnostic, const std::string &document,
                                                    const std::string &URI);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates code actions for incorrect instruction usage
    ///
    /// @param diagnostic
    /// @param document
    /// @param URI
    ///
    /////////////////////////////////////////////////////////////////////
    void createCodeActionsForIncorrectInstructionUsage(const Diagnostic &diagnostic,
                                                       const std::string &document, const std::string &URI);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Provider for document diagnostics
    ///
    /////////////////////////////////////////////////////////////////////
    std::shared_ptr<IDiagnosticsProvider> m_diagnosticsProvider;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Code actions
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<CodeAction> m_codeActions;
};

} // namespace ls6502
