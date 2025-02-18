#include "InstructionSetCompletionProvider.h"

#include <algorithm>
#include <functional>

#include "../Repo/InstructionSetRepoFactory.h"
#include "../Types/Position.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"

namespace ls6502
{
InstructionSetCompletionProvider::InstructionSetCompletionProvider()
    : m_instructionSetRepository(IInstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository->load();
    loadInstructionSetTrie();
}

void InstructionSetCompletionProvider::loadInstructionSetTrie()
{
    for (const auto &[instruction, _] : m_instructionSet)
    {
        m_instructionSetTrie->insert(instruction);
    }
}

std::vector<CompletionItem> InstructionSetCompletionProvider::getCompletions(const std::string &document,
                                                                             const Position &position)
{
    std::string prefix = DocumentUtil::extractPrefix(document, position);

    std::transform(prefix.begin(), prefix.end(), prefix.begin(),
                   std::ptr_fun<int32_t, int32_t>(std::toupper));

    std::vector<std::string> instructions = m_instructionSetTrie->getCompletionWords(prefix);

    return mapInstructionsToCompletions(instructions);
}

std::vector<CompletionItem> InstructionSetCompletionProvider::mapInstructionsToCompletions(
    const std::vector<std::string> &instructions)
{
    m_completionItems.clear();

    for (const auto &instruction : instructions)
    {
        InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

        if (it == m_instructionSet.end())
        {
            LS_6502_WARN(STR("%s isn't a valid 6502 assembly instruction", instruction.c_str()));
            continue;
        }

        Instruction foundInstruction = it->second;
        createCompletionsForAllAddressingModes(foundInstruction);
    }

    return m_completionItems;
}

void InstructionSetCompletionProvider::createCompletionsForAllAddressingModes(const Instruction &instruction)
{
    for (const auto &addressingMode : instruction.addressingModes)
    {
        m_completionItems.emplace_back(addressingMode.assembler, CompletionItemKind::TEXT,
                                       instruction.description, addressingMode.getDetails(),
                                       addressingMode.getDetails());
    }
}

} // namespace ls6502
