////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////


#include "InstructionSetManager.h"

#include <optional>

#include "../../Repo/Instructions/FactoryImpl/InstructionSetRepoFactory.h"
#include "../../Utils/Logger.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
InstructionsSetMapT InstructionSetManager::getAllInstructions()
{
    loadInstructions();
    return m_instructionSet;
}


////////////////////////////////////////////////////////////
std::vector<std::string> InstructionSetManager::getInstructionsByPrefix(const std::string& prefix)
{
    loadInstructionSetTrie();
    return m_instructionSetTrie->getCompletionWords(prefix);
}


////////////////////////////////////////////////////////////
std::optional<Instruction> InstructionSetManager::getInstructionByMnemonic(const std::string& mnemonic)
{
    loadInstructions();

    InstructionsSetMapT::iterator it = m_instructionSet.find(mnemonic);

    if (it == m_instructionSet.end())
    {
        LS_6502_ERROR(STR("No instruction found for mnemonic: %s", mnemonic.c_str()));
        return std::nullopt;
    }

    return std::make_optional(it->second);
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

    for (const auto& [mnemonic, _] : m_instructionSet)
    {
        m_instructionSetTrie->insert(mnemonic);
    }
}


////////////////////////////////////////////////////////////
InstructionSetManager& InstructionSetManager::getInstance()
{
    static InstructionSetManager instance;
    return instance;
}


} // namespace ls6502
