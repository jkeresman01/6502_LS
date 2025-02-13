#include <gtest/gtest.h>

#include "../../src/Enums/DiagnosticSeverity.h"
#include "../../src/Messages/Notification/PublishDiagnosticsNotification.h"
#include "../../src/Params/PublishDiagnosticsParams.h"

#include <memory>
#include <nlohmann/json.hpp>
#include <sstream>

namespace ls6502
{

class PublishDiagnosticsNoticifationTest : public ::testing::Test
{
  protected:
    std::string mockJsonRPC = "2.0";
    std::string mockMethod = "textDocument/publishDiagnostics";
    std::string mockURI = "file://test.cpp";

    std::vector<Diagnostic> mockDiagnostics{
        {{10, 10}, DiagnosticSeverity::ERROR, "Source1", "Test error message 1"},
        {{5, 5}, DiagnosticSeverity::WARNING, "Source2", "Test warning message"}};

    std::shared_ptr<PublishDiagnosticsParams> mockDiagnosticsParams =
        std::make_shared<PublishDiagnosticsParams>(mockURI, mockDiagnostics);
};

TEST_F(PublishDiagnosticsNoticifationTest, WillConvertToJsonCorrectly)
{
    // GIVEN
    PublishDiagnosticsNoticifation publishDiagnostics(mockMethod, mockDiagnosticsParams);

    // WHEN
    nlohmann::json resultJson = publishDiagnostics.toJson();

    // THEN
    EXPECT_EQ(resultJson["jsonrpc"], mockJsonRPC);
    EXPECT_EQ(resultJson["method"], mockMethod);
    EXPECT_EQ(resultJson["params"], mockDiagnosticsParams->toJson());
}

TEST_F(PublishDiagnosticsNoticifationTest, WillOutputStreamCorrectly)
{
    // GIVEN
    PublishDiagnosticsNoticifation publishDiagnostics(mockMethod, mockDiagnosticsParams);

    // WHEN
    std::ostringstream oss;
    oss << publishDiagnostics;

    std::string output = oss.str();

    // THEN
    nlohmann::json expectedJson = publishDiagnostics.toJson();
    std::string expectedOutput = "Content-Length: " + std::to_string(expectedJson.dump().size()) +
                                 "\r\n\r\n" + expectedJson.dump() + "\n";

    EXPECT_EQ(output, expectedOutput);
}

} // namespace ls6502
