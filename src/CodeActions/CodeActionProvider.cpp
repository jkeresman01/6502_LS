#include "CodeActionProvider.h"

#include <algorithm>
#include <string>

#include "../Diagnostics/DiagnosticsProviderFactory.h"
#include "DiagnosticsAnalyerFactory.h"

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

    std::vector<CodeAction> codeActions;

    for (const auto &diagnostic : diagnostics)
    {
        m_diagnosticsAnalyzer = DiagnosticsAnalyzerFactory::getInstance(diagnostic);
        codeActions = m_diagnosticsAnalyzer->provideCodeActions(diagnostic, document, URI);
        m_codeActions.insert(m_codeActions.end(), codeActions.begin(), codeActions.end());
    }

    return m_codeActions;
}
} // namespace ls6502
