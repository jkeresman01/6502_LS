#pragma once

#include <vector>

#include "../Types/HoverItem.h"
#include "../Types/Position.h"

namespace ls6502
{
class IHoverProvider
{
  public:
    virtual HoverItem getHoverItems(const std::string &document, const Position &position) = 0;
};
} // namespace ls6502
