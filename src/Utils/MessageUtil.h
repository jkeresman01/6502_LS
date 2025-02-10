#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "../Enums/RequestType.h"
#include "Logger.h"
#include "RequestMethodUtil.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class MessageUtil
///
/// @brief Utility class for handling LSP messages
///
/////////////////////////////////////////////////////////////////////
class MessageUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    MessageUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /// @param request
    ///
    /// @return request method/type
    ///
    /////////////////////////////////////////////////////////////////////
    static RequestType getType(const nlohmann::json &request);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Try to parse LSP request received from stdin
    ///
    /// @param request
    ///
    /// @return json object
    ///
    /////////////////////////////////////////////////////////////////////
    static nlohmann::json tryParse(const std::string &request);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline nlohmann::json MessageUtil::tryParse(const std::string &request)
{
    nlohmann::json jsonRequest;
    try
    {
        jsonRequest = nlohmann::json::parse(request);
    }
    catch (const std::exception &e)
    {
        LS_6502_ERROR(STR("Failed to parse request: %s!", e.what()));
    }

    return jsonRequest;
}

inline RequestType MessageUtil::getType(const nlohmann::json &request)
{
    auto it = request.find("method");

    if (it == request.end())
    {
        LS_6502_ERROR("Received unknown request type");
        return RequestType::UNKNOWN;
    }

    std::string method = std::string(request["method"]);
    return RequestMethodUtil::getType(method);
}

} // namespace ls6502
