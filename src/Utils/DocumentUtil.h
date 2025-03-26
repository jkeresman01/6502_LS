#pragma once

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "../Types/Position.h"
#include "../Utils/Logger.h"

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class DocumentUtil
///
/// @brief Utility class for handling document-related operations
///
/////////////////////////////////////////////////////////////////////
class DocumentUtil
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Delete default constructor to prevent instantiation
    ///
    /////////////////////////////////////////////////////////////////////
    DocumentUtil() = delete;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Extract the word under the cursor at the given position.
    //
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return The extracted word under the cursor.
    ///         Returns an empty string if no valid word is found
    ///         at the given position.
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string extractPrefix(const std::string &document, const Position &position);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Splits the given document into a vector of lines.
    //
    /// @param [in] document
    ///
    /// @return A vector containing individual lines.
    ///
    /////////////////////////////////////////////////////////////////////
    static std::vector<std::string> splitDocumentIntoLines(const std::string &document);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Extract the word under the cursor at the given position.
    //
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return Extracted line from the file
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string extractLine(const std::string &document, const Position &position);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Find start position of the word in line
    //
    /// @param [in] line
    /// @param [in] position
    ///
    /// @return words start position
    ///
    /////////////////////////////////////////////////////////////////////
    static size_t findStartOfTheWord(const std::string &line, const Position &position);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Find end position of the word in line
    //
    /// @param [in] line
    /// @param [in] position
    ///
    /// @return words end position
    ///
    /////////////////////////////////////////////////////////////////////
    static size_t findEndOfTheWord(const std::string &line, const Position &position);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

std::vector<std::string> inline DocumentUtil::splitDocumentIntoLines(const std::string &document)
{
    std::vector<std::string> lines;
    std::stringstream ss(document);
    std::string line;

    while (std::getline(ss, line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::string inline DocumentUtil::extractPrefix(const std::string &document, const Position &position)
{
    const std::string &line = extractLine(document, position);

    bool isValidPosition = position.character < line.size();

    if (!isValidPosition)
    {
        LS_6502_WARN(STR("Invalid position, when trying to extract prefix, at line %zu, character %zu:",
                         position.line, position.character));
        return std::string();
    }

    size_t start = findStartOfTheWord(line, position);
    size_t end = findEndOfTheWord(line, position);

    std::string word = line.substr(start, end - start);

    LS_6502_DEBUG(STR("Extracted word \"%s\" from document at line %zu, character %zu", word.c_str(),
                      position.line, position.character));

    return word;
}

std::string inline DocumentUtil::extractLine(const std::string &document, const Position &position)
{
    std::stringstream ss(document);
    std::string line;

    for (size_t i = 0; i <= position.line; ++i)
    {
        if (!getline(ss, line))
        {
            line = "";
        }
    }

    return line;
}

size_t inline DocumentUtil::findStartOfTheWord(const std::string &line, const Position &position)
{
    size_t start = position.character;

    while (start > 0 and std::isalnum(line[start - 1]))
    {
        --start;
    }

    return start;
}

size_t inline DocumentUtil::findEndOfTheWord(const std::string &line, const Position &position)
{
    size_t end = position.character;

    while (end < line.size() and std::isalnum(line[end]))
    {
        ++end;
    }

    return end;
}

} // namespace ls6502
