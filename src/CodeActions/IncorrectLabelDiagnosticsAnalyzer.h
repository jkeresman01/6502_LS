#pragma once

#include "IDiagnosticsAnalyzer.h"

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"

#include <string>
#include <vector>

namespace ls6502
{

class IncorrectLabelDiagnosticsAnalyzer : public IDiagnosticsAnalyzer
{
  public:
    std::vector<CodeAction> provideCodeActions(const Diagnostic &diagnostic, const std::string &document,
                                               const std::string &URI) override;

  private:
    CodeAction createCodeAction(const WorkspaceEdit &workspaceEdit);

  private:
    std::vector<CodeAction> m_codeActions;
};
} // namespace ls6502
