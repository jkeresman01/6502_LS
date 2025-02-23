#include "FakeDiagnosticsProvider.h" FakeDi

namespace ls6502
{

FakeDiagnosticsProvider::FakeDiagnosticsProvider()
{
    fillFakeDiagnostics();
}

FakeDiagnosticsProvider::FakeDiagnosticsProvider(const std::vector<Diagnostic> &mockDiagnostics)
    : m_diagnostics(mockDiagnostics)
{
}

std::vector<Diagnostic> FakeDiagnosticsProvider::getDiagnostics(const std::string &document)
{
    (void)document;

    return m_diagnostics;
}

void FakeDiagnosticsProvider::fillFakeDiagnostics()
{
    fillFakeHints();
    fillFakeWarnings();
    fillFakeErrors();
    fillFakeInfo();
}

void FakeDiagnosticsProvider::fillFakeErrors()
{
    m_diagnostics.emplace_back(Range{10, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                               "First ERROR message");
    m_diagnostics.emplace_back(Range{20, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                               "Second ERROR message");
    m_diagnostics.emplace_back(Range{30, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                               "Third ERROR message");
}

void FakeDiagnosticsProvider::fillFakeWarnings()
{
    m_diagnostics.emplace_back(Range{40, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                               "First WARNING message");
    m_diagnostics.emplace_back(Range{50, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                               "Second WARNING message");
    m_diagnostics.emplace_back(Range{60, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                               "Third WARNING message");
}

void FakeDiagnosticsProvider::fillFakeHints()
{
    m_diagnostics.emplace_back(Range{70, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                               "First HINT message");
    m_diagnostics.emplace_back(Range{80, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                               "Second HINT message");
    m_diagnostics.emplace_back(Range{90, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                               "Third HINT message");
}

void FakeDiagnosticsProvider::fillFakeInfo()
{
    m_diagnostics.emplace_back(Range{100, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                               "First INFORMATION message");
    m_diagnostics.emplace_back(Range{110, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                               "Second INFORMATION message");
    m_diagnostics.emplace_back(Range{120, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                               "Third INFORMATION message");
}

} // namespace ls6502
