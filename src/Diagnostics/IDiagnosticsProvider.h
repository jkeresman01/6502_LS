#pragma once

#include <string>
#include <vector>

#include "../Types/Diagnostic.h"
#include "../Types/Position.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class IDiagnosticsProvider
///
/// @brief An interface for providing diagnostics for a
///        given document and position.
///
//////////////////////////////////////////////////////////////
class IDiagnosticsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of diagnostics for a given
    ///        document and position.
    ///
    /// @param document
    /// @param position
    ///
    /// @return A vector of Diagnostic objects representing the
    ///         diagnostics for the specified document and position.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<Diagnostic> getDiagnostics(const std::string &document) = 0;
};

} // namespace ls6502
