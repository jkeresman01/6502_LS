#include "../../src/Utils/XMLUtil.h" test
#include <gtest/gtest.h>

using namespace ls6502;

class XMLUtilTest : public ::testing::Test
{
};

TEST_F(XMLUtilTest, WillParseValidPropertyLine)
{
    // GIVEN
    std::string line = "<property name=\"username\">MilicaKrmpotic</property>";

    // WHEN
    auto result = XMLUtil::parseFromFileLine(line);

    // THEN
    EXPECT_EQ(result.first, "username");
    EXPECT_EQ(result.second, "MilicaKrmpotic");
}

TEST_F(XMLUtilTest, WillReturnEmptyPairForInvalidPropertyLine)
{
    // GIVEN
    std::string line = "<property name=>Milica Krmpotic</property>";

    // WHEN
    auto result = XMLUtil::parseFromFileLine(line);

    // THEN
    EXPECT_TRUE(result.first.empty());
    EXPECT_TRUE(result.second.empty());
}

TEST_F(XMLUtilTest, WillValidateCorrectXMLLine)
{
    // GIVEN
    std::string_view line = "<property name=\"username\">Milica Krmpotic</property>";

    // WHEN
    bool result = XMLUtil::isValidXMLLine(line);

    // THEN
    EXPECT_TRUE(result);
}

TEST_F(XMLUtilTest, WillInvalidateIncorrectXMLLine)
{
    // GIVEN
    std::string_view line = "<property name=\"username\">Milica Krmpotic";

    // WHEN
    bool result = XMLUtil::isValidXMLLine(line);

    // THEN
    EXPECT_FALSE(result);
}
