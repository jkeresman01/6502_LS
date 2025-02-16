#pragma once

#include <nlohmann/json.hpp>

#include "IInstructionSetRepository.h"

namespace ls6502
{

typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

/////////////////////////////////////////////////////////////////////
///
/// @class JSONInstructionSetRepository
///
/// @brief Loads and manages instruction set data from a JSON file
///
/////////////////////////////////////////////////////////////////////
class JSONInstructionSetRepository : public IInstructionSetRepository
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads the instruction set from a JSON file
    ///
    /// @return A map of instruction names to Instruction objects
    ///
    /////////////////////////////////////////////////////////////////////
    InstructionSetMapT load() override;

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads instruction set data from an input file stream
    ///
    /// @param in
    ///
    /////////////////////////////////////////////////////////////////////
    void load(std::ifstream &in);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Parses instruction set data from a JSON object
    ///
    /// @param jsonData
    ///
    /////////////////////////////////////////////////////////////////////
    void loadInstructionSet(const nlohmann::json &jsonData);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads mnemonic details into an instruction object
    ///
    /// @param jsonData
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void loadMnemonic(const nlohmann::json &jsonData, Instruction &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads the description of an instruction
    ///
    /// @param jsonData
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void loadDescription(const nlohmann::json &jsonData, Instruction &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads the operation details of an instruction
    ///
    /// @param jsonData
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void loadOperation(const nlohmann::json &jsonData, Instruction &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads flag modifications associated with an instruction
    ///
    /// @param jsonData
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void loadFlags(const nlohmann::json &jsonData, Instruction &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads addressing mode details
    ///
    /// @param jsonData
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void loadAddressingMode(const nlohmann::json &jsonData, AddressingMode &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads the mode of an addressing mode object
    ///
    /// @param jsonData
    /// @param addressingMode
    ///
    /////////////////////////////////////////////////////////////////////
    void loadMode(const nlohmann::json &jsonData, AddressingMode &addressingMode);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads assembler syntax for an addressing mode
    ///
    /// @param jsonData
    /// @param addressingMode
    ///
    /////////////////////////////////////////////////////////////////////
    void loadAssembler(const nlohmann::json &jsonData, AddressingMode &addressingMode);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads opcode details for an addressing mode
    ///
    /// @param jsonData
    /// @param addressingMode
    ///
    /////////////////////////////////////////////////////////////////////
    void loadOpcode(const nlohmann::json &jsonData, AddressingMode &addressingMode);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads byte size details for an addressing mode
    ///
    /// @param jsonData
    /// @param addressingMode
    ///
    /////////////////////////////////////////////////////////////////////
    void loadBytes(const nlohmann::json &jsonData, AddressingMode &addressingMode);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads cycle count details for an addressing mode
    ///
    /// @param jsonData
    /// @param addressingMode
    ///
    /////////////////////////////////////////////////////////////////////
    void loadCycles(const nlohmann::json &jsonData, AddressingMode &addressingMode);

  private:
    InstructionSetMapT m_instructionSet; ///< Map of instruction names to Instruction objects
    const char *INSTRUCTION_SET_FILE_PATH =
        "/home/josip/git/cpp/6502_LS/instructions/instructions.json"; ///< Path to the JSON instruction set
                                                                      ///< file
};

} // namespace ls6502
