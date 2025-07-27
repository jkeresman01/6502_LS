#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../Config/ConfigurationManager.h"
#include "../DefinitionProviderImpl/DefinitionProvider.h"
#include "../DefinitionProviderMockImpl/FakeDefinitionProvider.h"
#include "../IDefinitionProvider.h"
#include "../Utils/Logger.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class DefinitionProviderFactory
///
/// @brief Factory class for creating instances of definition
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class DefinitionProviderFactory
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    DefinitionProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a completion provider.
    ///
    /// @return A shared pointer to an instance of a class
    ///         implementing IDefinitionProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<IDefinitionProvider> create()
    {
        const std::string& definitionProvider = ConfigurationManager::getInstance()->getProperty(
            DEFINITION_PROVIDER);

        LS_6502_DEBUG(STR("Definition provider: %s", definitionProvider.c_str()));

        return ClassRegistry::getInstance()->forName(definitionProvider)->createInstance();
    }

private:
    static const char* DEFINITION_PROVIDER = "definition";
};

} // namespace ls6502
