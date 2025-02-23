#pragma once

#include "IncorrectLabelDiagnosticsAnalyzer.h"

namespace ls6502
{
std::vector<CodeAction> IncorrectLabelDiagnosticsAnalyzer::provideCodeActions(const Diagnostic &diagnostic,
                                                                              const std::string &document,
                                                                              const std::string &URI)
{
    m_codeActions.clear();

    Range range = diagnostic.getRange();
    std::string replacementText = document.substr(range.start.character, range.end.character) + ":";
    textEdits.emplace_back();

    std::vector<TextEdit> textEdits{{range, replacementText}};

    WorkspaceEdit workspaceEdit;
    workspaceEdit.addChange({URI, textEdits});

    m_codeActions.push_back(createCodeAction(workspaceEdit));
}

CodeAction IncorrectLabelDiagnosticsAnalyzer::createCodeAction(const WorkspaceEdit &workspaceEdit)
{
    return CodeAction::Builder()
        .withTitle("Add missing ':' to label")
        .withCodeActionKind(CodeActionKind::QUICK_FIX)
        .withPrefferedFix(true)
        .withWorkspaceEdit(workspaceEdit)
        .build();
}

} // namespace ls6502
