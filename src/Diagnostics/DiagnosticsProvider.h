#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "../Repo/IInstructionSetRepository.h"
#include "IDiagnosticsProvider.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// Typedefs
///
/////////////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

/////////////////////////////////////////////////////////////////////
///
/// @class DiagnosticsProvider
///
/// @brief Provides diagnostics for assembly code
///
/////////////////////////////////////////////////////////////////////
class DiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Constructor for DiagnosticsProvider
    ///
    /////////////////////////////////////////////////////////////////////
    DiagnosticsProvider();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves diagnostics for a given document
    ///
    /// @param document
    ///
    /// @return A vector of diagnostic issues found in the document
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<Diagnostic> getDiagnostics(const std::string &document) override;

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for malformed labels in a given line
    ///
    /// @param line
    /// @param lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkMalformedLabel(const std::string &line, size_t lineNumber);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for invalid semicolon usage in a given line
    ///
    /// @param line
    /// @param lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkInvalidSemicolonUsage(const std::string &line, size_t lineNumber);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for unsupported instructions in a given line
    ///
    /// @param line
    /// @param lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkUnsupportedInstructions(const std::string &line, size_t lineNumber);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for general syntax errors in a given line
    ///
    /// @param line
    /// @param lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkGeneralSyntaxErrors(const std::string &line, size_t lineNumber);

  private:
    std::shared_ptr<IInstructionSetRepository>
        m_instructionSetRepository;        ///< Repository for instruction set data
    std::vector<Diagnostic> m_diagnostics; ///< List of collected diagnostics
    InstructionSetMapT m_instructionSet;   ///< Map of instruction names to Instruction objects
};

} // namespace ls6502
k
