#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <sstream>
#include <string>

#include "../Utils/Logger.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class Converter
///
/// @brief Utility class for converting stuff
///
/////////////////////////////////////////////////////////////////////
class Converter
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    Converter() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the given string input to provided type
    ///
    /// @param [in] input
    ///
    /////////////////////////////////////////////////////////////////////
    template <typename T> static T convert(const std::string &input);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
template <typename T> inline T Converter::convert(const std::string &input)
{
    T result;
    std::stringstream converter(input);

    if (!(converter >> result))
    {
        LS_6502_ERROR(STR("Conversion failed: invalid input '%s'", input.c_str()));
    }

    if (!converter.eof())
    {
        LS_6502_ERROR(STR("Conversion failed: extra characters in input '%s'", input.c_str()));
    }

    return result;
}

} // namespace ls6502
