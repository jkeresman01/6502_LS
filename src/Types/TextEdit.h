#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "Range.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class TextEdit
///
/// @brief Represents a text edit operation applied to a range in a document.
///
//////////////////////////////////////////////////////////////
class TextEdit
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a TextEdit with a specified range and new text.
    ///
    /// @param range
    /// @param newText
    ///
    //////////////////////////////////////////////////////////////
    TextEdit(const Range &range, const std::string &newText) : m_range(range), m_newText(newText){};

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the TextEdit to a JSON representation.
    ///
    /// @return A JSON object representing the TextEdit.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const { return {{"range", m_range.toJson()}, {"newText", m_newText}}; };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the TextEdit to a string representation.
    ///
    /// @return A string representation of the TextEdit.
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        std::stringstream ss;
        ss << "Range: " << m_range.toString() << "\r\n";
        ss << "TextEdit: " << m_newText << "\r\n";
        return ss.str();
    }

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range where the edit is applied.
    ///
    //////////////////////////////////////////////////////////////
    Range m_range;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The new text replacing the range.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_newText;
};

} // namespace justanlsp
