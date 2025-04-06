#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "../../Repo/Snippets/ISnippetRepository.h"
#include "../ISnippetProvider.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class PredefinedSnippetProvider
///
/// @brief Provides predefined code snippets for code completion.
///
//////////////////////////////////////////////////////////////
class SnippetsProvider : public ISnippetProvider
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a PredefinedSnippetProvider instance.
    ///
    //////////////////////////////////////////////////////////////
    SnippetsProvider();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of completion snippets that
    ///        match a given prefix.
    ///
    /// @param [in] prefix
    ///
    /// @return A vector of CompletionItem objects that match
    ///         the given prefix.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CompletionItem> getSnippets(const std::string& prefix) override;

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Filters snippets based on the given prefix
    ///        and converts them into completion items.
    ///
    /// @param [in] snippets
    /// @param [in] prefix
    ///
    /// @return A vector of CompletionItem objects.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CompletionItem> mapSnippetsToCompletions(const std::vector<std::string>& snippets, const std::string& prefix);
};
} // namespace ls6502
