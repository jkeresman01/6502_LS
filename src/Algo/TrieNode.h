#pragma once

#include <memory>
#include <unordered_map>

namespace ls6502
{
struct TrieNode
{
    bool isLeaf;
    std::unordered_map<char, std::shared_ptr<TrieNode>> children;
};
} // namespace ls6052
