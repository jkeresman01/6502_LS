#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <sstream>

#include "../../src/Errors/ErrorCodes.h"
#include "../../src/Messages/Response/ResponseError.h"
#include "../../src/Messages/Response/ResponseMessage.h"

using json = nlohmann::json;

namespace ls6502
{
class ResponseMessageTest : public ::testing::Test
{
  protected:
    int64_t mockId = 1;
    std::string mockJsonRPC = "2.0";

    ResponseError mockError{ErrorCodes::INVALID_REQUEST, "message"};

    ResponseMessage mockResponse{mockJsonRPC, mockId};

    ResponseMessage mockErrorResponse{mockJsonRPC, mockId, mockError};
};

TEST_F(ResponseMessageTest, WillConvertToJsonCorrectlyWithoutError)
{
    // WHEN
    json resultJson = mockResponse.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["id"], mockId);

    EXPECT_FALSE(resultJson.contains("error"));
}

TEST_F(ResponseMessageTest, WillConvertToJsonCorrectlyWithError)
{
    // WHEN
    json resultJson = mockErrorResponse.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["id"], mockId);

    EXPECT_TRUE(resultJson.contains("error"));
    EXPECT_EQ(resultJson["error"]["code"], mockError.getErrorCode());
    EXPECT_EQ(resultJson["error"]["message"], mockError.getErrorMessage());
}

TEST_F(ResponseMessageTest, WillOutputStreamCorrectlyWithoutError)
{
    // WHEN
    std::ostringstream oss;
    oss << mockResponse;

    std::string output = oss.str();

    // THEN
    json expectedJson = mockResponse.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST_F(ResponseMessageTest, WillOutputStreamCorrectlyWithError)
{
    // WHEN
    std::ostringstream oss;
    oss << mockErrorResponse;

    std::string output = oss.str();

    // THEN
    json expectedJson = mockErrorResponse.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}

} // namespace ls6502
