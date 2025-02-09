#include "CompletionResult.h"

#include <iostream>
#include <string>
#include <vector>

namespace justanlsp
{

CompletionResult::CompletionResult(const std::vector<CompletionItem> &completionItems)
    : m_completionItems(completionItems)
{
}

nlohmann::json CompletionResult::toJson() const
{
    std::vector<nlohmann::json> completions(m_completionItems.size());

    for (size_t i = 0; i < completions.size(); ++i)
    {
        completions[i] = m_completionItems[i].toJson();
    }

    return completions;
}

} // namespace justanlsp
