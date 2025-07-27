#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <sstream>

#include "../../src/Messages/Response/ShutdownResponse.h"

using json = nlohmann::json;

namespace ls6502
{
class ShutdownResponseTest : public ::testing::Test
{
  protected:
    int64_t mockId = 1;
    std::string mockJsonRPC = "2.0";

    ShutdownResponse shutdownResponse{mockJsonRPC, mockId};
};

TEST_F(ShutdownResponseTest, WillConvertToJsonCorrectly)
{
    // WHEN
    json resultJson = shutdownResponse.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["id"], mockId);
    EXPECT_EQ(resultJson["result"], nullptr);
}

TEST_F(ShutdownResponseTest, WillOutputStreamCorrectly)
{
    // WHEN
    std::ostringstream oss;
    oss << shutdownResponse;

    std::string output = oss.str();

    // THEN
    json expectedJson = shutdownResponse.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}

} // namespace ls6502
