#include "CodeActionProvider.h"

#include "../Diagnostics/DiagnosticsProviderFactory.h"

namespace ls6502
{
CodeActionProvider::CodeActionProvider() : m_diagnosticsProvider(DiagnosticsProviderFactory::create()) {}

std::vector<CodeAction> CodeActionProvider::getCodeActions(const std::string &document,
                                                           const std::string &URI)
{
    std::vector<Diagnostic> diagnostics = m_diagnosticsProvider->getDiagnostics(document);

    // TODO resever size from diagnostics, since vector size is known, will remove need to reallocate memorius
    // every timeius
    // TODO don't forget

    for (const auto &diagnostic : diagnostics)
    {
        WorkspaceEdit workspaceEdit;
        std::vector<TextEdit> textEdits;

        Range range = diagnostic.getRange();
        std::string replacementText;

        if (diagnostic.getMessage().find("Label missing ':'") != std::string::npos)
        {
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
        else if (diagnostic.getMessage().find("Unexpected ';'") != std::string::npos)
        {
            replacementText = document.substr(range.start.character + 1, range.end.character - 1);

            textEdits.emplace_back(range, replacementText);
            workspaceEdit.addChange({URI, textEdits});

            CodeAction codeAction = CodeAction::Builder()
                                        .withTitle("Remove unexpected ';'")
                                        .withCodeActionKind(CodeActionKind::QUICK_FIX)
                                        .withPrefferedFix(false)
                                        .withWorkspaceEdit(workspaceEdit)
                                        .build();

            m_codeActions.push_back(codeAction);
        }
        else if (diagnostic.getMessage().find("Unsupported instruction") != std::string::npos)
        {
            replacementText = "// Replace with a valid instruction";

            textEdits.emplace_back(range, replacementText);
            workspaceEdit.addChange({URI, textEdits});

            CodeAction codeAction = CodeAction::Builder()
                                        .withTitle("Replace unsupported instruction")
                                        .withCodeActionKind(CodeActionKind::REFACTOR)
                                        .withPrefferedFix(false)
                                        .withWorkspaceEdit(workspaceEdit)
                                        .build();

            m_codeActions.push_back(codeAction);
        }
        else if (diagnostic.getMessage().find("Incorrect instruction usage") != std::string::npos)
        {
            replacementText = "// Adjust syntax based on valid addressing modes";

            textEdits.emplace_back(range, replacementText);
            workspaceEdit.addChange({URI, textEdits});

            CodeAction codeAction = CodeAction::Builder()
                                        .withTitle("Fix instruction usage")
                                        .withCodeActionKind(CodeActionKind::REFACTOR)
                                        .withPrefferedFix(false)
                                        .withWorkspaceEdit(workspaceEdit)
                                        .build();

            m_codeActions.push_back(codeAction);
        }
    }

    return m_codeActions;
}
} // namespace ls6502
