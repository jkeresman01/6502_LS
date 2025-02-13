#include <gtest/gtest.h>

#include "../../src/Enums/AddressingModes.h"
#include "../../src/Utils/AddressingModesUtil.h"

using namespace ls6502;

class AddressingModeUtilTest : public ::testing::Test
{
};

TEST_F(AddressingModeUtilTest, GivenValidAddressingModeString_WhenConverted_ThenReturnsCorrectEnum)
{
    struct TestCase
    {
        std::string input;
        AddressingMode expectedOutput;
    };

    std::vector<TestCase> testCases = {
        {"Immediate", AddressingMode::IMMEDIATE},     {"Zero Page,X", AddressingMode::ZERO_PAGE_X},
        {"Zero Page,Y", AddressingMode::ZERO_PAGE_Y}, {"Absolute,X", AddressingMode::ABSOLUTE_X},
        {"Absolute,Y", AddressingMode::ABSOLUTE_Y},   {"Indirect", AddressingMode::INDIRECT_INDEXED},
        {"UnknownMode", AddressingMode::INVALID},     {"", AddressingMode::INVALID}};

    for (const auto &testCase : testCases)
    {
        EXPECT_EQ(AddressingModeUtil::stringToAddressingMode(testCase.input), testCase.expectedOutput)
            << "Failed for input: " << testCase.input;
    }
}

TEST_F(AddressingModeUtilTest, GivenValidAddressingModeEnum_WhenConverted_ThenReturnsCorrectString)
{
    struct TestCase
    {
        AddressingMode input;
        std::string expectedOutput;
    };

    std::vector<TestCase> testCases = {{AddressingMode::IMMEDIATE, "Immediate"},
                                       {AddressingMode::ZERO_PAGE_X, "Zero Page,X"},
                                       {AddressingMode::ZERO_PAGE_Y, "Zero Page,Y"},
                                       {AddressingMode::ABSOLUTE_X, "Absolute,X"},
                                       {AddressingMode::ABSOLUTE_Y, "Absolute,Y"},
                                       {AddressingMode::INDIRECT_INDEXED, "Indirect"},
                                       {AddressingMode::INVALID, ""}};

    for (const auto &testCase : testCases)
    {
        EXPECT_STREQ(AddressingModeUtil::addressingModeToString(testCase.input),
                     testCase.expectedOutput.c_str())
            << "Failed for input: " << static_cast<int>(testCase.input);
    }
}
