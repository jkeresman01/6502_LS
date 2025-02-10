#pragma once

#include <memory>

#include "IHoverProvider.h"

namespace ls6502
{
class InstructionSet6502HoverProvider : public IHoverProvider
{
  public:
    HoverItem getHoverItems(const std::string &document, const Position &position) override;

  private:
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;
};
} // namespace ls6502
