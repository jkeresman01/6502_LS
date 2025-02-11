#pragma once

#include <vector>
#include <memory>

#include "../Types/Position.h"
#include "../Repo/IInstructionSetRepository.h"
#include "IHoverProvider.h"

namespace ls6502
{
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

class InstructionSet6502HoverProvider : public IHoverProvider
{
  public:
    InstructionSet6502HoverProvider();

    HoverItem getHoverItem(const std::string &document, const Position &position) override;

  private:
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    InstructionSetMapT m_instructionSet;
};
} // namespace ls6502
