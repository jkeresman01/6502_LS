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
typedef std::unordered_map<std::string, AddressingMode> StringAddressingModeMapT;
typedef std::unordered_map<AddressingMode, std::string> AddressingModeStringMapT;

class AddressingModeUtil
{
  public:
    AddressingModeUtil() = delete;

    static AddressingMode stringToAddressingMode(const std::string &addressingMode);
    static const char *addressingModeToString(const AddressingMode addressingMode);
};
} // namespace ls6502
