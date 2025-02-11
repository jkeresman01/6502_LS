#include "InstructionSetCompletionProvider.h"

#include "../Repo/InstructionSetRepoFactory.h"

namespace ls6502
{
InstructionSetCompletionProvider::InstructionSetCompletionProvider()
    : m_instructionSetRepository(IInstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository.load();
    loadInstructionSetTrie();
}

void InstructionSetCompletionProvider::loadInstructionSetTrie()
{
    for (const auto &[instruction, _] : m_instructionSet)
    {
        m_instructionSetTrie->insert(instruction);
    }
}

std::vector<CompletionItem> InstructionSetCompletionProvider::getCompletions() override
{
    // TODO
}

} // namespace ls6502
