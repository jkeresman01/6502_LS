#pragma once

#include <string>

namespace ls6502
{
struct AddressingModeDetailsS
{
  public:
    std::string syntax;
    uint32_t bytes;
    uint32_t cycles;
};
} // namespace ls6502
