////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "DiagnosticsProvider.h"
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "../../Repo/Instructions/FactoryImpl/InstructionSetRepoFactory.h"
#include "../../Types/Range.h"
#include "../../Utils/DocumentUtil.h"
#include "../../Utils/Logger.h"
#include "../../Utils/StringUtil.h"

namespace ls6502
{

// TODO refactor this whole thing

////////////////////////////////////////////////////////////
DiagnosticsProvider::DiagnosticsProvider() : m_instructionSetRepository(InstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository->load();
}

////////////////////////////////////////////////////////////
std::vector<Diagnostic> DiagnosticsProvider::getDiagnostics(const std::string& document)
{
    m_diagnostics.clear();

    std::vector<std::string> lines = DocumentUtil::splitDocumentIntoLines(document);

    for (size_t lineNumber = 0; lineNumber < lines.size(); ++lineNumber)
    {
        checkMalformedLabel(lines[lineNumber], lineNumber);
        checkUnsupportedInstructions(lines[lineNumber], lineNumber);
        checkGeneralSyntaxErrors(lines[lineNumber], lineNumber);
    }

    return m_diagnostics;
}

////////////////////////////////////////////////////////////
void DiagnosticsProvider::checkMalformedLabel(const std::string& line, size_t lineNumber)
{
    std::regex  labelRegex(R"(^\s*([A-Za-z_][A-Za-z0-9_]*)\s*$)");
    std::smatch match;

    InstructionSetMapT::iterator it = m_instructionSet.find(line);

    bool isMissingColon = std::regex_match(line, match, labelRegex);

    if (isMissingColon)
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, line.size()},
                                   DiagnosticSeverity::WARNING,
                                   typeid(*this).name(),
                                   "Malformed label");
    }
}

////////////////////////////////////////////////////////////
void DiagnosticsProvider::checkUnsupportedInstructions(const std::string& line, size_t lineNumber)
{
    std::istringstream iss(line);

    std::string mnemonic;
    iss >> mnemonic;

    StringUtil::trim(mnemonic);

    InstructionSetMapT::iterator it = m_instructionSet.find(mnemonic);

    bool isValid6502ASMInstruction = it != m_instructionSet.end();

    if (!mnemonic.empty() and !isValid6502ASMInstruction)
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, mnemonic.size()},
                                   DiagnosticSeverity::ERROR,
                                   typeid(*this).name(),
                                   "Unsupported instruction: " + mnemonic);
    }
}

////////////////////////////////////////////////////////////
void DiagnosticsProvider::checkGeneralSyntaxErrors(const std::string& line, size_t lineNumber)
{
    std::regex validSyntaxRegex(R"(^\s*([A-Za-z_][A-Za-z0-9_]*:)?\s*([A-Z]{2,3})?\s*([^;]*)?(;.*)?$)");

    bool isValidSyntax = std::regex_match(line, validSyntaxRegex);

    if (!isValidSyntax)
    {
        m_diagnostics.emplace_back(Range{lineNumber, 0, lineNumber, line.size()},
                                   DiagnosticSeverity::ERROR,
                                   typeid(*this).name(),
                                   "General syntax error");
    }
}
} // namespace ls6502
