#include "../../src/CodeActions/FakeCodeActionsProvider.h"

#include "../../src/CodeActions/ICodeActionsProvider.h"
#include "../../src/Types/CodeAction.h"

#include <gtest/gtest.h>
#include <memory>

using namespace ls6502;

class FakeCodeActionsProviderTest : public ::testing::Test
{
  protected:
    std::unique_ptr<ICodeActionsProvider> m_fakeCodeActionProvider =
        std::make_shared<FakeCodeActionProvider>();
};

TEST_F(FakeCodeActionsProviderTest, WillReturnFakeCodeActions)
{
    // GIVEN
    std::string testURI = "file:///test.cpp";

    // WHEN
    std::vector<CodeAction> result = m_fakeCodeActionProvider.getCodeActions(testURI);

    // THEN
    EXPECT_EQ(result.size(), 3);
    EXPECT_EQ(result[0].title, "Code action test");
    EXPECT_EQ(result[1].title, "Code action test 1");
    EXPECT_EQ(result[2].title, "Code action test 2");
}
