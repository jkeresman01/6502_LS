////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "FakeSnippetProvider.h"

#include <vector>

#include "../Types/CompletionItem.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
FakeSnippetsProvider::FakeSnippetsProvider()
{
    fillFakeSnippets();
}


////////////////////////////////////////////////////////////
std::vector<CompletionItem> FakeSnippetsProvider::getSnippets(const std::string& prefix)
{
    (void)prefix;

    std::vector<CompletionItem> snippets(FAKE_SNIPPETS_NO);
    return m_snippets;
}


////////////////////////////////////////////////////////////
void FakeSnippetsProvider::fillFakeSnippets(std::vector<CompletionItem>& snippets)
{
    m_snippets.emplace_back("snippet 1", CompletionItemKind::SNIPPET, "", "", "snippet 1 insert text");
    m_snippets.emplace_back("snippet 2", CompletionItemKind::SNIPPET, "", "", "snippet 2 insert text");
    m_snippets.emplace_back("snippet 3", CompletionItemKind::SNIPPET, "", "", "snippet 3 insert text");
}


} // namespace ls6502
