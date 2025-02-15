#pragma once

#include <nlohmann/json.hpp>

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
    void loadInstructionSet(const nlohmann::json &jsonData);

    void loadMnemonic(const nlohmann::json &jsonData, Instruction &instruction);
    void loadDescription(const nlohmann::json &jsonData, Instruction &instruction);
    void loadOperation(const nlohmann::json &jsonData, Instruction &instruction);
    void loadFlags(const nlohmann::json &jsonData, Instruction &instruction);

    void loadAddressingMode(const nlohmann::json &jsonData, AddressingMode &instruction);

    void loadMode(const nlohmann::json &jsonData, AddressingMode &addressingMode);
    void loadAssembler(const nlohmann::json &jsonData, AddressingMode &addressingMode);
    void loadOpcode(const nlohmann::json &jsonData, AddressingMode &addressingMode);
    void loadBytes(const nlohmann::json &jsonData, AddressingMode &addressingMode);
    void loadCycles(const nlohmann::json &jsonData, AddressingMode &addressingMode);

  private:
    InstructionSetMapT m_instructionSet;
    const char *INSTRUCTION_SET_FILE_PATH = "/home/josip/git/cpp/6502_LS/instructions/instructions.json";
};
} // namespace ls6502
