#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Node.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class Trie
///
/// @brief A Trie / prefix tree implementation
///
//////////////////////////////////////////////////////////////
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
    /// @param word
    ///
    //////////////////////////////////////////////////////////////
    void insert(const std::string &word);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves all words in the trie that start
    ///        with the given prefix
    ///
    /// @param prefix
    ///
    /// @return A vector containing all words that match the prefix
    ///
    //////////////////////////////////////////////////////////////
    std::vector<std::string> getCompletionWords(const std::string &prefix) const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the TrieNode corresponding to the
    ///        given prefix
    ///
    /// @param prefix
    ///
    /// @return A shared pointer to the TrieNode associated
    ///         with the prefix, or nullptr if no such node exists
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<Node> getTrieNode(const std::string &prefix) const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Finds all words in the subtree rooted at the given node
    ///
    /// @param node
    /// @param prefix
    /// @param results
    ///
    //////////////////////////////////////////////////////////////
    void findAllWords(std::shared_ptr<Node> node, const std::string &prefix,
                      std::vector<std::string> &results) const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The root node of the trie
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<Node> m_root = std::make_shared<Node>();
};
} // namespace ls6502
