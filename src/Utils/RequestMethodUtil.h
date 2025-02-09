#pragma once

#include <string>

#include "../Enums/RequestType.h"
#include "../Utils/Logger.h"

namespace justanlsp
{

/////////////////////////////////////////////////////////////////////
///
/// @class RequestMethodUtil
///
/// @brief Utility class for converting string method
///        type to enumeration
///
/////////////////////////////////////////////////////////////////////
class RequestMethodUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    RequestMethodUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts LSP request method to corresponding enum type
    ///
    /// @param method
    ///
    /////////////////////////////////////////////////////////////////////
    static RequestType getType(const std::string &method);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

RequestType inline RequestMethodUtil::getType(const std::string &method)
{
    if (method == "initialize")
    {
        return RequestType::INITIALIZE;
    }
    else if (method == "initialized")
    {
        return RequestType::INITIALIZED;
    }
    else if (method == "textDocument/didChange")
    {
        return RequestType::TEXT_DOCUMENT_DID_CHANGE;
    }
    else if (method == "textDocument/definition")
    {
        return RequestType::TEXT_DOCUMENT_DEFINITION;
    }
    else if (method == "textDocument/completion")
    {
        return RequestType::TEXT_DOCUMENT_COMPLETION;
    }
    else if (method == "textDocument/codeAction")
    {
        return RequestType::TEXT_DOCUMENT_CODE_ACTION;
    }
    else if (method == "textDocument/codeAction")
    {
        return RequestType::TEXT_DOCUMENT_DEFINITION;
    }
    else if (method == "textDocument/didOpen")
    {
        return RequestType::TEXT_DOCUMENT_DID_OPEN;
    }
    else if (method == "textDocument/hover")
    {
        return RequestType::TEXT_DOCUMENT_HOVER;
    }
    else if (method == "shutdown")
    {
        return RequestType::SHUTDOWN;
    }
    else if (method == "exit")
    {
        return RequestType::EXIT;
    }
    else
    {
        return RequestType::UNKNOWN;
    }
}

} // namespace justanlsp
