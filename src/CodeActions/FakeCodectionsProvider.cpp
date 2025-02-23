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

    std::vector<CodeAction> codeActions(FAKE_CODE_ACTIONS_NO);
    fillFakeCodeActions(codeActions, URI);
    return codeActions;
}

void FakeCodeActionsProvider::fillFakeCodeActions(std::vector<CodeAction> &codeActions,
                                                  const std::string &URI)
{
    std::vector<TextEdit> textEdits {{{{2, 0}, {4, 10}}, "New text"}};

    WorkspaceEdit workspaceEdit;
    workspaceEdit.addChange({URI, textEdits});

    codeActions[0] = createFakeCodeAction(workspaceEdit, "Fake code action 1");
    codeActions[1] = createFakeCodeAction(workspaceEdit, "Fake code action 2");
    codeActions[2] = createFakeCodeAction(workspaceEdit, "Fake code action 3");
}

CodeAction FakeCodeActionsProvider::createFakeCodeAction(const WorkspaceEdit &workspaceEdit,
                                                         const std::string &title)
{
    return CodeAction::Builder()
        .withTitle(title)
        .withCodeActionKind(CodeActionKind::QUICK_FIX)
        .withPrefferedFix(false)
        .withWorkspaceEdit(workspaceEdit)
        .build();
}

} // namespace ls6502
