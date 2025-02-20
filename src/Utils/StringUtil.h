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
    /// @param string
    ///
    /////////////////////////////////////////////////////////////////////
    static void trim(std::string &string);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the string to upper case
    ///
    /// @param string
    ///
    /////////////////////////////////////////////////////////////////////
    static void toUpper(std::string &string);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the string to lower case
    ///
    /// @param string
    ///
    /////////////////////////////////////////////////////////////////////
    static void toLower(std::string &string);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

void inline StringUtil::trim(std::string &string)
{
    size_t start = string.find_first_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
    {
        return;
    }

    size_t end = string.find_last_not_of(" \t\n\r\f\v");
    string = string.substr(start, end - start + 1);
}

void inline StringUtil::toUpper(std::string &string)
{
    std::transform(string.begin(), string.end(), string.begin(),
                   std::ptr_fun<int32_t, int32_t>(std::toupper));
}
void inline StringUtil::toLower(std::string &string)
{
    std::transform(string.begin(), string.end(), string.begin(),
                   std::ptr_fun<int32_t, int32_t>(std::tolower));
}

} // namespace ls6502
