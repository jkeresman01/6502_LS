#pragma once

#include <string>

#include "../Enums/AddressingModes.h"

namespace ls6052
{

class AddressingModeUtil
{
  public:
    AddressingModeUtil() = delete;

    static AddressingMode stringToAddressingMode(const std::string &addressingMode);
    static const char *addressingModeToString(const AddressingMode addressingMode);
};
} // namespace ls6052
