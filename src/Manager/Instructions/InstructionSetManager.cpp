////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <optional>

#include "InstructionSetManager.h"

#include "../../../Utils/Logger.h"
#include "../FactoryImpl/InstructionSetRepoFactory.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
InstructionsSetMapT InstructionSetManager::getAllInstructions()
{
    loadInstructions();

    return m_instructionSet;
}

////////////////////////////////////////////////////////////
std::optional<std::vector<std::string>> InstructionSetManager::getInstructionsByPrefix(
    const std::string &prefix)
{
    loadInstructionSetTrie();

    const std::vector<std::string> &instructions = m_instructionSetTrie->getCompletionWords();

    return instructions.empty() ? std::nullopt : std::make_optional<std::vector<std::string>>(instructions);
}

////////////////////////////////////////////////////////////
std::optional<Instruction> InstructionSetManager::getInstructionsByMnemonic(const std::string &mnemonic)
{
    loadInstructions();

    InstructionsSetMapT::iterator it = m_instructionSet.find(mnemonic);

    if (it == m_instructionSet.end())
    {
        LS_6502_ERROR(STR("No instruction found for mnemonic: %s", mnemonic.c_str()));
        return std::nullopt;
    }

    return it->second;
}

////////////////////////////////////////////////////////////
void InstructionSetManager::loadInstructions()
{
    if (m_instructionSet.empty())
    {
        m_instructionSet = m_instructionSetRepository->load();
    }
}

////////////////////////////////////////////////////////////
void InstructionSetManager::loadInstructionSetTrie()
{
    loadInstructions();

    for (const auto &[mnemonic, _] : m_instructionSet)
    {
        m_instructionSetTrie->insert(mnemonic);
    }
}

////////////////////////////////////////////////////////////
InstructionSetManager &InstructionSetManager::getInstance()
{
    static InstructionSetManager instance;
    return instance;
}
} // namespace ls6502
