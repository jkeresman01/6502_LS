#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../../Algo/Trie.h"
#include "../../Repo/Instructions/FactoryImpl/InstructionSetRepoFactory.h"
#include "../../Types/Instruction.h"
#include "../IInstructionSetRepository.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, Instruction> InstructionsSetMapT;

//////////////////////////////////////////////////////////////
///
/// @class InstructionSetManager
///
/// @brief Manages the instruction set for the 6502 processor.
///        Provides access to all instructions and lookup functionality.
///
//////////////////////////////////////////////////////////////
class InstructionSetManager
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructor
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetManager() : m_instructionSetRepository(InstructionSetRepoFactory::create()){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted copy constructor
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetManager(const InstructionSetManager &) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted move constructor
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetManager(InstructionSetManager &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted copy assignment operator
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetManager &operator=(const InstructionSetManager &) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted move assignment operator
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetManager &operator=(InstructionSetManager &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Returns the singleton instance of InstructionSetManager
    ///

    ///
    //////////////////////////////////////////////////////////////
    static InstructionSetManager &getInstance();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves all available instructions
    ///
    /// @return A map containing all instructions
    ///
    //////////////////////////////////////////////////////////////
    InstructionsSetMapT getAllInstructions();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves instructions matching a given prefix
    ///
    /// @param [in] prefix The prefix to search for
    /// @return A vector of matching instruction mnemonics, if found
    ///
    //////////////////////////////////////////////////////////////
    std::optional<std::vector<std::string>> getInstructionsByPrefix(const std::string &prefix);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves an instruction by its mnemonic
    ///
    /// @param [in] mnemonic The instruction mnemonic
    /// @return The corresponding instruction, if found
    ///
    //////////////////////////////////////////////////////////////
    std::optional<Instruction> getInstructionsByMnemonic(const std::string &mnemonic);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads all available instructions into memory
    ///
    //////////////////////////////////////////////////////////////
    void loadInstructions();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Loads instructions into a trie structure for prefix-based lookup
    ///
    //////////////////////////////////////////////////////////////
    void loadInstructionSetTrie();

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Trie structure for fast instruction lookup
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Trie> m_instructionSetTrie;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Shared repository for accessing instruction sets
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Map storing all instruction mnemonics and corresponding instruction data
    ///
    //////////////////////////////////////////////////////////////
    InstructionsSetMapT m_instructionSet;
};
} // namespace ls6502
