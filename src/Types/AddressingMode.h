#pragma once

#include <sstream>
#include <string>

namespace ls6502
{
struct AddressingMode
{
  public:
    std::string mode;
    std::string assembler;
    std::string opcode;
    uint32_t bytes;
    uint32_t cycles;
    bool hasExtraCycle;

    std::string getDetails() const
    {
        std::stringstream ss;
        ss << "Opcode: " << opcode << ", bytes: " << bytes << ", cycles: " << cycles << "\r\n";
        return ss.str();
    }

    std::string toString() const
    {
        std::stringstream ss;

        ss << mode << "\t";
        ss << assembler << "\t";
        ss << opcode << "\t";
        ss << bytes << "\t";
        ss << cycles << "\t";
        ss << "Extra cycle: " << (hasExtraCycle ? "YES" : "NO") << "\n";

        return ss.str();
    }
};

} // namespace ls6502
