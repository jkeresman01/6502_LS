#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "../HoverProviderImpl/InstructionSet6502HoverProvider.h"
#include "../HoverProviderMockImpl/FakeHoverProvider.h"
#include "../IHoverProvider.h"

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
        const std::string& hoverProvider = ConfigurationManager::getInstance()->getProperty(HOVER_PROVIDER);

        LS_6502_DEBUG(STR("Hover provider: %s", hoverProvider.c_str()));

        return ClassRegistry::getInstance()->forName(hoverProvider)->newInstance();
    }

private:
    static const char* HOVER_PROVIDER = "hoverProvider";
};

} // namespace ls6502
