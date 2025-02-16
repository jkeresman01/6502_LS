#include "../../src/Utils/DocumentUtil.h"
#include <gtest/gtest.h>

using namespace ls6502;

class DocumentUtilTest : public ::testing::Test
{
};

TEST_F(DocumentUtilTest, WillExtractPrefixAtWordStart)
{
    // GIVEN
    std::string document = "int main() {\n    return 0;\n}";
    Position position{0, 0}; // Cursor at 'i' in "int"

    // WHEN
    std::string result = DocumentUtil::extractPrefix(document, position);

    // THEN
    EXPECT_EQ(result, "int");
}

TEST_F(DocumentUtilTest, WillExtractPrefixInMiddleOfWord)
{
    // GIVEN
    std::string document = "std::vector<int> vec;";
    Position position{0, 6};

    // WHEN
    std::string result = DocumentUtil::extractPrefix(document, position);

    // THEN
    EXPECT_EQ(result, "vector");
}

TEST_F(DocumentUtilTest, WillExtractPrefixAtEndOfWord)
{
    // GIVEN
    std::string document = "return value;";
    Position position{0, 9};

    // WHEN
    std::string result = DocumentUtil::extractPrefix(document, position);

    // THEN
    EXPECT_EQ(result, "value");
}

TEST_F(DocumentUtilTest, WillReturnEmptyStringForNonAlphanumericCharacter)
{
    // GIVEN
    std::string document = "int main() {\n    return 0;\n}";
    Position position{0, 3};

    // WHEN
    std::string result = DocumentUtil::extractPrefix(document, position);

    // THEN
    EXPECT_EQ(result, "");
}

TEST_F(DocumentUtilTest, WillReturnEmptyStringForOutOfBoundsPosition)
{
    // GIVEN
    std::string document = "int main();";
    Position position{2, 0};

    // WHEN
    std::string result = DocumentUtil::extractPrefix(document, position);

    // THEN
    EXPECT_EQ(result, "");
}

TEST_F(DocumentUtilTest, WillHadnleEmptyDocument)
{
    // GIVEN
    std::string document = "";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    EXPECT_TRUE(result.empty());
}

TEST_F(DocumentUtilTest, WillHandleSingleLineDocument)
{
    // GIVEN
    std::string document = "Hello, world!";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "Hello, world!");
}

TEST_F(DocumentUtilTest, WillHandleMultiLineDocument)
{
    // GIVEN
    std::string document = "Line 1\nLine 2\nLine 3";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "Line 1");
    EXPECT_EQ(result[1], "Line 2");
    EXPECT_EQ(result[2], "Line 3");
}

TEST_F(DocumentUtilTest, WillHandleTrailingNewline)
{
    // GIVEN
    std::string document = "Line 1\nLine 2\n";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], "Line 1");
    EXPECT_EQ(result[1], "Line 2");
}

TEST_F(DocumentUtilTest, WillHandleConsecutiveNewlines)
{
    // GIVEN
    std::string document = "Line 1\n\nLine 3";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "Line 1");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "Line 3");
}

TEST_F(DocumentUtilTest, WillHandleCarriageReturnNewlines)
{
    // GIVEN
    std::string document = "Line 1\r\nLine 2\r\nLine 3";

    // WHEN
    auto result = DocumentUtil::splitDocumentIntoLines(document);

    // THEN
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "Line 1");
    EXPECT_EQ(result[1], "Line 2");
    EXPECT_EQ(result[2], "Line 3");
}
