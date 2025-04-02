#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>
#include <unordered_map>

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class ISnippetRepository
///
/// @brief Interface for a snippet repository that loads code snippets.
///
//////////////////////////////////////////////////////////////
class ISnippetRepository
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Virtual destructor to ensure proper cleanup
    ///        of derived classes.
    ///
    //////////////////////////////////////////////////////////////
    virtual ~ISnippetRepository() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads snippets from a source and returns them as a multimap.
    ///
    /// @return A multimap where the key is the snippet identifier, and
    ///         the value is the corresponding snippet code.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::unordered_multimap<std::string, std::string> load() = 0;
};
} // namespace ls6502
