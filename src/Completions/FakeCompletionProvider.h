#pragma once

#include "../Types/CompletionItem.h"
#include "ICompletionProvider.h"

#include <vector>

namespace ls6502
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
    std::vector<CompletionItem> getCompletions(const std::string &document,
                                               const Position &position) override;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Populates the provided vector with fake completion items.
    ///
    /// @param [in] completions
    ///
    //////////////////////////////////////////////////////////////
    void fillFakeComletions(std::vector<CompletionItem> &completions);
};

} // namespace ls6502
