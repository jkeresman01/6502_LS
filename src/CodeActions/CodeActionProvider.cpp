#include "CodeActionProvider.h"

#include "../Diagnostics/DiagnosticsProviderFactory.h"

namespace ls6502
{
CodeActionProvider::CodeActionProvider() : m_diagnosticsProvider(DiagnosticsProviderFactory::create()) {}

void CodeActionProvider::setDiagnosticsProvider(
    const std::shared_ptr<IDiagnosticsProvider> &diagnosticsProvider)
{
    m_diagnosticsProvider = diagnosticsProvider;
};

std::vector<CodeAction> CodeActionProvider::getCodeActions(const std::string &document,
                                                           const std::string &URI)
{
    std::vector<Diagnostic> diagnostics = m_diagnosticsProvider->getDiagnostics(document);

    for (const auto &diagnostic : diagnostics)
    {
        if (isLabelMissingSemicolon(diagnostic))
        {
            fillCodeActionsForMissingLabel(diagnostic, document, URI);
        }

        if (isInstructionUnsupproted(diagnostic))
        {
            fillCodeActionsForUnsupportedInstruction(diagnostic, document, URI);
        }

        if (isInstructionUsageIncorrect(diagnostic))
        {
            fillCodeActionsForIncorrectInstructionUsage(diagnostic, document, URI);
        }
    }

    return m_codeActions;
}

void CodeActionProvider::createCodeActionsForMissingLabel(const Diagnostic &diagnostic,
                                                          const std::string &document, const std::string &URI)
{
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

void CodeActionProvider::createCodeActionsForUnsupportedInstruction(const Diagnostic &diagnostic,
                                                                    const std::string &document,
                                                                    const std::string &URI)
{
    WorkspaceEdit workspaceEdit;
    std::vector<TextEdit> textEdits;

    Range range = diagnostic.getRange();

    // TODO Replace with a valid instruction
    std::string replacementText = "// Replace with a valid instruction";

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

void CodeActionProvider::createCodeActionsForIncorrectInstructionUsage(const Diagnostic &diagnostic,
                                                                       const std::string &document,
                                                                       const std::string &URI)
{
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
}

} // namespace ls6502
