#include "InstructionSetCompletionProvider.h"

#include "../Repo/InstructionSetRepoFactory.h"
#include "../Types/Position.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"
#include "../Utils/StringUtil.h"

namespace ls6502
{
InstructionSetCompletionProvider::InstructionSetCompletionProvider()
    : m_instructionSetRepository(InstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository->load();
    loadInstructionSetTrie();
}

void InstructionSetCompletionProvider::loadInstructionSetTrie()
{
    for (const auto &[mnemonic, _] : m_instructionSet)
    {
        m_instructionSetTrie->insert(mnemonic);
    }
}

std::vector<CompletionItem> InstructionSetCompletionProvider::getCompletions(const std::string &document,
                                                                             const Position &position)
{
    std::string prefix = DocumentUtil::extractPrefix(document, position);

    StringUtil::toUpper(prefix);

    const std::vector<std::string> &instructions = m_instructionSetTrie->getCompletionWords(prefix);

    return mapInstructionsToCompletions(instructions);
}

std::vector<CompletionItem> InstructionSetCompletionProvider::mapInstructionsToCompletions(
    const std::vector<std::string> &instructions)
{
    m_completionItems.clear();
    m_completionItems.reserve(instructions.size());

    for (const auto &instruction : instructions)
    {
        fillCompletionsForInstruction(instruction);
    }

    return m_completionItems;
}

void InstructionSetCompletionProvider::fillCompletionsForInstruction(const std::string &instruction)
{
    InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

    if (it == m_instructionSet.end())
    {
        LS_6502_WARN(STR("%s isn't a valid 6502 assembly instruction", instruction.c_str()));
        return;
    }

    Instruction foundInstruction = it->second;
    createCompletionsForAllAddressingModes(foundInstruction);
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
