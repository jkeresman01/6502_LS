#include "InstructionSet6502HoverProvider.h"

#include "../Types/HoverItem.h"
#include "../Types/Position.h"

#include "../Utils/DocumentUtil.h"
#include "../Repo/InstructionSetRepoFactory.h"

namespace ls6502
{

    InstructionSet6502HoverProvider::InstructionSet6502HoverProvider()
        : m_instructionSetRepository(IInstructionSetRepoFactory::create())
    {
        m_instructionSet = m_instructionSetRepository->load();
    }

    HoverItem InstructionSet6502HoverProvider::getHoverItems(const std::string &document, const Position &position)
    {
        std::string instruction = DocumentUtil::extractPrefix(document, position);

        LS_6502_DEBUG(STR("Hover items are requested for instruction: %s", instruction.c_str()));

        InstructionSetMapT::iterator it = m_instructionSet.find(instruction);

        if(it == m_instructionSet.end())
        {
            LS_6502_DEBUG(STR("Following instruction isn't supporeted: %s", instruction.c_str()));
            return {};
        }

        Instruction instructionDetails = it->second;

        HoverItem hoverItem;
        hoverItem.text = instructionDetails.toString();

        return hoverItem;
    }

} // namespace ls6502
