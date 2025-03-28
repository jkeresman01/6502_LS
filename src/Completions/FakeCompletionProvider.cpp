////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "FakeCompletionProvider.h"

#include "../Types/CompletionItem.h"

#include <vector>

namespace ls6502
{

////////////////////////////////////////////////////////////
std::vector<CompletionItem> FakeCompletionProvider::getCompletions(const std::string &document,
                                                                   const Position &position)
{
    (void)document;
    (void)position;

    std::vector<CompletionItem> completions(FAKE_COMPLETION_ITEMS_NO);
    fillFakeComletions(completions);
    return completions;
}

////////////////////////////////////////////////////////////
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
} // namespace ls6502
