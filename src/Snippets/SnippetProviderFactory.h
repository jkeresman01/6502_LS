#pragma once

#include <memory>
#include <string>

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"
#include "FakeSnippetProvider.h"
#include "ISnippetProvider.h"
#include "PredefinedSnipetProvider.h"

namespace ls6502
{
class SnippetProviderFactory
{
  public:
    SnippetProviderFactory() = delete;

    static std::shared_ptr<ISnippetProvider> create()
    {
        const std::string &snippetsProvider =
            ConfigurationManager::getInstance()->getProperty("snippetsProvider");

        LS_6502_DEBUG(STR("Snippets provder: %s", snippetsProvider.c_str()));

        if (snippetsProvider == "predefined")
        {
            return std::make_shared<PredefinedSnippetProvider>();
        }

        return std::make_shared<FakeSnippetsProvider>();
    }
};
} // namespace ls6502
