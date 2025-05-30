#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <string>
#include <unordered_map>

#include "../../Repo/Instructions/IInstructionSetRepository.h"
#include "../IDiagnosticsProvider.h"

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
    /// @param [in] document
    ///
    /// @return A vector of diagnostic issues found in the document
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<Diagnostic> getDiagnostics(const std::string& document) override;

private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for malformed labels in a given line
    ///
    /// @param [in] line
    /// @param [in] lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkMalformedLabel(const std::string& line, size_t lineNumber);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for unsupported instructions in a given line
    ///
    /// @param [in] line
    /// @param [in] lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkUnsupportedInstructions(const std::string& line, size_t lineNumber);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Checks for general syntax errors in a given line
    ///
    /// @param [in] line
    /// @param [in] lineNumber
    ///
    /////////////////////////////////////////////////////////////////////
    void checkGeneralSyntaxErrors(const std::string& line, size_t lineNumber);

private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Repository for instruction set data
    ///
    /////////////////////////////////////////////////////////////////////
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief List of collected diagnostics
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<Diagnostic> m_diagnostics;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Map of instruction names to Instruction objects
    ///
    /////////////////////////////////////////////////////////////////////
    InstructionSetMapT m_instructionSet;
};

} // namespace ls6502
