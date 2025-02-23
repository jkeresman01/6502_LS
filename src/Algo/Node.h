#pragma once

#include <memory>
#include <unordered_map>

namespace ls6502
{
struct Node
{
    bool isLeaf;
    std::unordered_map<char, std::shared_ptr<Node>> children;
};
} // namespace ls6502
