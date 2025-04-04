#include <gtest/gtest.h>

#include "../../src/Enums/AddressingModes.h"
#include "../../src/Utils/AddressingModessUtil.h"

using namespace ls6502;

class AddressingModesUtilTest : public ::testing::Test
{
};

TEST_F(AddressingModesUtilTest, WillReturnCorrectAddressingModeEnumValue)
{
    // GIVEN
    struct TestCase
    {
        std::string input;
        AddressingModes expectedOutput;
    };

    std::vector<TestCase> testCases = {
        {"Immediate", AddressingModes::IMMEDIATE},     {"Zero Page,X", AddressingModes::ZERO_PAGE_X},
        {"Zero Page,Y", AddressingModes::ZERO_PAGE_Y}, {"Absolute,X", AddressingModes::ABSOLUTE_X},
        {"Absolute,Y", AddressingModes::ABSOLUTE_Y},   {"Indirect", AddressingModes::INDIRECT_INDEXED},
        {"UnknownMode", AddressingModes::UNKOWN},     {"", AddressingModes::UNKOWN}};

    // WHEN
    // THEN
    for (const auto &testCase : testCases)
    {
        EXPECT_EQ(AddressingModeUtil::stringToAddressingMode(testCase.input), testCase.expectedOutput)
            << "Failed for input: " << testCase.input;
    }
}

TEST_F(AddressingModesUtilTest, WillReturnCorrectAddressingModeBasedOnEnumValue)
{
    // GIVEN
    struct TestCase
    {
        AddressingModes input;
        std::string expectedOutput;
    };

    std::vector<TestCase> testCases = {{AddressingModes::IMMEDIATE, "Immediate"},
                                       {AddressingModes::ZERO_PAGE_X, "Zero Page,X"},
                                       {AddressingModes::ZERO_PAGE_Y, "Zero Page,Y"},
                                       {AddressingModes::ABSOLUTE_X, "Absolute,X"},
                                       {AddressingModes::ABSOLUTE_Y, "Absolute,Y"},
                                       {AddressingModes::INDIRECT_INDEXED, "Indirect"},
                                       {AddressingModes::UNKOWN, ""}};

    // WHEN
    // THEN
    for (const auto &testCase : testCases)
    {
        EXPECT_STREQ(AddressingModesUtil::addressingModeToString(testCase.input),
                     testCase.expectedOutput.c_str())
            << "Failed for input: " << static_cast<int>(testCase.input);
    }
}
