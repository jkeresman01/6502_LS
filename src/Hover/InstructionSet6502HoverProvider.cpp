#include "InstructionSet6502HoverProvider.h"

#include <algorithm>
#include <cstdint>
#include <functional>

#include "../Repo/InstructionSetRepoFactory.h"
#include "../Types/HoverItem.h"
#include "../Types/Position.h"
#include "../Utils/DocumentUtil.h"
#include "../Utils/Logger.h"
#include "../Utils/StringUtil.h"

namespace ls6502
{

InstructionSet6502HoverProvider::InstructionSet6502HoverProvider()
    : m_instructionSetRepository(InstructionSetRepoFactory::create())
{
    m_instructionSet = m_instructionSetRepository->load();

    for (const auto &[instruction, _] : m_instructionSet)
    {
        LS_6502_DEBUG(STR("Loaded instruction: %s", instruction.c_str()));
    }
}

HoverItem InstructionSet6502HoverProvider::getHoverItem(const std::string &document, const Position &position)
{
    std::string instruction = DocumentUtil::extractPrefix(document, position);

    StringUtil::toUpper(instruction);

    LS_6502_DEBUG(STR("Hover items are requested for instruction: %s", instruction.c_str()));

    HoverItem hoverItem;

    InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

    if (it == m_instructionSet.end())
    {
        std::stringstream ss;
        ss << instruction << " isn't valid 6502 ASM instruction!";

        LS_6502_DEBUG(ss.str());

        hoverItem.text = ss.str();
    }
    else
    {
        Instruction instructionDetails = it->second;
        hoverItem.text = instructionDetails.toString();
    }

    return hoverItem;
}

} // namespace ls6502
