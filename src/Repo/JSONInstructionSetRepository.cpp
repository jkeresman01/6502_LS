#include "JSONInstructionSetRepository.h"
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

    bool isValidJSONFormat = jsonData.contains("instructions") && jsonData["instructions"].is_array();

    if (!isValidJSONFormat)
    {
        LS_6502_WARN(STR("No can do for %s: Invalid JSON format - missing 'instructions' array",
                         INSTRUCTION_SET_FILE_PATH));
        return;
    }

    loadInstructionSet(jsonData);
}

void JSONInstructionSetRepository::loadInstructionSet(const nlohmann::json &jsonData)
{
    for (const auto &jsonInstruction : jsonData["instructions"])
    {
        Instruction instruction;

        loadMnemonic(jsonInstruction, instruction);
        loadDescription(jsonInstruction, instruction);
        loadOperation(jsonInstruction, instruction);
        loadFlags(jsonInstruction, instruction);

        bool isValidJSONFormat =
            jsonInstruction.contains("addressing_modes") && jsonInstruction["addressing_modes"].is_array();

        if (!isValidJSONFormat)
        {
            LS_6502_WARN(STR("No can do for %s: Missing or invalid 'addressing_modes' in instruction",
                             INSTRUCTION_SET_FILE_PATH));
            continue;
        }

        for (const auto &mode : jsonInstruction["addressing_modes"])
        {
            AddressingMode addressingMode;
            loadAddressingMode(mode, addressingMode);
            instruction.addressingModes.push_back(addressingMode);
        }

        m_instructionSet[instruction.mnemonic] = instruction;

        LS_6502_DEBUG(STR("Loaded instruction: %s", instruction.toString().c_str()));
    }
}

void JSONInstructionSetRepository::loadMnemonic(const nlohmann::json &jsonData, Instruction &instruction)
{
    if (jsonData.contains("mnemonic"))
    {
        instruction.mnemonic = jsonData["mnemonic"].get<std::string>();
    }
    else
    {
        LS_6502_WARN(STR("No can do for %s: Missing 'mnemonic' in instruction", INSTRUCTION_SET_FILE_PATH));
    }
}

void JSONInstructionSetRepository::loadDescription(const nlohmann::json &jsonData, Instruction &instruction)
{
    if (!jsonData.contains("description"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'description' in instruction", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    instruction.description = jsonData["description"].get<std::string>();
}

void JSONInstructionSetRepository::loadOperation(const nlohmann::json &jsonData, Instruction &instruction)
{
    if (!jsonData.contains("operation"))
    {
        LS_6502_WARN(STR("No can do for %s: Missing 'operation' in instruction", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    instruction.operation = jsonData["operation"].get<std::string>();
}

void JSONInstructionSetRepository::loadFlags(const nlohmann::json &jsonData, Instruction &instruction)
{
    bool isValidJSONFormat = jsonData.contains("flags") && jsonData["flags"].is_object();

    if (!isValidJSONFormat)
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing or invalid 'flags' in instruction", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    for (const auto &[flag, value] : jsonData["flags"].items())
    {
        if (!value.is_boolean())
        {
            LS_6502_WARN(STR("No can do for %s: Invalid value type for flag '%s'", INSTRUCTION_SET_FILE_PATH,
                             flag.c_str()));
            continue;
        }

        instruction.flags[flag] = value.get<bool>();
    }
}

void JSONInstructionSetRepository::loadAddressingMode(const nlohmann::json &jsonData,
                                                      AddressingMode &addressingMode)
{
    loadMode(jsonData, addressingMode);
    loadAssembler(jsonData, addressingMode);
    loadOpcode(jsonData, addressingMode);
    loadBytes(jsonData, addressingMode);
    loadCycles(jsonData, addressingMode);

    addressingMode.hasExtraCycle = jsonData.value("extra_cycle", false);
}

void JSONInstructionSetRepository::loadMode(const nlohmann::json &jsonData, AddressingMode &addressingMode)
{
    if (!jsonData.contains("mode"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'jsonData' in addressing jsonData", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    addressingMode.mode = jsonData["mode"].get<std::string>();
}

void JSONInstructionSetRepository::loadAssembler(const nlohmann::json &jsonData,
                                                 AddressingMode &addressingMode)
{
    if (!jsonData.contains("assembler"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'assembler' in addressing jsonData", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    addressingMode.assembler = jsonData["assembler"].get<std::string>();
}

void JSONInstructionSetRepository::loadOpcode(const nlohmann::json &jsonData, AddressingMode &addressingMode)
{
    if (!jsonData.contains("opcode"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'opcode' in addressing jsonData", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    addressingMode.opcode = jsonData["opcode"].get<std::string>();
}

void JSONInstructionSetRepository::loadBytes(const nlohmann::json &jsonData, AddressingMode &addressingMode)
{
    if (!jsonData.contains("bytes"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'bytes' in addressing jsonData", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    addressingMode.bytes = jsonData["bytes"].get<int32_t>();
}

void JSONInstructionSetRepository::loadCycles(const nlohmann::json &jsonData, AddressingMode &addressingMode)
{
    if (!jsonData.contains("cycles"))
    {
        LS_6502_WARN(
            STR("No can do for %s: Missing 'cycles' in addressing jsonData", INSTRUCTION_SET_FILE_PATH));
        return;
    }

    addressingMode.cycles = jsonData["cycles"].get<int32_t>();
}

} // namespace ls6502
