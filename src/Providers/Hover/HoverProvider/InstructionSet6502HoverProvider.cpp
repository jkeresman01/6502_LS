////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "InstructionSet6502HoverProvider.h"

#include "../../Manager/Instructions/InstructionSetManager.h"
#include "../../Repo/Instructions/FactoryImpl/InstructionSetRepoFactory.h"
#include "../../Types/HoverItem.h"
#include "../../Types/Position.h"
#include "../../Utils/DocumentUtil.h"
#include "../../Utils/Logger.h"
#include "../../Utils/StringUtil.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
HoverItem InstructionSet6502HoverProvider::getHoverItem(const std::string& document, const Position& position)
{
    std::string mnemonic = DocumentUtil::extractPrefix(document, position);

    StringUtil::toUpper(mnemonic);

    LS_6502_DEBUG(STR("Hover item is requested for mnemonic: %s", mnemonic.c_str()));

    HoverItem hoverItem;

    if (auto it = InstructionSetManager::getInstance().getInstructionByMnemonic(mnemonic))
    {
        hoverItem.text = it->toString();
        return hoverItem;
    }

    std::string invalidInstructionStr = STR("%s isn't valid 6502 ASM instruction!", mnemonic.c_str());

    LS_6502_DEBUG(invalidInstructionStr);

    hoverItem.text = invalidInstructionStr;

    return hoverItem;
}


} // namespace ls6502
