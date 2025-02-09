#include "AddressingModesUtil.h"

#include <unordered_map>

#include "../Enums/AddressingModes.h"
#include "../Utils/Logger.h"

namespace ls6052
{

AddressingMode AddressingModeUtil::stringToAddressingMode(const std::string &addressingMode)
{
    static const  StringAddressingModeMapT addressingModes = {
        {"Immediate", AddressingMode::IMMEDIATE},
        {"Zero Page,X", AddressingMode::ZERO_PAGE_X},
        {"Zero Page,Y", AddressingMode::ZERO_PAGE_Y},
        {"Absolute,X", AddressingMode::ABSOLUTE_X},
        {"Absolute,Y", AddressingMode::ABSOLUTE_Y},
        {"Indirect,X", AddressingMode::INDIRECT_X},
        {"Indirect,Y", AddressingMode::INDIRECT_Y}};

    StringAddressingModeMapT::const_iterator it = addressingModes.find(addressingMode);

    if (it == addressingModes.end())
    {
        LS_6502_WARN(STR("Unkknown addressing mode: %s", addressingMode.c_str()));
        return AddressingMode::INVALID;
    }

    return it->second;
}

const char *AddressingModeUtil::addressingModeToString(const AddressingMode addressingMode)
{
    static const AddressingModeStringMapT addressingModes = {
        {AddressingMode::IMMEDIATE, "Immediate"},
        {AddressingMode::ZERO_PAGE_X, "Zero Page,X"},
        {AddressingMode::ZERO_PAGE_Y, "Zero Page,Y"},
        {AddressingMode::ABSOLUTE_X, "Absolute,X"},
        {AddressingMode::ABSOLUTE_Y, "Absolute,Y"},
        {AddressingMode::INDIRECT_X, "Indirect,X"},
        {AddressingMode::INDIRECT_Y, "Indirect,Y"}};

    AddressingModeStringMapT::const_iterator it = addressingModes.find(addressingMode);

    if (it == addressingModes.end())
    {
        LS_6502_WARN("Unknown addressing mode");
        return "";
    }

    return it->second.c_str();
}

} // namespace ls6052
