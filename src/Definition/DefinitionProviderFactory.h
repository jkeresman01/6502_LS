#pragma once

#include <memory>

#include "FakeDefinitionProvider.h"
#include "IDefinitionProvider.h"

#include "../Config/ConfigurationManager.h"
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
        const std::string &definitionProvider =
            ConfigurationManager::getInstance()->getProperty("definition");

        LS_6502_DEBUG(STR("Definition provider: %s", definitionProvider.c_str()));

        if (definitionProvider == "fake")
        {
            return std::make_shared<FakeDefinitionProvider>();
        }

        // TODO replace
        return std::make_shared<FakeDefinitionProvider>();
    }
};

} // namespace ls6502
