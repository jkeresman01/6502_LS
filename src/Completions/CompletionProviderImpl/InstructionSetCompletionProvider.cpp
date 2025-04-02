////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "InstructionSetCompletionProvider.h"

#include <vector>
#include <optional>

#include "../../Manager/Instructions/InstructionSetManager.h"
#include "../../Repo/Instructions/FactoryImpl/InstructionSetRepoFactory.h"
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

    const std::vector<std::string> &instructions = InstructionSetManager::getInstance().getInstructionsByPrefix(prefix);

    return mapInstructionsToCompletions(instructions);
}

////////////////////////////////////////////////////////////
std::vector<CompletionItem> InstructionSetCompletionProvider::mapInstructionsToCompletions(
    const std::vector<std::string> &instructions)
{
    std::vector<CompletionItem> completionItems(instructions.size());

    for (const auto &instruction : instructions)
    {
        fillCompletionsForInstruction(instruction);
    }

    return completionItems;
}

////////////////////////////////////////////////////////////
void InstructionSetCompletionProvider::fillCompletionsForInstruction(
    const std::string &mnemonic, std::vector<CompletionItem> &completionItems)
{
    if (auto it = InstructionSetManager::getInstance().getInstructionByMnemonic(mnemonic))
    {
        createCompletionsForAllAddressingModes(*it, completionItems);
    }
    else
    {
        LS_6502_ERROR(STR("Unkown instruction, mnemonic: %s", mnemonic.c_str()));
    }
}

////////////////////////////////////////////////////////////
void InstructionSetCompletionProvider::createCompletionsForAllAddressingModes(
    const Instruction &instruction, std::vector<CompletionItem> &completionItems)
{
    for (const auto &addressingMode : instruction.addressingModes)
    {
        completionItems.emplace_back(addressingMode.assembler, CompletionItemKind::TEXT,
                                     instruction.description, addressingMode.getDetails(),
                                     addressingMode.getDetails());
    }
}

} // namespace ls6502
