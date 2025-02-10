#pragma once

#include <unordered_map>
#include <vector>

#include "../Enums/AddressingModes.h"
#include "AddressingMode.h"

namespace ls6502
{
struct Instruction
{
    std::string mnemonic;
    std::string description;
    std::string operation;
    std::string flags;
    std::vector<AddressingMode> addressingModes;

    std::string toString() const
    {
        std::ostringstream ss;

        ss << mnemonic << "\n" << description << "\n\n" << operation << "\n" << flags << "\n";
        ss << "addressing\tassembler\topc\tbytes\tcycles\n";

        for (const auto &addressingMode : addressingModes)
        {
            ss << addressingMode.toString() << "\n";
        }

        return ss.str();
    }
};
} // namespace ls6502
