////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../../Manager/Snippets/SnippetsManager.h"
#include "../../Utils/Logger.h"
#include "PredefinedSnipetProvider.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
std::vector<CompletionItem> PredefinedSnippetProvider::getSnippets(const std::string& prefix)
{
    if (auto it = SnippetsManager::getInstance().getSnippetsByMnemonic(prefix))
    {
        return mapSnippetsToCompletions(*it, prefix);
    }
    else
    {
        LS_6502_WARN(STR("No snippets for this prefix: %s", prefix.c_str()));
    }
}


////////////////////////////////////////////////////////////
std::vector<CompletionItem> PredefinedSnippetProvider::mapSnippetsToCompletions(
    const std::vector<std::string>& snippets,
    const std::string&              prefix)
{
    std::vector<CompletionItem> completionItems(snippets.size());

    for (size_t i = 0; i < completionItems.size(); ++i)
    {
        completionItems.emplace_back(prefix, CompletionItemKind::SNIPPET, "", "", snippets[i]);
    }

    return completionItems;
}


} // namespace ls6502
