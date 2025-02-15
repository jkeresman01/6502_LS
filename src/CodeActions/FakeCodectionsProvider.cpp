#include "FakeCodectionsProvider.h"

#include "../Types/CodeAction.h"
#include "../Types/Range.h"
#include "../Types/TextEdit.h"
#include "../Types/WorkspaceEdit.h"

#include <vector>

namespace ls6502
{
std::vector<CodeAction> FakeCodeActionsProvider::getCodeActions(const std::string &document,
                                                                const std::string &URI)
{
    (void)document;

    std::vector<CodeAction> codeActions;
    fillFakeCodeActions(codeActions, URI);
    return codeActions;
}

void FakeCodeActionsProvider::fillFakeCodeActions(std::vector<CodeAction> &codeActions,
                                                  const std::string &URI)
{
    WorkspaceEdit workspaceEdit;
    Range range{{2, 0}, {4, 10}};

    TextEdit textEdit(range, "New text");

    std::vector<TextEdit> textEdits;
    textEdits.push_back(textEdit);
    workspaceEdit.addChange({URI, textEdits});

    CodeAction firstFakeCodeAction = CodeAction::Builder()
                                         .withTitle("Code action test")
                                         .withCodeActionKind(CodeActionKind::QUICK_FIX)
                                         .withPrefferedFix(false)
                                         .withWorkspaceEdit(workspaceEdit)
                                         .build();

    CodeAction secondFakeCodeAction = CodeAction::Builder()
                                          .withTitle("Code action test 1")
                                          .withCodeActionKind(CodeActionKind::QUICK_FIX)
                                          .withPrefferedFix(false)
                                          .withWorkspaceEdit(workspaceEdit)
                                          .build();

    CodeAction thirdFakeCodeAction = CodeAction::Builder()
                                         .withTitle("Code action test 2")
                                         .withCodeActionKind(CodeActionKind::QUICK_FIX)
                                         .withPrefferedFix(false)
                                         .withWorkspaceEdit(workspaceEdit)
                                         .build();

    codeActions.push_back(firstFakeCodeAction);
    codeActions.push_back(secondFakeCodeAction);
    codeActions.push_back(thirdFakeCodeAction);
}

} // namespace ls6502
