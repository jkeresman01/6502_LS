#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <unordered_map>
#include <vector>

#include "../Enums/AddressingModes.h"
#include "AddressingMode.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @struct Instruction
///
/// @brief Represents an instruction in the 6502 instruction set.
///
//////////////////////////////////////////////////////////////
struct Instruction
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The mnemonic of the instruction.
    ///
    //////////////////////////////////////////////////////////////
    std::string mnemonic;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A brief description of the instruction.
    ///
    //////////////////////////////////////////////////////////////
    std::string description;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The operation performed by the instruction.
    ///
    //////////////////////////////////////////////////////////////
    std::string operation;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A map of flags affected by the instruction.
    ///
    //////////////////////////////////////////////////////////////
    std::unordered_map<std::string, bool> flags;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A list of addressing modes supported by the instruction.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<AddressingMode> addressingModes;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the instruction details to a formatted string.
    ///
    /// @return A string containing the formatted instruction details.
    ///
    //////////////////////////////////////////////////////////////
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
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Appends flag information to the provided
    ///        output stream.
    ///
    /// @param [in,out] ss The output stream to which
    ///        flag details are added.
    ///
    //////////////////////////////////////////////////////////////
    void putFlags(std::ostringstream& ss) const
    {
        for (const auto& [flag, value] : flags)
        {
            ss << flag << "=" << (value ? "1" : "0") << " ";
        }

        ss << "\n";
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Appends addressing mode details to the
    ///        provided output stream.
    ///
    /// @param [in,out] ss The output stream to which addressing
    ///         mode details are added.
    ///
    //////////////////////////////////////////////////////////////
    void putAddressingModes(std::ostringstream& ss) const
    {
        for (const auto& addressingMode : addressingModes)
        {
            ss << addressingMode.toString();
        }
    }
};

} // namespace ls6502
