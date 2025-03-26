#include "FakeDiagnosticsProvider.h"

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
    m_diagnostics.emplace_back(Range{10, 10}, DiagnosticSeverity::ERROR, typeid(*this).name(),
                               "First ERROR message");
    m_diagnostics.emplace_back(Range{20, 10}, DiagnosticSeverity::ERROR, typeid(*this).name(),
                               "Second ERROR message");
    m_diagnostics.emplace_back(Range{30, 10}, DiagnosticSeverity::ERROR, typeid(*this).name(),
                               "Third ERROR message");
}

void FakeDiagnosticsProvider::fillFakeWarnings()
{
    m_diagnostics.emplace_back(Range{40, 10}, DiagnosticSeverity::WARNING, typeid(*this).name(),
                               "First WARNING message");
    m_diagnostics.emplace_back(Range{50, 10}, DiagnosticSeverity::WARNING, typeid(*this).name(),
                               "Second WARNING message");
    m_diagnostics.emplace_back(Range{60, 10}, DiagnosticSeverity::WARNING, typeid(*this).name(),
                               "Third WARNING message");
}

void FakeDiagnosticsProvider::fillFakeHints()
{
    m_diagnostics.emplace_back(Range{70, 10}, DiagnosticSeverity::HINT, typeid(*this).name(),
                               "First HINT message");
    m_diagnostics.emplace_back(Range{80, 10}, DiagnosticSeverity::HINT, typeid(*this).name(),
                               "Second HINT message");
    m_diagnostics.emplace_back(Range{90, 10}, DiagnosticSeverity::HINT, typeid(*this).name(),
                               "Third HINT message");
}

void FakeDiagnosticsProvider::fillFakeInfo()
{
    m_diagnostics.emplace_back(Range{100, 10}, DiagnosticSeverity::INFORMATION, typeid(*this).name(),
                               "First INFORMATION message");
    m_diagnostics.emplace_back(Range{110, 10}, DiagnosticSeverity::INFORMATION, typeid(*this).name(),
                               "Second INFORMATION message");
    m_diagnostics.emplace_back(Range{120, 10}, DiagnosticSeverity::INFORMATION, typeid(*this).name(),
                               "Third INFORMATION message");
}

} // namespace ls6502
