#pragma once

#include <algorithm>
#include <functional>
#include <string>

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class StringUtil
///
/// @brief String manipulation utility class
///
/////////////////////////////////////////////////////////////////////
class StringUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    StringUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Trims the provided string
    ///
    /// @param line
    ///
    /// @return trimed string, or empty string if all whitespaces
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string trim(const std::string &line);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

std::string inline StringUtil::trim(const std::string &line)
{
    size_t start = line.find_first_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
    {
        return std::string();
    }

    size_t end = line.find_last_not_of(" \t\n\r\f\v");
    return line.substr(start, end - start + 1);
}
} // namespace ls6502
