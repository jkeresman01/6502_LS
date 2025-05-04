#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>
#include <unordered_map>

#include "../Enums/AddressingModes.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, AddressingModes> StringAddressingModeMapT;
typedef std::unordered_map<AddressingModes, std::string> AddressingModeStringMapT;

//////////////////////////////////////////////////////////////
///
/// @class AddressingModeUtil
///
/// @brief A utility class that provides conversion
///        functions between string representations and
///        enumeration values of addressing modes.
///
//////////////////////////////////////////////////////////////
class AddressingModeUtil
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    AddressingModeUtil() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts a string representation of an addressing mode
    ///        to its corresponding enum value.
    ///
    /// @param [in] addressingMode
    ///
    /// @return The corresponding AddressingModes enum value.
    ///
    //////////////////////////////////////////////////////////////
    static AddressingModes stringToAddressingMode(const std::string& addressingMode);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts an addressing mode enum value to
    ///        its string representation.
    ///
    /// @param [in] addressingMode
    ///
    /// @return A C-string representing the addressing mode.
    ///
    //////////////////////////////////////////////////////////////
    static const char* addressingModeToString(const AddressingModes addressingMode);
};

} // namespace ls6502
