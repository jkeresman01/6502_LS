#include "FakeSnippetProvider.h"

#include "../Types/CompletionItem.h"

#include <vector>

namespace ls6502
{

FakeSnippetsProvider::FakeSnippetsProvider()
{
    fillFakeSnippets();
}

std::vector<CompletionItem> FakeSnippetsProvider::getSnippets(const std::string &prefix)
{
    (void)prefix;

    return m_snippets;
}

void FakeSnippetsProvider::fillFakeSnippets()
{
    m_snippets.emplace_back("snippet 1", CompletionItemKind::SNIPPET, "", "", "snippet 1 insert text");
    m_snippets.emplace_back("snippet 2", CompletionItemKind::SNIPPET, "", "", "snippet 2 insert text");
    m_snippets.emplace_back("snippet 3", CompletionItemKind::SNIPPET, "", "", "snippet 3 insert text");
}
} // namespace ls6502
