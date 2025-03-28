#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>

#include "../Types/Diagnostic.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class DiagnosticsUtil
///
/// @brief Utility class for diagnostic message validation
///
/////////////////////////////////////////////////////////////////////
class DiagnosticsUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    DiagnosticsUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validates if provided diagnostic is for missing label
    ///
    /// @param [in] diagnostic
    ///
    /// @return true if label is missing semicolo, false otherwise
    ///
    /////////////////////////////////////////////////////////////////////
    static bool isLabelMissingSemicolon(const Diagnostic &diagnostic);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validates if provided diagnostic is for missing label
    ///
    /// @param [in] diagnostic
    ///
    /// @return true if label is missing semicolo, false otherwise
    ///
    /////////////////////////////////////////////////////////////////////
    static bool isInstructionUnsupproted(const Diagnostic &diagnostic);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validates if provided diagnostic is for incorrect
    ///        instruction usage
    ///
    /// @param [in] diagnostic
    ///
    /// @return true if instruction was incorrectly used, false otherwise
    ///
    /////////////////////////////////////////////////////////////////////
    static bool isInstructionUsageIncorrect(const Diagnostic &diagnostic);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
bool inline DiagnosticsUtil::isLabelMissingSemicolon(const Diagnostic &diagnostic)
{
    return diagnostic.getMessage().find("Label missing ':'") != std::string::npos;
}

////////////////////////////////////////////////////////////
bool inline DiagnosticsUtil::isInstructionUnsupproted(const Diagnostic &diagnostic)
{
    return diagnostic.getMessage().find("Unsupported instruction") != std::string::npos;
}

////////////////////////////////////////////////////////////
bool inline DiagnosticsUtil::isInstructionUsageIncorrect(const Diagnostic &diagnostic)
{
    return diagnostic.getMessage().find("Incorrect instruction usage") != std::string::npos;
}

} // namespace ls6502
