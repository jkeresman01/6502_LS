#pragma once

#include "../Types/CompletionItem.h"
#include <vector>

namespace justanlsp
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
    virtual std::vector<CompletionItem> getCompletions() = 0;
};

} // namespace justanlsp
