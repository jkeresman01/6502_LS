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
    std::unordered_map<std::string, bool> flags;
    std::vector<AddressingMode> addressingModes;

    std::string toString() const
    {
        std::ostringstream ss;

        ss << "Mnemonic: " << mnemonic << "\n"
           << "Description: " << description << "\n\n"
           << "Operation: " << operation << "\n"
           << "Flags: ";

        if (flags.empty())
        {
            ss << "None\n";
        }
        else
        {
            for (const auto &[flag, value] : flags)
            {
                ss << flag << "=" << (value ? "1" : "0") << " ";
            }
            ss << "\n";
        }

        ss << "\nAddressing Modes:\n";
        ss << "---------------------------------------------------\n";
        ss << "Mode\t\tAssembler\tOpcode\tBytes\tCycles\n";
        ss << "---------------------------------------------------\n";

        for (const auto &addressingMode : addressingModes)
        {
            ss << addressingMode.toString();
        }

        return ss.str();
    }
};
} // namespace ls6502
