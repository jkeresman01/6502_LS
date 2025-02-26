#pragma once

#include <unordered_map>
#include <vector>

#include "../Enums/AddressingModes.h"
#include "AddressingMode.h"

namespace ls6502
{

struct Instruction
{
  public:
    std::string mnemonic;
    std::string description;
    std::string operation;
    std::unordered_map<std::string, bool> flags;
    std::vector<AddressingMode> addressingModes;

    std::string toString() const
    {
        std::ostringstream ss;

        ss << "Mnemonic: " << mnemonic << "\n";
        ss << "Description: " << description << "\n\n";
        ss << "Operation: " << operation << "\n";
        ss << "Flags: ";

        if (flags.empty())
        {
            ss << "None\n";
        }
        else
        {
            putFlags(ss);
        }

        ss << "\nAddressing Modes:\n";
        ss << "---------------------------------------------------\n";
        ss << "Mode\t\tAssembler\tOpcode\tBytes\tCycles\n";
        ss << "---------------------------------------------------\n";

        putAddressingModes(ss);

        return ss.str();
    }

  private:
    void putFlags(std::ostringstream &ss) const
    {
        for (const auto &[flag, value] : flags)
        {
            ss << flag << "=" << (value ? "1" : "0") << " ";
        }

        ss << "\n";
    }

    void putAddressingModes(std::ostringstream &ss) const
    {
        for (const auto &addressingMode : addressingModes)
        {
            ss << addressingMode.toString();
        }
    }
};
} // namespace ls6502
