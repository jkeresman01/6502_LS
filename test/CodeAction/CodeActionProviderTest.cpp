#include "../../src/CodeActions/CodeActionProvider.h"

#include "../../src/Diagnostics/DiagnosticsProviderFactory.h"
#include "../../src/Types/CodeAction.h"
#include "../../src/Types/Diagnostic.h"
#include "../../src/Types/Range.h"

#include <gtest/gtest.h>
#include <memory>

using namespace ls6502;

class CodeActionProviderTest : public ::testing::Test
{
  protected:
    std::unique_ptr<CodeActionProvider> m_codeActionProvider;

    void SetUp() override { m_codeActionProvider = std::make_unique<CodeActionProvider>(); }
};

TEST_F(CodeActionProviderTest, ReturnsCodeActionForMissingLabel)
{
    // GIVEN
    std::string document = "LABEL";
    std::string uri = "file:///test.asm";

    Diagnostic diagnostic(Range{{0, 0}, {0, 5}}, DiagnosticSeverity::ERROR, "mock", "Label missing ':'");

    // Mock Diagnostics Provider
    auto mockDiagnosticsProvider =
        std::make_shared<FakeDiagnosticsProvider>(std::vector<Diagnostic>{diagnostic});
    m_codeActionProvider->setDiagnosticsProvider(mockDiagnosticsProvider);

    // WHEN
    std::vector<CodeAction> codeActions = m_codeActionProvider->getCodeActions(document, uri);

    // THEN
    ASSERT_EQ(codeActions.size(), 1);
    EXPECT_EQ(codeActions[0].getTitle(), "Add missing ':' to label");
}

TEST_F(CodeActionProviderTest, ReturnsCodeActionForUnexpectedSemicolon)
{
    // GIVEN
    std::string document = "LDA #10;";
    std::string uri = "file:///test.asm";

    Diagnostic diagnostic(Range{{0, 7}, {0, 8}}, DiagnosticSeverity::ERROR, "mock", "Unexpected ';'");

    auto mockDiagnosticsProvider =
        std::make_shared<FakeDiagnosticsProvider>(std::vector<Diagnostic>{diagnostic});
    m_codeActionProvider->setDiagnosticsProvider(mockDiagnosticsProvider);

    // WHEN
    std::vector<CodeAction> codeActions = m_codeActionProvider->getCodeActions(document, uri);

    // THEN
    ASSERT_EQ(codeActions.size(), 1);
    EXPECT_EQ(codeActions[0].getTitle(), "Remove unexpected ';'");
}

TEST_F(CodeActionProviderTest, ReturnsCodeActionForUnsupportedInstruction)
{
    // GIVEN
    std::string document = "FOO #10";
    std::string uri = "file:///test.asm";

    Diagnostic diagnostic(Range{{0, 0}, {0, 7}}, DiagnosticSeverity::ERROR, "mock",
                          "Unsupported instruction");

    auto mockDiagnosticsProvider =
        std::make_shared<FakeDiagnosticsProvider>(std::vector<Diagnostic>{diagnostic});
    m_codeActionProvider->setDiagnosticsProvider(mockDiagnosticsProvider);

    // WHEN
    std::vector<CodeAction> codeActions = m_codeActionProvider->getCodeActions(document, uri);

    // THEN
    ASSERT_EQ(codeActions.size(), 1);
    EXPECT_EQ(codeActions[0].getTitle(), "Replace unsupported instruction");
}

TEST_F(CodeActionProviderTest, ReturnsCodeActionForIncorrectInstructionUsage)
{
    // GIVEN
    std::string document = "LDA #";
    std::string uri = "file:///test.asm";

    Diagnostic diagnostic(Range{{0, 0}, {0, 5}}, DiagnosticSeverity::ERROR, "mock",
                          "Incorrect instruction usage");

    auto mockDiagnosticsProvider =
        std::make_shared<FakeDiagnosticsProvider>(std::vector<Diagnostic>{diagnostic});
    m_codeActionProvider->setDiagnosticsProvider(mockDiagnosticsProvider);

    // WHEN
    std::vector<CodeAction> codeActions = m_codeActionProvider->getCodeActions(document, uri);

    // THEN
    ASSERT_EQ(codeActions.size(), 1);
    EXPECT_EQ(codeActions[0].getTitle(), "Fix instruction usage");
}
