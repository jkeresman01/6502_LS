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

  private:
    std::shared_ptr<IDiagnosticsProvider> m_diagnosticsProvider; ///< Provider for document diagnostics
    std::vector<CodeAction> m_codeActions;                       ///< code actions
};

} // namespace ls6502
