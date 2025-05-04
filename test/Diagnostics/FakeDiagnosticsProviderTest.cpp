#include "../../src/Diagnostics/FakeDiagnosticsProvider.h"

#include <memory>

#include <gtest/gtest.h>

using namespace ls6502;

class FakeDiagnosticsProviderTest : public ::testing::Test
{
  protected:
    std::unique_ptr<IDiagnosticsProvider> diagnosticsProvider = std::make_unique<FakeDiagnosticsProvider>();
};

TEST_F(FakeDiagnosticsProviderTest, WillReturnCorrectNumberOfDiagnostics)
{
    // GIVEN
    std::string document = "milica krmpotic";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    ASSERT_EQ(diagnostics.size(), 12);
}

TEST_F(FakeDiagnosticsProviderTest, WillContainCorrectErrorDiagnostics)
{
    // GIVEN
    std::string document = "milica krmpotic";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    EXPECT_EQ(diagnostics[0].severity, DiagnosticSeverity::ERROR);
    EXPECT_EQ(diagnostics[0].message, "First ERROR message");
    EXPECT_EQ(diagnostics[1].severity, DiagnosticSeverity::ERROR);
    EXPECT_EQ(diagnostics[1].message, "Second ERROR message");
    EXPECT_EQ(diagnostics[2].severity, DiagnosticSeverity::ERROR);
    EXPECT_EQ(diagnostics[2].message, "Third ERROR message");
}

TEST_F(FakeDiagnosticsProviderTest, WillContainCorrectWarningDiagnostics)
{
    // GIVEN
    std::string document = "milica krmpotic";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    EXPECT_EQ(diagnostics[3].severity, DiagnosticSeverity::WARNING);
    EXPECT_EQ(diagnostics[3].message, "First WARNING message");
    EXPECT_EQ(diagnostics[4].severity, DiagnosticSeverity::WARNING);
    EXPECT_EQ(diagnostics[4].message, "Second WARNING message");
    EXPECT_EQ(diagnostics[5].severity, DiagnosticSeverity::WARNING);
    EXPECT_EQ(diagnostics[5].message, "Third WARNING message");
}

TEST_F(FakeDiagnosticsProviderTest, WillContainCorrectHintDiagnostics)
{
    // GIVEN
    std::string document = "milica krmpotic";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    EXPECT_EQ(diagnostics[6].severity, DiagnosticSeverity::HINT);
    EXPECT_EQ(diagnostics[6].message, "First HINT message");
    EXPECT_EQ(diagnostics[7].severity, DiagnosticSeverity::HINT);
    EXPECT_EQ(diagnostics[7].message, "Second HINT message");
    EXPECT_EQ(diagnostics[8].severity, DiagnosticSeverity::HINT);
    EXPECT_EQ(diagnostics[8].message, "Third HINT message");
}

TEST_F(FakeDiagnosticsProviderTest, WillContainCorrectInfoDiagnostics)
{
    // GIVEN
    std::string document = "milica krmpotic";

    // WHEN
    auto diagnostics = diagnosticsProvider->getDiagnostics(document);

    // THEN
    EXPECT_EQ(diagnostics[9].severity, DiagnosticSeverity::INFORMATION);
    EXPECT_EQ(diagnostics[9].message, "First INFORMATION message");
    EXPECT_EQ(diagnostics[10].severity, DiagnosticSeverity::INFORMATION);
    EXPECT_EQ(diagnostics[10].message, "Second INFORMATION message");
    EXPECT_EQ(diagnostics[11].severity, DiagnosticSeverity::INFORMATION);
    EXPECT_EQ(diagnostics[11].message, "Third INFORMATION message");
}
