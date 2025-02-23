#pragma once

#include "IncorrectLabelDiagnosticsAnalyzer.h"

namespace ls6502
{
std::vector<CodeAction> IncorrectLabelDiagnosticsAnalyzer::provideCodeActions(const Diagnostic &diagnostic,
                                                                              const std::string &document,
                                                                              const std::string &URI)
{
    m_codeActions.clear();

    WorkspaceEdit workspaceEdit;
    std::vector<TextEdit> textEdits;

    Range range = diagnostic.getRange();
    std::string replacementText;
    replacementText = document.substr(range.start.character, range.end.character) + ":";

    textEdits.emplace_back(range, replacementText);
    workspaceEdit.addChange({URI, textEdits});

    CodeAction codeAction = CodeAction::Builder()
                                .withTitle("Add missing ':' to label")
                                .withCodeActionKind(CodeActionKind::QUICK_FIX)
                                .withPrefferedFix(true)
                                .withWorkspaceEdit(workspaceEdit)
                                .build();

    m_codeActions.push_back(codeAction);
}
} // namespace ls6502
