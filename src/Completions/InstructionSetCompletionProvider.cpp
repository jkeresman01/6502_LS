#include "InstructionSetCompletionProvider.h"

#include "../Repo/InstructionSetRepoFactory.h"
#include "../Types/Position.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"

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

std::vector<CompletionItem> InstructionSetCompletionProvider::getCompletions(const std::string &document,
                                                                             const Positon &position) override
{
    std::string instruction = DocumentUtil::extractPrefix(document, position);

    InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

    if (it == m_instructionSet.end())
    {
        LS_6502_WARN(STR("%s isn't a vaid 6502 assembly instruction", instruction.c_str()));
        return {};
    }

    Instruction instructionDetails = it->second;

    // TODO finish creat comletion item, return vector
}

} // namespace ls6502
