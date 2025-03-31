#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <memory>
#include <unordered_map>
#include <vector>

#include "../../Algo/Trie.h"
#include "../../Repo/IInstructionSetRepository.h"
#include "../../Types/Instruction.h"
#include "../ICompletionProvider.h"

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
    InstructionSetCompletionProvider() = default;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves completion suggestions based on document context
    ///
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return A vector of completion items
    ///
    /////////////////////////////////////////////////////////////////////
    virtual std::vector<CompletionItem> getCompletions(const std::string &document,
                                                       const Position &position) override;

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Maps a list of instructions to completion items
    ///
    /// @param [in] instructions
    ///
    /// @return A vector of corresponding completion items
    ///
    /////////////////////////////////////////////////////////////////////
    std::vector<CompletionItem> mapInstructionsToCompletions(const std::string &mnemonic, std::vector<CompletionItem> &completionItems);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates completion suggestions for all addressing modes
    ///
    /// @param [in] instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void createCompletionsForAllAddressingModes(const Instruction &mnemonic, std::vector<CompletionItem> &completionItems);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Creates completions for the given instruction
    ///
    /// @param [in] instruction
    ///
    /////////////////////////////////////////////////////////////////////
    void fillCompletionsForInstruction(const std::string &instruction, std::vector<CompletionItem> &completionItems);
};
} // namespace ls6502
