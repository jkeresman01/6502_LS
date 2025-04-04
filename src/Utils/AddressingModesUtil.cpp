////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "AddressingModesUtil.h"
#include <unordered_map>

#include "../Enums/AddressingModes.h"
#include "../Utils/Logger.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
AddressingModes AddressingModeUtil::stringToAddressingMode(const std::string &addressingMode)
{
    static const StringAddressingModeMapT addressingModes
      = {{"Immediate", AddressingModes::IMMEDIATE},     {"Zero Page,X", AddressingModes::ZERO_PAGE_X},
         {"Zero Page,Y", AddressingModes::ZERO_PAGE_Y}, {"Absolute,X", AddressingModes::ABSOLUTE_X},
         {"Absolute,Y", AddressingModes::ABSOLUTE_Y},   {"Indirect", AddressingModes::INDIRECT_INDEXED}};

    StringAddressingModeMapT::const_iterator it = addressingModes.find(addressingMode);

    if (it == addressingModes.end())
    {
        LS_6502_WARN(STR("Unknown addressing mode: %s", addressingMode.c_str()));
        return AddressingModes::INVALID;
    }

    return it->second;
}

////////////////////////////////////////////////////////////
const char *AddressingModeUtil::addressingModeToString(const AddressingModes addressingMode)
{
    static const AddressingModeStringMapT addressingModes
      = {{AddressingModes::IMMEDIATE, "Immediate"},     {AddressingModes::ZERO_PAGE_X, "Zero Page,X"},
         {AddressingModes::ZERO_PAGE_Y, "Zero Page,Y"}, {AddressingModes::ABSOLUTE_X, "Absolute,X"},
         {AddressingModes::ABSOLUTE_Y, "Absolute,Y"},   {AddressingModes::INDIRECT_INDEXED, "Indirect"}};

    AddressingModeStringMapT::const_iterator it = addressingModes.find(addressingMode);

    if (it == addressingModes.end())
    {
        LS_6502_WARN("Unknown addressing mode");
        return "";
    }

    return it->second.c_str();
}

} // namespace ls6502
