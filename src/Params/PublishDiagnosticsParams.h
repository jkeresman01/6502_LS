#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include "../Types/Diagnostic.h"

namespace justanlsp
{
class PublishDiagnosticsParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the PublishDiagnosticsParams object
    ///
    /// @param URI
    /// @param diagnostics
    ///
    //////////////////////////////////////////////////////////////
    PublishDiagnosticsParams(const std::string &URI, const std::vector<Diagnostic> &diagnostics);

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
} // namespace justanlsp
