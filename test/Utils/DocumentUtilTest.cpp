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
