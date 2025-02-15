#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "../Repo/IInstructionSetRepository.h"
#include "IDiagnosticsProvider.h"

namespace ls6502
{
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

class DiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    DiagnosticsProvider();

    std::vector<Diagnostic> getDiagnostics(const std::string &document) override;

  private:
    void checkMalformedLabel(const std::string &line, size_t lineNumber);
    void checkInvalidSemicolonUsage(const std::string &line, size_t lineNumber);
    void checkUnsupportedInstructions(const std::string &line, size_t lineNumber);
    void checkGeneralSyntaxErrors(const std::string &line, size_t lineNumber);

  private:
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    std::vector<Diagnostic> m_diagnostics;

    InstructionSetMapT m_instructionSet;
};
} // namespace ls6502
