#pragma once

#include "../Types/CompletionItem.h"

#include <string>
#include <vector>

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class ISnippetProvider
///
/// @brief Interface for providing code snippets based on a given prefix.
///
//////////////////////////////////////////////////////////////
class ISnippetProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Virtual destructor to ensure proper cleanup of derived classes.
    ///
    //////////////////////////////////////////////////////////////
    virtual ~ISnippetProvider() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of code snippets that match a given prefix.
    ///
    /// @param prefix
    /// @return A vector of CompletionItem objects representing matching snippets.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<CompletionItem> getSnippets(const std::string &prefix) = 0;
};
} // namespace ls6502
