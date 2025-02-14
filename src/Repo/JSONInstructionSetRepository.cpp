#include "JSONInstructionSetRepository.h"

#include <nlohmann/json.hpp>

#include "../Utils/Logger.h"

namespace ls6502
{
InstructionSetMapT JSONInstructionSetRepository::load()
{
    std::ifstream instructionSetFile(INSTRUCTION_SET_FILE_PATH);

    if (!instructionSetFile)
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
    nlohmann::json jsonData;
    in >> jsonData;

    bool isValidJSONformat = jsonData.contains("instructions") or jsonData["instructions"].is_array();

    if (!isValidJSONformat)
    {
        throw std::runtime_error("Invalid JSON format: missing 'instructions' array");
    }

    for (const auto &jsonInstruction : jsonData["instructions"])
    {
        Instruction instruction;
        instruction.mnemonic = jsonInstruction["mnemonic"].get<std::string>();
        instruction.description = jsonInstruction["description"].get<std::string>();
        instruction.operation = jsonInstruction["operation"].get<std::string>();

        for (const auto &[flag, value] : jsonInstruction["flags"].items())
        {
            instruction.flags[flag] = value.get<bool>();
        }

        for (const auto &mode : jsonInstruction["addressing_modes"])
        {
            AddressingMode addressingMode;
            addressingMode.mode = mode["mode"].get<std::string>();
            addressingMode.assembler = mode["assembler"].get<std::string>();
            addressingMode.opcode = mode["opcode"].get<std::string>();
            addressingMode.bytes = mode["bytes"].get<int32_t>();
            addressingMode.cycles = mode["cycles"].get<int32_t>();

            if (mode.contains("extra_cycle"))
            {
                addressingMode.hasExtraCycle = mode["extra_cycle"].get<bool>();
            }
            else
            {
                addressingMode.hasExtraCycle = false;
            }

            instruction.addressingModes.push_back(addressingMode);
        }

        m_instructionSet[instruction.mnemonic] = instruction;
    }
}
} // namespace ls6502
