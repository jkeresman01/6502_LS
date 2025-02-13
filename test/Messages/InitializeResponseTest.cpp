#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
#include <sstream>

#include "../../src/Messages/Response/InitializeResponse.h"
#include "../../src/Results/InitializeResult.h"

using json = nlohmann::json;

namespace ls6502
{
class InitializeResponseTest : public ::testing::Test
{
  protected:
    int64_t mockId = 1;
    std::string mockJsonRPC = "2.0";

    InitializeResult initializeResult{{"6502ls", "0.0.0.0.0.1-alpha"},
                                      ServerCapabilities(TextDocumentSyncKind::FULL)};

    InitializeResponse initializeResponse{mockJsonRPC, mockId, initializeResult};
};

TEST_F(InitializeResponseTest, WillConvertToJsonCorrectly)
{
    // WHEN
    json resultJson = initializeResponse.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["id"], mockId);
    EXPECT_EQ(resultJson["result"]["serverInfo"]["name"], "6502ls");
    EXPECT_EQ(resultJson["result"]["serverInfo"]["version"], "0.0.0.0.0.1-alpha");
    EXPECT_EQ(resultJson["result"]["capabilities"], initializeResult.getServerCapabilities().toJson());
}

TEST_F(InitializeResponseTest, WillOutputStreamCorrectly)
{
    // WHEN
    std::ostringstream oss;
    oss << initializeResponse;

    std::string output = oss.str();

    // THEN
    json expectedJson = initializeResponse.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST_F(InitializeResponseTest, WillReturnCorrectStringRepresentation)
{
    // WHEN
    std::string responseString = initializeResponse.toString();

    // THEN
    std::string expectedString =
        "Initialization response from server { " + initializeResult.toString() + " }";
    EXPECT_EQ(responseString, expectedString);
}

} // namespace ls6502
