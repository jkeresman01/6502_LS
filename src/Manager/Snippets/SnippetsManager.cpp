////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "SnippetsManager.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
SnippetsMapT SnippetsManager::getAllSnippets()
{
    loadSnippets();

    return m_snippets;
}

////////////////////////////////////////////////////////////
std::optional<std::vector<std::string>> SnippetsManager::getSnippetsByMnemonic(const std::string& mnemonic)
{
    loadSnippets();

    std::vector<std::string> snippets;
    const auto&              range = m_snippets.equal_range(mnemonic);

    for (auto it = range.first; it != range.second; ++it)
    {
        snippets.emplace_back(it->second);
    }

    return snippets.empty() ? std::nullopt : std::make_optional<std::vector<std::string>>(snippets);
}

////////////////////////////////////////////////////////////
void SnippetsManager::loadSnippets()
{
    if (m_snippets.empty())
    {
        m_snippets = m_snippetsRepository->load();
    }
}

////////////////////////////////////////////////////////////
SnippetsManager& SnippetsManager::getInstance()
{
    static SnippetsManager instance;
    return instance;
}

} // namespace ls6502
