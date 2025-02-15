#pragma once

#include "IHoverProvider.h"

#include <string>

namespace ls6502
{
class FakeHoverProvider : public IHoverProvider
{
  public:
    FakeHoverProvider() = default;

    HoverItem getHoverItem(const std::string &document, const Position &position) override;
};
} // namespace ls6502
