#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <regex>

#include "../Types/Position.h"
#include "../Utils/Logger.h"

namespace ls6502
{
class DefinitionUtil
{
public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    DefinitionUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Extracts position of the given label in a given document
    ///
    /// @param [in] label
    /// @param [in] document
    ///
    /// @return position
    ///
    /////////////////////////////////////////////////////////////////////
    static Position& findLabelPosition(const std::string& label, const std::string& document);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
inline Position& DefinitionUtil::findLabelPosition(const std::string& label, const std::string& document)
{
    std::regex  labelPattern("\\b" + label + "\\b");
    std::smatch match;

    std::stringstream ss(document);

    std::string line;
    uint32_t    lineNumber = 0;
    Position    definitionPosition;

    while (std::getline(ss, line))
    {
        bool isLabelMatched = std::regex_search(line, match, labelPattern);

        if (isLabelMatched)
        {
            definitionPosition = {lineNumber, static_cast<uint32_t>(match.position())};
            LS_6502_DEBUG(STR("Found label definition at line: %d, column: %d",
                              definitionPosition.line,
                              definitionPosition.character));
            break;
        }

        lineNumber++;
    }
}


} // namespace ls6502
