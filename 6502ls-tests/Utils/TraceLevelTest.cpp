#include <gtest/gtest.h>

#include "../../src/Enums/TraceValue.h"
#include "../../src/Utils/TraceUtil.h"

using namespace ls6502;

class TraceUtilTest : public ::testing::Test
{
};

TEST_F(TraceUtilTest, WillReturnMessagesTraceValue)
{
    // GIVEN
    std::string traceValueStr = "messages";

    // WHEN
    TraceValue result = TraceUtil::getTraceValue(traceValueStr);

    // THEN
    EXPECT_EQ(result, TraceValue::MESSAGES);
}

TEST_F(TraceUtilTest, WillReturnVerboseTraceValue)
{
    // GIVEN
    std::string traceValueStr = "verbose";

    // WHEN
    TraceValue result = TraceUtil::getTraceValue(traceValueStr);

    // THEN
    EXPECT_EQ(result, TraceValue::VERBOSE);
}

TEST_F(TraceUtilTest, WillReturnOffTraceValueForUnknownString)
{
    // GIVEN
    std::string traceValueStr = "unknown";

    // WHEN
    TraceValue result = TraceUtil::getTraceValue(traceValueStr);

    // THEN
    EXPECT_EQ(result, TraceValue::OFF);
}

TEST_F(TraceUtilTest, WillReturnOffTraceValueForEmptyString)
{
    // GIVEN
    std::string traceValueStr = "";

    // WHEN
    TraceValue result = TraceUtil::getTraceValue(traceValueStr);

    // THEN
    EXPECT_EQ(result, TraceValue::OFF);
}
