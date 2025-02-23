#pragma once

#include "WrongInstructionUsageDiagnosticsAnalyzer.h"

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"

#include <string>
#include <vector>

namespace ls6502
{

std::vector<CodeAction> WrongInstructionUsageDiagnosticsAnalyzer::provideCodeActions(
    const Diagnostic &diagnostic, const std::string &document, const std::string &URI)
{
    m_codeActions.clear();

    WorkspaceEdit workspaceEdit;
    std::vector<TextEdit> textEdits;

    Range range = diagnostic.getRange();

    // TODO Replace with a valid instruction
    std::string replacementText = "// Adjust syntax based on valid addressing modes";

    textEdits.emplace_back(range, replacementText);
    workspaceEdit.addChange({URI, textEdits});

    CodeAction codeAction = CodeAction::Builder()
                                .withTitle("Fix instruction usage")
                                .withCodeActionKind(CodeActionKind::REFACTOR)
                                .withPrefferedFix(false)
                                .withWorkspaceEdit(workspaceEdit)
                                .build();

    m_codeActions.push_back(codeAction);

    return m_codeActions;
}
} // namespace ls6502
