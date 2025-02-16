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
    /// @brief Creates completion suggestions for all addressing modes
    ///
    /// @param instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void createCompletionsForAllAddressingModes(const Instruction &instruction);

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

  private:
    std::unique_ptr<Trie> m_instructionSetTrie =
        std::make_unique<Trie>(); ///< Trie structure for instruction set

    std::shared_ptr<IInstructionSetRepository>
        m_instructionSetRepository; ///< Repository for instruction set data

    std::vector<CompletionItem> m_completionItems; ///< Cached list of completion items

    InstructionSetMapT m_instructionSet; ///< Map of instruction names to Instruction objects
};
