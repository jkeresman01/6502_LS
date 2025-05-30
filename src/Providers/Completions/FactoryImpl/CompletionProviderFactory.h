#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../CompletionProviderImpl/InstructionSetCompletionProvider.h"
#include "../CompletionProviderMockImpl/FakeCompletionProvider.h"
#include "../Config/ConfigurationManager.h"
#include "../ICompletionProvider.h"
#include "../Utils/Logger.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class CompletionProviderFactory
///
/// @brief Factory class for creating instances of completion
///        providers based on configuration settings.
///
//////////////////////////////////////////////////////////////
class CompletionProviderFactory
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    CompletionProviderFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an instance of a completion provider.
    ///
    /// @return A shared pointer to an instance of a class
    ///         implementing ICompletionProvider.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ICompletionProvider> create()
    {
        const std::string& completionProvider = ConfigurationManager::getInstance()->getProperty(
            COMPLETION_PROVIDER);

        LS_6502_DEBUG(STR("Completion provider: %s", completionProvider.c_str()));

        return ClassRegistry::getInstance()->forName(completionProvider)->createInstance();
    }

private:
    static const char* COMPLETION_PROVIDER = "completionProvider";
};

} // namespace ls6502
