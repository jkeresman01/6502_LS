#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../CodeActionProviderImpl/CodeActionProvider.h"
#include "../CodeActionProviderMockImpl/FakeCodectionsProvider.h"
#include "../Config/ConfigurationManager.h"
#include "../ICodeActionsProvider.h"
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
        const std::string& codeActionProvider = ConfigurationManager::getInstance()->getProperty(
            CODE_ACTION_PROVIDER);

        LS_6502_DEBUG(STR("Code action provider: %s", codeActionProvider.c_str()));

        return ClassRegistry::getInstance()->forName(codeActionProvider)->createInstance();
    }

private:
    static const char* CODE_ACTION_PROVIDER = "codeActionProvider";
};

} // namespace ls6502
