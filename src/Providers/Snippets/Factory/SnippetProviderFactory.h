#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <string>

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
        const std::string& snippetsProvider = ConfigurationManager::getInstance()->getProperty(
            "snippetsProvider");

        LS_6502_DEBUG(STR("Snippets provider: %s", snippetsProvider.c_str()));

        if (snippetsProvider == "predefined")
        {
            return std::make_shared<PredefinedSnippetProvider>();
        }

        return std::make_shared<FakeSnippetsProvider>();
    }
};
} // namespace ls6502
