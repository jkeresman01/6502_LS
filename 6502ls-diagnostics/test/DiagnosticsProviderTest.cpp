#include "../../src/Diagnostics/DiagnosticsProvider.h"

#include <memory>

#include <gtest/gtest.h>

using namespace ls6502;

class DiagnosticsProviderTest : public ::testing::Test
{
  protected:
    std::unique_ptr<IDiagnosticsProvider> diagnosticsProvider = std::make_unique<DiagnosticsProvider>();
};

TEST_F(DiagnosticsProviderTest, WillDetectsMalformedLabel)
{
    // GIVEN
    std::string document = "InvalidLabel";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    ASSERT_EQ(diagnostics.size(), 1);
    EXPECT_EQ(diagnostics[0].severity, DiagnosticSeverity::WARNING);
    EXPECT_EQ(diagnostics[0].message, "Label missing ':' at end");
}

TEST_F(DiagnosticsProviderTest, WillDetectUnsupportedInstruction)
{
    // GIVEN
    std::string document = "XYZ 10";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    ASSERT_EQ(diagnostics.size(), 1);
    EXPECT_EQ(diagnostics[0].severity, DiagnosticSeverity::ERROR);
    EXPECT_EQ(diagnostics[0].message, "Unsupported instruction: XYZ");
}

TEST_F(DiagnosticsProviderTest, WillDetectGeneralSyntaxErrors)
{
    // GIVEN
    std::string document = "@invalid_syntax";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    ASSERT_EQ(diagnostics.size(), 1);
    EXPECT_EQ(diagnostics[0].severity, DiagnosticSeverity::ERROR);
    EXPECT_EQ(diagnostics[0].message, "General syntax error");
}

TEST_F(DiagnosticsProviderTest, WillProvideNoDiagnosticsForValidCode)
{
    // GIVEN
    std::string document = "LABEL: LDA #10";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    EXPECT_TRUE(diagnostics.empty());
}
