#pragma once

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

class AddressingModeUtil
{
  public:
    AddressingModeUtil() = delete;

    static AddressingModes stringToAddressingMode(const std::string &addressingMode);
    static const char *addressingModeToString(const AddressingModes addressingMode);
};
} // namespace ls6502
