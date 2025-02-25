#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "ISnippetProvider.h"
#include "ISnippetRepository.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::multimap<std::string, std::string> SnippetsT;

//////////////////////////////////////////////////////////////
///
/// @class PredefinedSnippetProvider
///
/// @brief Provides predefined code snippets for code completion.
///
//////////////////////////////////////////////////////////////
class PredefinedSnippetProvider : public ISnippetProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a PredefinedSnippetProvider instance.
    ///
    //////////////////////////////////////////////////////////////
    PredefinedSnippetProvider();

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
    std::vector<CompletionItem> getSnippets(const std::string &prefix) override;

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
    std::vector<CompletionItem> getCompletions(const std::vector<std::string> &snippets,
                                               const std::string &prefix);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Stores all predefined snippets as a multimap.
    ///
    //////////////////////////////////////////////////////////////
    SnippetsT m_snippets;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unique pointer to an instance of ISnippetRepository
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ISnippetRepository> m_snippetRepository;
};
} // namespace ls6502
