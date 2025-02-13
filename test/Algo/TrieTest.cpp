#include "../../src/Algo/Trie.h"

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace ls6502;

class TrieTest : public ::testing::Test
{
  protected:
    Trie trie;

    void insertWords(const std::vector<std::string> &words)
    {
        for (const auto &word : words)
        {
            trie.insert(word);
        }
    }
};

TEST_F(TrieTest, WillProvideCorrectCompletions)
{
    // GIVEN
    insertWords({"dnsClient", "dnsClientID", "dnsClientIpAddress", "DHCPServer", "TLS", "trie",
                 "AbstractSyntaxTree"});

    // WHEN
    std::vector<std::string> completions = trie.getCompletionWords("dns");
    std::sort(completions.begin(), completions.end());

    // THEN
    std::vector<std::string> expected = {"dnsClient", "dnsClientID", "dnsClientIpAddress"};
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(completions, expected);
}

TEST_F(TrieTest, WillProvideNoCompletions)
{
    // GIVEN
    insertWords({"dnsClient", "dnsClientID", "dnsClientIpAddress", "DHCPServer", "TLS", "trie",
                 "AbstractSyntaxTree"});

    // WHEN
    auto completions = trie.getCompletionWords("TCP");

    // THEN
    EXPECT_TRUE(completions.empty());
}

TEST_F(TrieTest, WillProvideCorrectCompletionsEdgeCaseEmptyPreffix)
{
    // GIVEN
    insertWords({"dnsClient", "dnsClientID", "dnsClientIpAddress", "DHCPServer"});

    // WHEN
    auto completions = trie.getCompletionWords("");
    std::sort(completions.begin(), completions.end());

    // THEN
    std::vector<std::string> expected = {"dnsClient", "dnsClientID", "dnsClientIpAddress", "DHCPServer"};
    std::sort(expected.begin(), expected.end());

    EXPECT_EQ(completions, expected);
}
