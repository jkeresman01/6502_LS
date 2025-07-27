#include <cstdint>
#include <gtest/gtest.h>

#include "../../src/Utils/Convert.h"

using namespace ls6502;

class ConverterTest : public ::testing::Test
{
};

TEST_F(ConverterTest, WillConvertValidInteger)
{
    // GIVEN
    std::string input = "42";

    // WHEN
    uint16_t result = Converter::convert<uint16_t>(input);

    // THEN
    EXPECT_EQ(result, 42);
}

TEST_F(ConverterTest, WillConvertValidFloat)
{
    // GIVEN
    std::string input = "3.14";

    // WHEN
    float result = Converter::convert<float>(input);

    // THEN
    EXPECT_FLOAT_EQ(result, 3.14f);
}

TEST_F(ConverterTest, WillConvertValidDouble)
{
    // GIVEN
    std::string input = "2.718281828";

    // WHEN
    double result = Converter::convert<double>(input);

    // THEN
    EXPECT_DOUBLE_EQ(result, 2.718281828);
}

TEST_F(ConverterTest, WillConvertZero)
{
    // GIVEN
    std::string input = "0";

    // WHEN
    int32_t result = Converter::convert<int32_t>(input);

    // THEN
    EXPECT_EQ(result, 0);
}

TEST_F(ConverterTest, WillConvertWithWhitespace)
{
    // GIVEN
    std::string input = "   99  ";

    // WHEN
    uint64_t result = Converter::convert<uint64_t>(input);

    // THEN
    EXPECT_EQ(result, 99);
}
