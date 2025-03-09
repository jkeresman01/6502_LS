#pragma once

#include <memory>

#include "CodeActionProvider.h"
#include "FakeCodectionsProvider.h"
#include "ICodeActionsProvider.h"

#include "../Config/ConfigurationManager.h"
#include "../Utils/Logger.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class CodeActionsProviderFactory
///
/// @brief Factory class to create instances of code actions
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class CodeActionsProviderFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    CodeActionsProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a code actions provider.
    ///
    /// @return A shared pointer to an instance of
    ///         a class implementing ICodeActionsProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ICodeActionsProvider> create()
    {
        const std::string &codeActionProvider =
            ConfigurationManager::getInstance()->getProperty("codeActionProvider");

        LS_6502_DEBUG(STR("Code action provider: %s", codeActionProvider.c_str()));

        if (codeActionProvider == "6502asm")
        {
            return std::make_shared<CodeActionProvider>();
        }

        return std::make_shared<FakeCodeActionsProvider>();
    }
};

} // namespace ls6502
