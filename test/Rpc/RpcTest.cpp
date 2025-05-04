#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include "../../src/Messages/Message.h"
#include "../../src/Rpc/Rpc.h"
#include "../../src/Utils/Convert.h"

using namespace ls6502;

class RpcTest : public ::testing::Test
{
  protected:
    void redirectStdin(const std::string &input)
    {
        inputStream.str(input);
        std::cin.rdbuf(inputStream.rdbuf());
    }

    void redirectStdout() { std::cout.rdbuf(outputStream.rdbuf()); }

    void restoreIO()
    {
        std::cin.rdbuf(cinBuffer);
        std::cout.rdbuf(coutBuffer);
    }

    std::string getCapturedOutput() { return outputStream.str(); }

    std::istringstream inputStream;
    std::ostringstream outputStream;
    std::streambuf *cinBuffer = std::cin.rdbuf();
    std::streambuf *coutBuffer = std::cout.rdbuf();

    void TearDown() override { restoreIO(); }
};

TEST_F(RpcTest, WillReadContentWithCorrectContentLength)
{
    // GIVEN
    std::string input = "Content-Length: 13\r\n\r\nSwilda Tinton";
    redirectStdin(input);

    // WHEN
    std::string content = Rpc::receive();

    // THEN
    EXPECT_EQ(content, "Swilda Tinton");
}

TEST_F(RpcTest, WillSendMessage)
{
    // GIVEN
    Message response("2.0");
    redirectStdout();

    // WHEN
    Rpc::send(response);

    // THEN
    std::string output = getCapturedOutput();

    std::string expectedContent = R"({"jsonrpc":"2.0"})";
    std::string expectedOutput =
        "Content-Length: " + std::to_string(expectedContent.size()) + "\r\n\r\n" + expectedContent + "\n\n";

    EXPECT_EQ(output, expectedOutput);
}

TEST_F(RpcTest, WillReadWithMultipleHeaders)
{
    // GIVEN
    std::string input =
        "Some-Header: value\r\nContent-Length: 11\r\nAnother-Header: value\r\n\r\nHello World";
    redirectStdin(input);

    // WHEN
    std::string content = Rpc::receive();

    // THEN
    EXPECT_EQ(content, "Hello World");
}

TEST_F(RpcTest, WillReturnEmptyStringIfNoContentLengthHeader)
{
    // GIVEN
    std::string input = "Some-Header: value\r\nAnother-Header: value\r\n\r\nNoContent";
    redirectStdin(input);

    // WHEN
    std::string content = Rpc::receive();

    // THEN
    EXPECT_EQ(content, "");
}

TEST_F(RpcTest, WillHandleMalformedContentLengthHeader)
{
    // GIVEN
    std::string input = "Content-Length: abc\r\n\r\n";
    redirectStdin(input);

    // WHEN
    EXPECT_THROW(Rpc::receive(), std::invalid_argument);
}

TEST_F(RpcTest, WillHandleZeroContentLength)
{
    // GIVEN
    std::string input = "Content-Length: 0\r\n\r\n";
    redirectStdin(input);

    // WHEN
    std::string content = Rpc::receive();

    // THEN
    EXPECT_EQ(content, "");
}
