#pragma once

#include <vector>

#include "../Types/Diagnostic.h"
#include "IDiagnosticsProvider.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class FakeDiagnosticsProvider
///
/// @brief A mock implementation of the IDiagnosticsProvider
///        interface. This class is used to simulate diagnostics,
///        providing fake diagnostic information for testing or
///        mock scenarios.
///
//////////////////////////////////////////////////////////////
class FakeDiagnosticsProvider : public IDiagnosticsProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mock constructor for FakeDiagnosticsProvider.
    ///
    //////////////////////////////////////////////////////////////
    FakeDiagnosticsProvider();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mock constructor for FakeDiagnosticsProvider.
    ///
    /// @param mockDiagnostics
    ///
    //////////////////////////////////////////////////////////////
    explicit FakeDiagnosticsProvider(const std::vector<Diagnostic> &mockDiagnostics);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a vector of fake diagnostics for a given
    ///        document and position.
    ///
    /// @param document
    /// @param position
    ///
    /// @return A vector of Diagnostic objects representing
    ///         the fake diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<Diagnostic> getDiagnostics(const std::string &document) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with a combination
    ///        of fake diagnostics.
    ///
    /// @param diagnostics The vector to be populated with
    ///        fake diagnostic data.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeDiagnostics();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake
    ///        hint diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeHints();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake
    ///        warning diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeWarnings();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake
    ///        error diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeErrors();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Fills the diagnostics vector with fake
    ///        informational diagnostics.
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeInfo();

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Diagnostics
    ///
    //////////////////////////////////////////////////////////////
    std::vector<Diagnostic> m_diagnostics;
};

} // namespace ls6502
