////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "InstructionSetCompletionProvider.h"

#include "../../Manager/Instructions/InstructionSetManager.h"
#include "../../Repo/InstructionSetRepoFactory.h"
#include "../../Types/Position.h"
#include "../../Utils/DocumentUtil.h"
#include "../../Utils/Logger.h"
#include "../../Utils/StringUtil.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
std::vector<CompletionItem> InstructionSetCompletionProvider::getCompletions(const std::string &document,
                                                                             const Position &position)
{
    std::string prefix = DocumentUtil::extractPrefix(document, position);

    StringUtil::toUpper(prefix);

    std::optional<std::vector<std::string>> &instructions =
        InstructionSetManager::getInstance().getInstructionsByPrefix(prefix);

    return instructions ? mapInstructionsToCompletions(instructions.value()) : std::vector<std::string>();
}

////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////
void InstructionSetCompletionProvider::fillCompletionsForInstruction(const std::string &instruction)
{
    InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

    if (it == m_instructionSet.end())
    {
        LS_6502_WARN(STR("%s isn't a valid 6502 assembly instruction", instruction.c_str()));
        return;
    }

    const Instruction &foundInstruction = it->second;
    createCompletionsForAllAddressingModes(foundInstruction);
}

////////////////////////////////////////////////////////////
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
