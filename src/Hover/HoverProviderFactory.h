#pragma once

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "FakeHoverProvider.h"
#include "IHoverProvider.h"
#include "InstructionSet6502HoverProvider.h"

namespace ls6502
{
/////////////////////////////////////////////////////////////////////
///
/// @class HoverProviderFactory
///
/// @brief A factory class responsible for creating hover provider
///        instances based on configuration settings.
///
/////////////////////////////////////////////////////////////////////
class HoverProviderFactory
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor
    ///
    /////////////////////////////////////////////////////////////////////
    HoverProviderFactory() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates a hover provider based on the configuration
    ///
    /// @return A shared pointer to an IHoverProvider instance.
    ///
    /////////////////////////////////////////////////////////////////////
    static std::shared_ptr<IHoverProvider> create()
    {
        std::string hoverProvider = ConfigurationManager::getInstance()->getProperty("hoverProvider");

        if (hoverProvider == "fake")
        {
            return std::make_shared<FakeHoverProvider>();
        }

        if (hoverProvider == "6502ISA")
        {
            return std::make_shared<InstructionSet6502HoverProvider>();
        }

        //TODO default to FakeHoverProvider
        return std::make_shared<InstructionSet6502HoverProvider>();
    }
};

} // namespace ls6502
