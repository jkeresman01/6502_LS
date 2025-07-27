#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <string>

#include "../Common/ClassRegistry.h"
#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"
#include "ISnippetProvider.h"
#include "SnippetProviderImpl/PredefinedSnipetProvider.h"
#include "SnippetProviderMockImpl/FakeSnippetProvider.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class SnippetProviderFactory
///
/// @brief Factory class for creating snippet providers.
///
//////////////////////////////////////////////////////////////
class SnippetProviderFactory
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    SnippetProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates a snippet provider based on configuration settings.
    ///
    /// @return A shared pointer to an instance of ISnippetProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ISnippetProvider> create()
    {
        const std::string& snippetsProvider = ConfigurationManager::getInstance()->getProperty(SNIPPET_PROVIDER);

        LS_6502_DEBUG(STR("Snippet provider: %s", snippetsProvider.c_str()));

        return ClassRegistry::getInstance()->forName(snippetsProvider)->createInstance();
    }

private:
    static const char* SNIPPET_PROVIDER = "snippetProvider";
};
} // namespace ls6502
