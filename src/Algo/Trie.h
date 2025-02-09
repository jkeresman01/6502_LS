#pragma once

#include <memory>
#include <string>
#include <vector>

#include "TrieNode.h"

namespace justanlsp
{
class Trie
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor
    ///
    //////////////////////////////////////////////////////////////
    Trie() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Inserts a word into the trie
    ///
    /// @param word The word to insert
    ///
    //////////////////////////////////////////////////////////////
    void insert(const std::string &word);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves all words in the trie that start with the given prefix
    ///
    /// @param prefix The prefix to search for
    /// @return A vector containing all words that match the prefix
    ///
    //////////////////////////////////////////////////////////////
    std::vector<std::string> getCompletionWords(const std::string &prefix) const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the TrieNode corresponding to the given prefix
    ///
    /// @param prefix The prefix to search for
    /// @return A shared pointer to the TrieNode associated with the prefix,
    ///         or nullptr if no such node exists
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TrieNode> getTrieNode(const std::string &prefix) const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Finds all words in the subtree rooted at the given node
    ///
    /// @param node The root of the subtree
    /// @param prefix The current prefix leading to this node
    /// @param results A vector to store the found words
    ///
    //////////////////////////////////////////////////////////////
    void findAllWords(std::shared_ptr<TrieNode> node, const std::string &prefix,
                      std::vector<std::string> &results) const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The root node of the trie
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TrieNode> m_root = std::make_shared<TrieNode>();
};
} // namespace justanlsp
