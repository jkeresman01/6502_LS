#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "../Types/Diagnostic.h"

namespace ls6502
{
class PublishDiagnosticsParams
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the PublishDiagnosticsParams object
    ///
    /// @param [in] URI
    /// @param [in] diagnostics
    ///
    //////////////////////////////////////////////////////////////
    PublishDiagnosticsParams(const std::string& URI, const std::vector<Diagnostic>& diagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the PublishDiagnosticsParams object to JSON format
    ///
    /// @return JSON representation of the diagnostics parameters
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts diagnostic items to JSON format
    ///
    /// @return JSON array of diagnostic items
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json dianosticItemsToJson() const;

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The URI of the document for which diagnostics are published
    ///
    //////////////////////////////////////////////////////////////
    std::string m_URI;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The list of diagnostics associated with the document
    ///
    //////////////////////////////////////////////////////////////
    std::vector<Diagnostic> m_diagnostics;
};
} // namespace ls6502
