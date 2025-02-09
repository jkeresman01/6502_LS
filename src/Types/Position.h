#pragma once

#include <cstdint>
#include <sstream>
#include <string>

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct Position
///
/// @brief Position in a text document expressed as zero-based
///        line and zero-based character offset
///
//////////////////////////////////////////////////////////////
struct Position
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Line position in a document (zero-based).
    ///
    //////////////////////////////////////////////////////////////
    uint64_t line;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Character offset on a line in a document (zero-based).
    ///
    //////////////////////////////////////////////////////////////
    uint64_t character;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the Position to JSON format
    ///
    /// @return Text document position in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const { return {{"line", line}, {"character", character}}; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts Postion to it's string representation
    ///
    /// @return String representation of postion
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        std::stringstream ss;

        ss << "Line: " << line << "\r\n";
        ss << "Character: " << character << "\r\n";

        return ss.str();
    }
};
} // namespace justanlsp
