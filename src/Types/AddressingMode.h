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

    std::string toString() const
    {
        std::stringstream ss;
        ss << mode << "\t" << assembler << "\t" << opcode << "\t" << bytes << "\t" << cycles;
        return ss.str();
    }
};

} // namespace ls6502
