#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class XMLUtil
///
/// @brief Utility class for converting stuff
///
/////////////////////////////////////////////////////////////////////
class XMLUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    XMLUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Parse xml property from line in XML file
    ///
    /// @param [in] line from XML file
    ///
    /////////////////////////////////////////////////////////////////////
    static std::pair<std::string, std::string> parseFromFileLine(const std::string &line);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validate if XML line is valid
    ///
    /// @param [in] line from XML file
    ///
    /// @return true if is valid XML line
    ///
    /////////////////////////////////////////////////////////////////////
    static bool isValidXMLLine(const std::string_view &line);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Trims line from XML file
    ///
    /// @param [in] line from XML file
    ///
    /// @return trimed line
    ///
    /////////////////////////////////////////////////////////////////////
    std::string trim(const std::string &line);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validates if line from XML file is valid property line
    ///
    /// @param [in] true if line is valid property line
    ///
    /// @return true if is valid propery
    ///
    /////////////////////////////////////////////////////////////////////
    bool isValidPropertyXMLLine(const std::string &line);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
std::pair<std::string, std::string> inline XMLUtil::parseFromFileLine(const std::string &line)
{
    size_t nameStart = line.find("name=\"") + 6;
    size_t nameEnd = line.find("\"", nameStart);

    size_t valueStart = line.find(">", nameEnd) + 1;
    size_t valueEnd = line.find("</property>", valueStart);

    bool hasName = nameStart != std::string::npos and nameEnd != std::string::npos;
    bool hasValue = valueStart != std::string::npos and valueEnd != std::string::npos;

    std::pair<std::string, std::string> property;

    if (hasName and hasValue)
    {
        std::string propertyName = line.substr(nameStart, nameEnd - nameStart);
        std::string propertyValue = line.substr(valueStart, valueEnd - valueStart);

        property = std::make_pair(propertyName, propertyValue);
    }

    return property;
}

////////////////////////////////////////////////////////////
bool inline XMLUtil::isValidXMLLine(const std::string_view &line)
{
    bool hasCorrectStartPropertyTag = line.find("<property") != std::string::npos;
    bool hasCorrectStartEndPropertyTag = line.find("</property>") != std::string::npos;

    return hasCorrectStartPropertyTag and hasCorrectStartEndPropertyTag;
}

////////////////////////////////////////////////////////////
std::string inline XMLUtil::trim(const std::string &line)
{
    size_t start = line.find_first_not_of(" \t\n\r");
    size_t end = line.find_last_not_of(" \t\n\r");

    bool isAllWhitespaceLine = start or end;

    return isAllWhitespaceLine ? "" : line.substr(start, end - start + 1);
}

} // namespace ls6502
