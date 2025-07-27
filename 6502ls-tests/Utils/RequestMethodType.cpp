#include <gtest/gtest.h>

#include "../../src/Enums/RequestType.h"
#include "../../src/Utils/RequestMethodUtil.h"

using namespace ls6502;

class RequestMethodUtilTest : public ::testing::Test
{
};

TEST_F(RequestMethodUtilTest, WillReturnCorrectRequestType)
{
    struct TestCase
    {
        std::string method;
        RequestType expectedType;
    };

    std::vector<TestCase> testCases = {{"initialize", RequestType::INITIALIZE},
                                       {"initialized", RequestType::INITIALIZED},
                                       {"textDocument/didChange", RequestType::TEXT_DOCUMENT_DID_CHANGE},
                                       {"textDocument/definition", RequestType::TEXT_DOCUMENT_DEFINITION},
                                       {"textDocument/completion", RequestType::TEXT_DOCUMENT_COMPLETION},
                                       {"textDocument/codeAction", RequestType::TEXT_DOCUMENT_CODE_ACTION},
                                       {"textDocument/didOpen", RequestType::TEXT_DOCUMENT_DID_OPEN},
                                       {"textDocument/hover", RequestType::TEXT_DOCUMENT_HOVER},
                                       {"shutdown", RequestType::SHUTDOWN},
                                       {"exit", RequestType::EXIT},
                                       {"unknownMethod", RequestType::UNKNOWN},
                                       {"", RequestType::UNKNOWN}};

    for (const auto &testCase : testCases)
    {
        EXPECT_EQ(RequestMethodUtil::getType(testCase.method), testCase.expectedType)
            << "Failed for method: " << testCase.method;
    }
}
