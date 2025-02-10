#pragma once

#include <memory>

#include "FakeDiagnosticsProvider.h"
#include "IDiagnosticsProvider.h"

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class DiagnosticsProviderFactory
///
/// @brief Factory class for creating instances of diagnostics
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class DiagnosticsProviderFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    DiagnosticsProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a diagnostics provider.
    ///
    /// @return A shared pointer to an instance of a class
    ///         implementing IDiagnosticsProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<IDiagnosticsProvider> create()
    {
        std::string diagnosticsProvider =
            ConfigurationManager::getInstance()->getProperty("diagnosticsProvider");

        LS_6502_DEBUG(STR("Diagnostics provider: %s", diagnosticsProvider.c_str()));

        if (diagnosticsProvider == "fake")
        {
            return std::make_shared<FakeDiagnosticsProvider>();
        }

        // Default to FakeDiagnosticsProvider if no valid configuration is found.
        return std::make_shared<FakeDiagnosticsProvider>();
    }
};

} // namespace ls6502
