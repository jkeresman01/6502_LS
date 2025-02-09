#pragma once

#include <vector>

#include "../Types/Diagnostic.h"
#include "IDiagnosticsProvider.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class FakeDiagnosticsProvider
///
/// @brief A mock implementation of the IDiagnosticsProvider interface.
///        This class is used to simulate diagnostics, providing fake
///        diagnostic information for testing or mock scenarios.
///
/// @note This class does not analyze the document or position for real errors.
///       Instead, it generates fake diagnostics for different types such as
///       hints, warnings, errors, and information.
///
/// @implements IDiagnosticsProvider
///
//////////////////////////////////////////////////////////////
class FakeDiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor for FakeDiagnosticsProvider.
    ///
    //////////////////////////////////////////////////////////////
    FakeDiagnosticsProvider() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of fake diagnostics for a given document and position.
    ///
    /// @param document
    /// @param position
    ///
    /// @return A vector of Diagnostic objects representing the fake diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<Diagnostic> getDiagnostics(const std::string &document, const Position &position) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with a combination of fake diagnostics.
    ///
    /// @param diagnostics The vector to be populated with fake diagnostic data.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeDiagnostics(std::vector<Diagnostic> &diagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake hint diagnostics.
    ///
    /// @param diagnostics The vector to be populated with hint diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeHints(std::vector<Diagnostic> &diagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake warning diagnostics.
    ///
    /// @param diagnostics The vector to be populated with warning diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeWarnings(std::vector<Diagnostic> &diagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake error diagnostics.
    ///
    /// @param diagnostics The vector to be populated with error diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeErrors(std::vector<Diagnostic> &diagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake informational diagnostics.
    ///
    /// @param diagnostics The vector to be populated with informational diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeInfo(std::vector<Diagnostic> &diagnostics);
};

} // namespace justanlsp
