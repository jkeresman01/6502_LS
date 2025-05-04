#include "../../src/Utils/StringUtil.h"

#include <gtest/gtest.h>

using namespace ls6502;

class StringUtilTest : public ::testing::Test
{
};

TEST_F(StringUtilTest, WillTrimLeadingAndTrailingWhitespace)
{
    // GIVEN
    std::string input = "   Hello, World!   ";

    // WHEN
    StringUtil::trim(input);

    // THEN
    EXPECT_EQ(input, "Hello, World!");
}

TEST_F(StringUtilTest, WillNotModifyStringWithoutWhitespace)
{
    // GIVEN
    std::string input = "HelloWorld";

    // WHEN
    StringUtil::trim(input);

    // THEN
    EXPECT_EQ(input, "HelloWorld");
}

TEST_F(StringUtilTest, WillConvertToUppercase)
{
    // GIVEN
    std::string input = "Hello World!";

    // WHEN
    StringUtil::toUpper(input);

    // THEN
    EXPECT_EQ(input, "HELLO WORLD!");
}

TEST_F(StringUtilTest, WillConvertToLowercase)
{
    // GIVEN
    std::string input = "Hello World!";

    // WHEN
    StringUtil::toLower(input);

    // THEN
    EXPECT_EQ(input, "hello world!");
}

TEST_F(StringUtilTest, WillHandleEmptyStringTrim)
{
    // GIVEN
    std::string input = "";

    // WHEN
    StringUtil::trim(input);

    // THEN
    EXPECT_EQ(input, "");
}

TEST_F(StringUtilTest, WillHandleEmptyStringUppercase)
{
    // GIVEN
    std::string input = "";

    // WHEN
    StringUtil::toUpper(input);

    // THEN
    EXPECT_EQ(input, "");
}

TEST_F(StringUtilTest, WillHandleEmptyStringLowercase)
{
    // GIVEN
    std::string input = "";

    // WHEN
    StringUtil::toLower(input);

    // THEN
    EXPECT_EQ(input, "");
}
