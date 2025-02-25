#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "../Enums/DiagnosticSeverity.h"
#include "../Enums/DiagnosticsTag.h"
#include "../Types/DiagnosticsRelatedInformation.h"
#include "Range.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class Diagnostic
///
/// @brief Represents a diagnostic item in language server protocol
///
//////////////////////////////////////////////////////////////
class Diagnostic
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor
    ///
    //////////////////////////////////////////////////////////////
    Diagnostic() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a Diagnostic item with specified range.
    ///
    /// @param [in] range
    /// @param [in] severity
    /// @param [in] source
    /// @param [in] message
    ///
    //////////////////////////////////////////////////////////////
    Diagnostic(const Range &range, const DiagnosticSeverity &severity, const std::string &source,
               const std::string &message);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes Diagnostics item to JSON format
    ///
    /// @return Diagnostics item in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Adds new diagnostics tag
    ///
    //////////////////////////////////////////////////////////////
    void addDiagnosticsTag(const DiagnosticTag diagnosticsTag);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for diagnostics message
    ///
    /// @return diagnostics message
    ///
    //////////////////////////////////////////////////////////////
    std::string getMessage() const { return m_message; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for diagnostics range
    ///
    /// @return diagnostics range
    ///
    //////////////////////////////////////////////////////////////
    Range getRange() const { return m_range; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range in the source code where the diagnostic applies.
    ///
    //////////////////////////////////////////////////////////////
    Range m_range;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The severity level of the diagnostic
    ///
    //////////////////////////////////////////////////////////////
    DiagnosticSeverity m_severity;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Specifies the source
    ///
    //////////////////////////////////////////////////////////////
    std::string m_source;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Diagnostic tags
    ///
    //////////////////////////////////////////////////////////////
    std::vector<DiagnosticTag> m_diagnosticsTag;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Additional information about diagnostics
    ///
    //////////////////////////////////////////////////////////////
    std::vector<DiagnosticRelatedInformation> m_diagnosticsRelatedInformation;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The diagnostic message
    ///
    //////////////////////////////////////////////////////////////
    std::string m_message;
};

} // namespace ls6502
