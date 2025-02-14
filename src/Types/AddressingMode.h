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
    ;

    std::string toString() const
    {
        std::stringstream ss;
        ss << mode << "\t" << assembler << "\t" << opcode << "\t" << bytes << "\t" << cycles;
        ss << "\t"
           << "Extra cycle: " << (hasExtraCycle ? "YES" : "NO") << "\n";
        return ss.str();
    }
};

} // namespace ls6502
