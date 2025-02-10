#pragma once

#include "IInstructionSetRepository.h"

namespace ls6502
{

typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

class JSONInstructionSetRepository : public IInstructionSetRepository
{
  public:
    InstructionSetMapT load() override;

  private:
    void load(std::ifstream &in);

  private:
    InstructionSetMapT m_instructionSet;
    const char *INSTRUCTION_SET_FILE_PATH = "../../instructions/instructions.json";
};
} // namespace ls6502
