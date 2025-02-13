#include "PredefinedSnipetProvider.h"

#include "SnippetRepositoryFactory.h"

namespace ls6502
{
PredefinedSnippetProvider::PredefinedSnippetProvider()
    : m_snippetRepository(SnippetRepositoryFactory::create())
{
    m_snippets = m_snippetRepository->load();
}

std::vector<CompletionItem> PredefinedSnippetProvider::getSnippets(const std::string &prefix)
{
    std::vector<std::string> snippets;
    auto range = m_snippets.equal_range(prefix);

    for (auto it = range.first; it != range.second; ++it)
    {
        snippets.push_back(it->second);
    }

    return getCompletions(snippets, prefix);
}

std::vector<CompletionItem> PredefinedSnippetProvider::getCompletions(
    const std::vector<std::string> &snippets, const std::string &prefix)
{
    std::vector<CompletionItem> completionItems(snippets.size());

    for (size_t i = 0; i < completionItems.size(); ++i)
    {
        completionItems.emplace_back(prefix, CompletionItemKind::SNIPPET, "", "", snippets[i]);
    }

    return completionItems;
}
} // namespace ls6502
