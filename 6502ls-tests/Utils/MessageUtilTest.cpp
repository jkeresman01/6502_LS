#include <gtest/gtest.h>

#include <nlohmann/json.hpp>

#include "../../src/Enums/RequestType.h"
#include "../../src/Utils/MessageUtil.h"

using namespace ls6502;

class MessageUtilTest : public ::testing::Test
{
};

TEST_F(MessageUtilTest, WillReturnCorrectTypeForKnownMethod)
{
    // GIVEN
    nlohmann::json request = {{"method", "initialize"}};

    // WHEN
    RequestType result = MessageUtil::getType(request);

    // THEN
    EXPECT_EQ(result, RequestType::INITIALIZE);
}

TEST_F(MessageUtilTest, WillReturnUnknownTypeForMissingMethod)
{
    // GIVEN
    nlohmann::json request = {{"param", "value"}};

    // WHEN
    RequestType result = MessageUtil::getType(request);

    // THEN
    EXPECT_EQ(result, RequestType::UNKNOWN);
}

TEST_F(MessageUtilTest, WillReturnUnknownTypeForInvalidMethod)
{
    // GIVEN
    nlohmann::json request = {{"method", "invalidMethod"}};

    // WHEN
    RequestType result = MessageUtil::getType(request);

    // THEN
    EXPECT_EQ(result, RequestType::UNKNOWN);
}

TEST_F(MessageUtilTest, WillParseValidJsonString)
{
    // GIVEN
    std::string validJson = R"({"method": "initialize"})";

    // WHEN
    nlohmann::json result = MessageUtil::tryParse(validJson);

    // THEN
    EXPECT_TRUE(result.is_object());
    EXPECT_EQ(result["method"], "initialize");
}

TEST_F(MessageUtilTest, WillReturnEmptyJsonForInvalidJsonString)
{
    // GIVEN
    std::string invalidJson = R"({"method": "initialize)"; // Missing closing quote

    // WHEN
    nlohmann::json result = MessageUtil::tryParse(invalidJson);

    // THEN
    EXPECT_TRUE(result.is_null());
}

TEST_F(MessageUtilTest, WillHandleEmptyStringGracefully)
{
    // GIVEN
    std::string emptyJson = "";

    // WHEN
    nlohmann::json result = MessageUtil::tryParse(emptyJson);

    // THEN
    EXPECT_TRUE(result.is_null());
}

TEST_F(MessageUtilTest, WillReturnEmptyJsonForNonJsonText)
{
    // GIVEN
    std::string nonJson = "This is not JSON";

    // WHEN
    nlohmann::json result = MessageUtil::tryParse(nonJson);

    // THEN
    EXPECT_TRUE(result.is_null());
}
