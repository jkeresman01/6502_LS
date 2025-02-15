#include "DiagnosticsProvider.h"

#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "../Repo/InstructionSetRepoFactory.h"
#include "../Types/Range.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"

namespace ls6502
{

DiagnosticsProvider::DiagnosticsProvider() : m_instructionSetRepository(IInstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository->load();
}

std::vector<Diagnostic> DiagnosticsProvider::getDiagnostics(const std::string &document)
{
    std::vector<std::string> lines = DocumentUtil::splitDocumentIntoLines(document);

    for (size_t lineNumber = 0; lineNumber < lines.size(); ++lineNumber)
    {
        checkMalformedLabel(lines[lineNumber], lineNumber);
        checkInvalidSemicolonUsage(lines[lineNumber], lineNumber);
        checkUnsupportedInstructions(lines[lineNumber], lineNumber);
        checkGeneralSyntaxErrors(lines[lineNumber], lineNumber);
    }

    return m_diagnostics;
}

void DiagnosticsProvider::checkMalformedLabel(const std::string &line, size_t lineNumber)
{
    std::regex labelRegex(R"(^\s*([A-Za-z_][A-Za-z0-9_]*)\s*$)");
    std::smatch match;

    if (std::regex_match(line, match, labelRegex))
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, line.size()}, DiagnosticSeverity::WARNING,
                                   "Parser", "Label missing ':' at end");
    }
}

void DiagnosticsProvider::checkInvalidSemicolonUsage(const std::string &line, size_t lineNumber)
{
    std::regex invalidSemicolonRegex(R"(^\s*;\S.*$)");

    if (std::regex_match(line, invalidSemicolonRegex))
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, line.size()}, DiagnosticSeverity::ERROR,
                                   "Parser", "Invalid non-comment word starting with ';'");
    }
}

void DiagnosticsProvider::checkUnsupportedInstructions(const std::string &line, size_t lineNumber)
{
    std::istringstream iss(line);
    std::string mnemonic;
    iss >> mnemonic;

    if (!mnemonic.empty() and m_instructionSet.find(mnemonic) == m_instructionSet.end())
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, mnemonic.size()},
                                   DiagnosticSeverity::ERROR, "Parser",
                                   "Unsupported instruction: " + mnemonic);
    }
}

void DiagnosticsProvider::checkGeneralSyntaxErrors(const std::string &line, size_t lineNumber)
{
    std::regex validSyntaxRegex(R"(^\s*([A-Za-z_][A-Za-z0-9_]*:)?\s*([A-Z]{2,3})?\s*([^;]*)?(;.*)?$)");

    if (!std::regex_match(line, validSyntaxRegex))
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, line.size()}, DiagnosticSeverity::ERROR,
                                   "Parser", "General syntax error");
    }
}
} // namespace ls6502
