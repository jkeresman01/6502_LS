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
        bool isLabelMissing = diagnostic.getMessage().find("Label missing ':'") != std::string::npos;

        if (isLabelMissing)
        {
            createCodeActionsForMissingLabel(diagnostic, document, URI);
        }

        bool isInstructionUnsopproted =
            diagnostic.getMessage().find("Unsupported instruction") != std::string::npos;

        if (isInstructionUnsopproted)
        {
            createCodeActionsForUnsupportedInstruction(diagnostic, document, URI);
        }

        bool isInstructionUsageIncorrect =
            diagnostic.getMessage().find("Incorrect instruction usage") != std::string::npos;

        if (isInstructionUnsopproted)
        {
            createCodeActionsForIncorrectInstructionUsage(diagnostic, document, URI);
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
