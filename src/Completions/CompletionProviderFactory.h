#pragma once

#include <memory>

#include "FakeCompletionProvider.h"
#include "ICompletionProvider.h"
#include "InstructionSetCompletionProvider.h"

#include "../Config/ConfigurationManager.h"
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
        std::string completionProvider = ConfigurationManager::getInstance()->getProperty("completion");

        LS_6502_DEBUG(STR("Completion provider: %s", completionProvider.c_str()));

        if (completionProvider == "fake")
        {
            return std::make_shared<FakeCompletionProvider>();
        }

        // TODO implement rest of the completion providers

        return std::make_shared<InstructionSetCompletionProvider>();
    }
};

} // namespace ls6502
