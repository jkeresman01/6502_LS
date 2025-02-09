#pragma once

#include "../Types/CompletionItem.h"
#include "ICompletionProvider.h"

#include <vector>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class FakeCompletionProvider
///
/// @brief A mock implementation of the ICompletionProvider
///        interface, providing fake completion items for
///        testing and demonstration purposes.
///
//////////////////////////////////////////////////////////////
class FakeCompletionProvider : public ICompletionProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a list of fake completion items.
    ///
    /// @return A vector of CompletionItem objects representing
    ///         the fake completions.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<CompletionItem> getCompletions() override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Populates the provided vector with fake completion items.
    ///
    /// @param completions
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeComletions(std::vector<CompletionItem> &completions);
};

} // namespace justanlsp
