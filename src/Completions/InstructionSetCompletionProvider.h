#pragma once

#include <memory>
#include <unordered_map>
#include <vector>

#include "../Algo/Trie.h"
#include "../Repo/IInstructionSetRepository.h"
#include "../Types/Instruction.h"
#include "ICompletionProvider.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// Typedefs
///
/////////////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

/////////////////////////////////////////////////////////////////////
///
/// @class InstructionSetCompletionProvider
///
/// @brief Provides completion suggestions for instruction sets
///
/////////////////////////////////////////////////////////////////////
class InstructionSetCompletionProvider : public ICompletionProvider
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Constructor for InstructionSetCompletionProvider
    ///
    /////////////////////////////////////////////////////////////////////
    InstructionSetCompletionProvider();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves completion suggestions based on document context
    ///
    /// @param document
    /// @param position
    ///
    /// @return A vector of completion items
    ///
    /////////////////////////////////////////////////////////////////////
    virtual std::vector<CompletionItem> getCompletions(const std::string &document,
                                                       const Position &position) override;

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Loads instruction set data into a trie structure
    ///
    /////////////////////////////////////////////////////////////////////
    void loadInstructionSetTrie();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Maps a list of instructions to completion items
    ///
    /// @param instructions
    ///
    /// @return A vector of corresponding completion items
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<CompletionItem> mapInstructionsToCompletions(const std::vector<std::string> &instructions);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates completion suggestions for all addressing modes
    ///
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void createCompletionsForAllAddressingModes(const Instruction &instruction);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates completions for the given instruction
    ///
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void createCompletionsForInstruction(const std::string &instruction);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Trie structure for instruction set
    ///
    /////////////////////////////////////////////////////////////////////
    std::unique_ptr<Trie> m_instructionSetTrie = std::make_unique<Trie>();

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Repository for instruction set data
    ///
    /////////////////////////////////////////////////////////////////////
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Cached list of completion items
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<CompletionItem> m_completionItems;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Map of instruction names to Instruction objects
    ///
    /////////////////////////////////////////////////////////////////////
    InstructionSetMapT m_instructionSet;
};
} // namespace ls6502
