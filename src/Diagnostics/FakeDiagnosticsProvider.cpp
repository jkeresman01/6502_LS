#include "FakeDiagnosticsProvider.h"

namespace justanlsp
{

std::vector<Diagnostic> FakeDiagnosticsProvider::getDiagnostics(const std::string &document,
                                                                const Position &position)
{
    std::vector<Diagnostic> diagnostics;
    fillFakeDiagnostics(diagnostics);
    return diagnostics;
}

void FakeDiagnosticsProvider::fillFakeDiagnostics(std::vector<Diagnostic> &diagnostics)
{
    fillFakeHints(diagnostics);
    fillFakeWarnings(diagnostics);
    fillFakeErrors(diagnostics);
    fillFakeInfo(diagnostics);
}

void FakeDiagnosticsProvider::fillFakeErrors(std::vector<Diagnostic> &diagnostics)
{
    diagnostics.emplace_back(Range{10, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                             "First ERROR message");
    diagnostics.emplace_back(Range{20, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                             "Second ERROR message");
    diagnostics.emplace_back(Range{30, 10}, DiagnosticSeverity::ERROR, "Source is this stuff",
                             "Third ERROR message");
}

void FakeDiagnosticsProvider::fillFakeWarnings(std::vector<Diagnostic> &diagnostics)
{
    diagnostics.emplace_back(Range{40, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                             "First WARNING message");
    diagnostics.emplace_back(Range{50, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                             "Second WARNING message");
    diagnostics.emplace_back(Range{60, 10}, DiagnosticSeverity::WARNING, "Source is this stuff",
                             "Third WARNING message");
}

void FakeDiagnosticsProvider::fillFakeHints(std::vector<Diagnostic> &diagnostics)
{
    diagnostics.emplace_back(Range{70, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                             "First HINT message");
    diagnostics.emplace_back(Range{80, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                             "Second HINT message");
    diagnostics.emplace_back(Range{90, 10}, DiagnosticSeverity::HINT, "Source is this stuff",
                             "Third HINT message");
}

void FakeDiagnosticsProvider::fillFakeInfo(std::vector<Diagnostic> &diagnostics)
{
    diagnostics.emplace_back(Range{100, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                             "First INFORMATION message");
    diagnostics.emplace_back(Range{110, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                             "Second INFORMATION message");
    diagnostics.emplace_back(Range{120, 10}, DiagnosticSeverity::INFORMATION, "Source is this stuff",
                             "Third INFORMATION message");
}

} // namespace justanlsp
