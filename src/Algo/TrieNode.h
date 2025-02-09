#pragma once

#include <memory>
#include <unordered_map>

namespace justanlsp
{
struct TrieNode
{
    bool isLeaf;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
};
} // namespace justanlsp
