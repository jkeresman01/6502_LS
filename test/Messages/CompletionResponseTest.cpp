#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <vector>

#include "../../src/Messages/Response/CompletionResponse.h"
#include "../../src/Results/CompletionResult.h"

using json = nlohmann::json;

namespace ls6502
{
class CompletionResponseTest : public ::testing::Test
{
  protected:
    int64_t mockId = 1;
    std::string mockJsonRPC = "2.0";

    std::vector<CompletionItem> completionItems{
        CompletionItem("dnsClient", "DNS client test 1", "DNS client test 1 documentation"),
        CompletionItem("dnsClientId", "DNS client test 1", "DNS client id test 1 documentation"),
        CompletionItem("dnsClientIpAddress", "DNS client ip address test 1",
                       "DNS client ip address test 1 documentation"),
    };

    CompletionResult mockCompletionResult{completionItems};
};

TEST_F(CompletionResponseTest, WillConvertToJsonCorrectly)
{
    // GIVEN
    CompletionResponse response(mockJsonRPC, mockId, mockCompletionResult);

    // WHEN
    json resultJson = response.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["id"], mockId);
    EXPECT_EQ(resultJson["result"], mockCompletionResult.toJson());
}

TEST_F(CompletionResponseTest, WillOutputStreamCorrectly)
{
    // GIVEN
    CompletionResponse response(mockJsonRPC, mockId, mockCompletionResult);

    // WHEN
    std::ostringstream oss;
    oss << response;

    std::string output = oss.str();

    // THEN
    json expectedJson = response.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}
} // namespace ls6502
