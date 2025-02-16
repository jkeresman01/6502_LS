#pragma once

#include <unordered_map>

#include "../Types/Instruction.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class IInstructionSetRepository
///
/// @brief Interface for loading an instruction set repository
///
/////////////////////////////////////////////////////////////////////
class IInstructionSetRepository
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Pure virtual function to load the instruction set
    ///
    /// @return A map of instruction names to Instruction objects
    ///
    /////////////////////////////////////////////////////////////////////
    virtual std::unordered_map<std::string, Instruction> load() = 0;
};

} // namespace ls6502
