#pragma once

#include "../Enums/AddressingModes.h"
#include "AddressingModeDetails.h"

#include <unordered_map>

namespace ls6502
{
typedef std::unordered_map<AddressingMode, AddressingModeDetailsS> AddressingModesMapT;

struct Instruction
{
  public:
    std::string description;
    AddressingModesMapT addressingModes;
};
} // namespace ls6502
