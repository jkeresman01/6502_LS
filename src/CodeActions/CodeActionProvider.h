#pragma once

#include <memory>

#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Types/CodeAction.h"
#include "ICodeActionsProvider.h"

namespace ls6502
{
class CodeActionProvider : public ICodeActionsProvider
{
  public:
    CodeActionProvider();

    std::vector<CodeAction> getCodeActions(const std::string &document, const std::string &URI) override;

  private:
    std::shared_ptr<IDiagnosticsProvider> m_diagnosticsProvider;
    std::vector<CodeAction> m_codeActions;
};
} // namespace ls6502
