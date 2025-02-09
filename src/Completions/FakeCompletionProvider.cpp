#include "FakeCompletionProvider.h"

#include "../Types/CompletionItem.h"

#include <vector>

namespace justanlsp
{
std::vector<CompletionItem> FakeCompletionProvider::getCompletions()
{
    std::vector<CompletionItem> completions;
    fillFakeComletions(completions);
    return completions;
}

void FakeCompletionProvider::fillFakeComletions(std::vector<CompletionItem> &completions)
{
    completions.emplace_back("dnsClient", CompletionItemKind::TEXT, "DNS client test 1 documentation",
                             "dnsClient", "dnsClient");
    completions.emplace_back("dnsClientId", CompletionItemKind::TEXT, "DNS client test 1",
                             "DNS client id test 1 documentation", "dnsClientId");
    completions.emplace_back("dnsClientIpAddress", CompletionItemKind::TEXT,
                             "DNS client ip address test 1 documentation", "dnsClientIpAddress",
                             "dnsClientIpAddress");
}
} // namespace justanlsp
