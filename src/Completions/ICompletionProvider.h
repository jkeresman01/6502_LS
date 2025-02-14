#pragma once

#include <vector>

#include "../Types/CompletionItem.h"
#include "../Types/Position.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ICompletionProvider
///
/// @brief Interface for providing completion items in response
///        to code completion requests.
///
//////////////////////////////////////////////////////////////
class ICompletionProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Pure virtual function to retrieve completion items.
    ///
    /// @return A vector of CompletionItem objects representing
    ///         the available completions.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<CompletionItem> getCompletions(const std::string &document,
                                                       const Position &position) = 0;
};

} // namespace ls6502
