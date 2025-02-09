#pragma once

#include <string>

#include "../Enums/RequestType.h"
#include "../Messages/Message.h"
#include "../Utils/Convert.h"
#include "../Utils/Logger.h"

namespace justanlsp
{
/////////////////////////////////////////////////////////////////////
///
/// @class Rpc
///
/// @brief Responsible for receive and sending messages defined by
///        language server protocol
///
/////////////////////////////////////////////////////////////////////
class Rpc
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    Rpc() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Send Message defined by language server protocol
    ///
    /// @param response
    ///
    /////////////////////////////////////////////////////////////////////
    static void send(const Message &response) { std::cout << response << std::endl; }

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Read JSON RPC request
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string receive();

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Read content length from JSON RPC request
    ///
    /////////////////////////////////////////////////////////////////////
    static uint32_t extractContentLength();
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline std::string Rpc::receive()
{
    uint32_t contentlength = extractContentLength();

    std::string content(contentlength, ' ');
    std::cin.read(&content[0], contentlength);

    return content;
}

inline uint32_t Rpc::extractContentLength()
{
    std::string header;
    uint32_t contentLength = 0;

    while (getline(std::cin, header))
    {
        header.erase(0, header.find_first_not_of(" \t\r\n\v\f"));
        header.erase(header.find_last_not_of(" \t\r\n\v\f") + 1);

        if (header.substr(0, 16) == "Content-Length: ")
        {
            contentLength = std::stoul(header.substr(16));
        }

        if (header.empty())
        {
            return contentLength;
        }
    }
}

} // namespace justanlsp
