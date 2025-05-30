////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Trie.h"
#include <memory>

namespace ls6502
{

////////////////////////////////////////////////////////////
void Trie::insert(const std::string& word)
{
    std::shared_ptr<Node> current = m_root;

    for (const char ch : word)
    {
        current->children.try_emplace(ch, std::make_shared<Node>());
        current = current->children[ch];
    }

    current->isLeaf = true;
}


////////////////////////////////////////////////////////////
std::vector<std::string> Trie::getCompletionWords(const std::string& prefix) const
{
    std::vector<std::string> completionOptions;
    std::shared_ptr<Node>    node = getNode(prefix);

    if (node)
    {
        findAllWords(node, prefix, completionOptions);
    }

    return completionOptions;
}


////////////////////////////////////////////////////////////
std::shared_ptr<Node> Trie::getNode(const std::string& prefix) const
{
    std::shared_ptr<Node> current = m_root;

    for (const char ch : prefix)
    {
        if (current->children.find(ch) == current->children.end())
        {
            return nullptr;
        }

        current = current->children[ch];
    }

    return current;
}


////////////////////////////////////////////////////////////
void Trie::findAllWords(std::shared_ptr<Node> node, const std::string& prefix, std::vector<std::string>& results) const
{
    if (node->isLeaf)
    {
        results.push_back(prefix);
    }

    for (const auto& pair : node->children)
    {
        findAllWords(pair.second, prefix + pair.first, results);
    }
}


} // namespace ls6502
