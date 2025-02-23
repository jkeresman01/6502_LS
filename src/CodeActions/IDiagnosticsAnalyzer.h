#pragma once

#include "../Types/CodeAction.h"
#include "../Types/Diagnostic.h"

#include <string>
#include <vector>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class IDiagnosticsAnalyzer
///
/// @brief Interface for analyzing diagnostics and providing
///        code actions based on detected issues in a document.
///
//////////////////////////////////////////////////////////////
class IDiagnosticsAnalyzer
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Pure virtual function to provide code actions based
    ///        on a given diagnostic and document.
    ///
    /// @param diagnostic  A reference to the Diagnostic object
    ///                    representing the issue.
    /// @param document
    /// @param URI
    ///
    /// @return A vector of CodeAction objects representing the
    ///         available fixes or suggestions for the diagnostic.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<CodeAction> provideCodeActions(const Diagnostic &diagnostic,
                                                       const std::string &document,
                                                       const std::string &URI) = 0;
};
} // namespace ls6502
