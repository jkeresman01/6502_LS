#pragma once

#include <cctype>
#include <sstream>
#include <string>

#include "../Types/Position.h"
#include "../Utils/Logger.h"

namespace ls6052
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
    /// @param document
    /// @param position
    ///
    /// @return The extracted word under the cursor.
    ///         Returns an empty string if no valid word is found
    ///         at the given position.
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string extractPrefix(const std::string &document, const Position &position);

  private:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Extract the word under the cursor at the given position.
    //
    /// @param document
    /// @param position
    ///
    /// @return Extracted line from the file
    ///
    /////////////////////////////////////////////////////////////////////
    static std::string extractLine(const std::string &document, const Position &position);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Find start position of the word in line
    //
    /// @param line
    /// @param position
    ///
    /// @return words start position
    ///
    /////////////////////////////////////////////////////////////////////
    static size_t findStartOfTheWord(const std::string &line, const Position &position);

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Find end position of the word in line
    //
    /// @param line
    /// @param position
    ///
    /// @return words end position
    ///
    /////////////////////////////////////////////////////////////////////
    static size_t findEndOfTheWord(const std::string &line, const Position &position);
};

/////////////////////////////////////////////////////////////////////
/// Implementation of inline defined functions
/////////////////////////////////////////////////////////////////////

inline std::string DocumentUtil::extractPrefix(const std::string &document, const Position &position)
{
    std::string line = extractLine(document, position);

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

static size_t findStartOfTheWord(const std::string &line, const Position &position)
{
    size_t start = position.character;

    while (start > 0 && std::isalnum(line[start - 1]))
    {
        --start;
    }

    return start;
}

static size_t findEndOfTheWord(const std::string &line, const Position &position)
{
    size_t end = position.character;

    while (end < line.size() && std::isalnum(line[end]))
    {
        ++end;
    }

    return end;
}

} // namespace ls6052
