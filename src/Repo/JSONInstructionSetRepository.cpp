#include "JSONInstructionSetRepository.h"

#include <nlohmann/json.hpp>

#include "../Utils/Logger.h"

namespace ls6502
{
InstructionSetMapT JSONInstructionSetRepository::load()
{
    std::ifstream instructionSetFile(INSTRUCTION_SET_FILE_PATH);

    if (!instructionSetFile.is_open())
    {
        LS_6502_ERROR(STR("No can do for %s", INSTRUCTION_SET_FILE_PATH));
        return {};
    }

    load(instructionSetFile);

    instructionSetFile.close();

    return m_instructionSet;
}

void JSONInstructionSetRepository::load(std::ifstream &in)
{
    nlohmann::json jsonInstructions;
    in >> jsonInstructions;

    for (const auto &jsonInstruction : jsonInstructions)
    {
        Instruction instruction;
        instruction.mnemonic = jsonInstruction["mnemonic"];
        instruction.description = jsonInstruction["description"];
        instruction.operation = jsonInstruction["operation"];
        instruction.flags = jsonInstruction["flags"];

        for (const auto &mode : jsonInstruction["addressingModes"])
        {
            AddressingMode addressingMode;
            addressingMode.mode = mode["mode"];
            addressingMode.assembler = mode["assembler"];
            addressingMode.opcode = mode["opcode"];
            addressingMode.bytes = mode["bytes"];
            addressingMode.cycles = mode["cycles"];
            instruction.addressingModes.push_back(addressingMode);
        }

        m_instructionSet[instruction.mnemonic] = instruction;
    }
}
} // namespace ls6502
