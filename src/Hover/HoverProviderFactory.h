#pragma once

#include <memory>

#include "IHoverProvider.h"
#include "InstructionSet6502HoverProvider.h"

namespace ls6502
{
class HoverProviderFactory
{
  public:
    HoverProviderFactory() = delete;

    static std::shared_ptr<IHoverProvider> create()
    {
        return std::make_shared<InstructionSet6502HoverProvider>();
    }
};
} // namespace ls6502
