#pragma once

#include <unordered_map>

#include "../Types/Instruction.h"

namespace ls6502
{
class IInstructionSetRepository
{
  public:
    virtual std::unordered_map<std::string, Instruction> load() = 0;
};
} // namespace ls6502
