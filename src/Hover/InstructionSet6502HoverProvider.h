#pragma once

#include "../Types/Position.h"
#include "IHoverProvider.h"

#include <vector>

namespace ls6502
{
class InstructionSet6502HoverProvider : public IHoverProvider
{
  public:
    HoverItem getHoverItem(const std::string &document, const Position &position) override;
};
} // namespace ls6502
