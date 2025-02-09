#pragma once

#include <string>

namespace justanlsp
{

/////////////////////////////////////////////////////////////////////
///
/// @class Converter
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
    /// @param line from XML file
    ///
    /////////////////////////////////////////////////////////////////////
    static std::pair<std::string, std::string> parseFromFileLine(const std::string &line);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validate if XML line is valid
    ///
    /// @param line from XML file
    ///
    /////////////////////////////////////////////////////////////////////
    static bool isValidXMLLine(const std::string_view &line);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Trims line from XML file
    ///
    /// @param line from XML file
    ///
    /////////////////////////////////////////////////////////////////////
    std::string trim(const std::string &line);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Validates if line from XML file is valid property line
    ///
    /// @param true if line is valid property line
    ///
    /////////////////////////////////////////////////////////////////////
    bool isValidPropertyXMLLine(const std::string &line);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

std::pair<std::string, std::string> inline XMLUtil::parseFromFileLine(const std::string &line)
{
    size_t nameStart = line.find("name=\"") + 6;
    size_t nameEnd = line.find("\"", nameStart);

    size_t valueStart = line.find(">", nameEnd) + 1;
    size_t valueEnd = line.find("</property>", valueStart);

    bool hasPropertyName = nameStart != std::string::npos and nameEnd != std::string::npos;
    bool hasPropertyValue = valueStart != std::string::npos && valueEnd != std::string::npos;

    std::pair<std::string, std::string> property;

    if (hasPropertyName and hasPropertyValue)
    {
        std::string propertyName = line.substr(nameStart, nameEnd - nameStart);
        std::string propertyValue = line.substr(valueStart, valueEnd - valueStart);

        property = std::make_pair(propertyName, propertyValue);
    }

    return property;
}

bool inline XMLUtil::isValidXMLLine(const std::string_view &line)
{
    return line.find("<property") != std::string::npos and line.find("</property>") != std::string::npos;
}

std::string inline XMLUtil::trim(const std::string &line)
{
    size_t start = line.find_first_not_of(" \t\n\r");
    size_t end = line.find_last_not_of(" \t\n\r");

    bool isAllWhitespaceLine = start or end;

    return isAllWhitespaceLine ? "" : line.substr(start, end - start + 1);
}

} // namespace justanlsp
