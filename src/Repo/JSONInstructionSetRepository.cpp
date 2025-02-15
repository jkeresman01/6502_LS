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

    bool isValidJSONformat = jsonData.contains("instructions") && jsonData["instructions"].is_array();

    if (!isValidJSONformat)
    {
        LS_6502_WARN(STR("No can do for %s: Invalid JSON format - missing 'instructions' array",
                          INSTRUCTION_SET_FILE_PATH));
        return;
    }

    for (const auto &jsonInstruction : jsonData["instructions"])
    {
        Instruction instruction;

        if (jsonInstruction.contains("mnemonic"))
        {
            instruction.mnemonic = jsonInstruction["mnemonic"].get<std::string>();
        }
        else
        {
            LS_6502_WARN(
                STR("No can do for %s: Missing 'mnemonic' in instruction", INSTRUCTION_SET_FILE_PATH));
        }

        if (jsonInstruction.contains("description"))
        {
            instruction.description = jsonInstruction["description"].get<std::string>();
        }
        else
        {
            LS_6502_WARN(
                STR("No can do for %s: Missing 'description' in instruction", INSTRUCTION_SET_FILE_PATH));
        }

        if (jsonInstruction.contains("operation"))
        {
            instruction.operation = jsonInstruction["operation"].get<std::string>();
        }
        else
        {
            LS_6502_WARN(
                STR("No can do for %s: Missing 'operation' in instruction", INSTRUCTION_SET_FILE_PATH));
        }

        if (jsonInstruction.contains("flags") && jsonInstruction["flags"].is_object())
        {
            for (const auto &[flag, value] : jsonInstruction["flags"].items())
            {
                if (value.is_boolean())
                {
                    instruction.flags[flag] = value.get<bool>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Invalid value type for flag '%s'",
                                      INSTRUCTION_SET_FILE_PATH, flag.c_str()));
                }
            }
        }
        else
        {
            LS_6502_WARN(STR("No can do for %s: Missing or invalid 'flags' in instruction",
                              INSTRUCTION_SET_FILE_PATH));
        }

        if (jsonInstruction.contains("addressing_modes") && jsonInstruction["addressing_modes"].is_array())
        {
            for (const auto &mode : jsonInstruction["addressing_modes"])
            {
                AddressingMode addressingMode;

                if (mode.contains("mode"))
                {
                    addressingMode.mode = mode["mode"].get<std::string>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Missing 'mode' in addressing mode",
                                      INSTRUCTION_SET_FILE_PATH));
                }

                if (mode.contains("assembler"))
                {
                    addressingMode.assembler = mode["assembler"].get<std::string>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Missing 'assembler' in addressing mode",
                                      INSTRUCTION_SET_FILE_PATH));
                }

                if (mode.contains("opcode"))
                {
                    addressingMode.opcode = mode["opcode"].get<std::string>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Missing 'opcode' in addressing mode",
                                      INSTRUCTION_SET_FILE_PATH));
                }

                if (mode.contains("bytes"))
                {
                    addressingMode.bytes = mode["bytes"].get<int32_t>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Missing 'bytes' in addressing mode",
                                      INSTRUCTION_SET_FILE_PATH));
                }

                if (mode.contains("cycles"))
                {
                    addressingMode.cycles = mode["cycles"].get<int32_t>();
                }
                else
                {
                    LS_6502_WARN(STR("No can do for %s: Missing 'cycles' in addressing mode",
                                      INSTRUCTION_SET_FILE_PATH));
                }

                addressingMode.hasExtraCycle = mode.value("extra_cycle", false);

                instruction.addressingModes.push_back(addressingMode);
            }
        }
        else
        {
            LS_6502_WARN(STR("No can do for %s: Missing or invalid 'addressing_modes' in instruction",
                              INSTRUCTION_SET_FILE_PATH));
        }

        m_instructionSet[instruction.mnemonic] = instruction;
    }
}
} // namespace ls6502
