#pragma once

#include <nlohmann/json.hpp>
#include <sstream>

#include "Position.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct Range
///
/// @brief A range in a text document expressed as (zero-based)
///        start and end positions. A range is comparable to a
///        selection in an editor. Therefore, the end position
///        is exclusive
///
//////////////////////////////////////////////////////////////
struct Range
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range's start positon
    ///
    //////////////////////////////////////////////////////////////
    Position start;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The range's end positon
    ///
    //////////////////////////////////////////////////////////////
    Position end;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the Range to JSON format
    ///
    /// @return Range in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const
    {
        return {
            {"start", start.toJson()},
            {"end", end.toJson()},
        };
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @return String representation of Range type
    ///
    /// @return string representation of Range type
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const
    {
        std::stringstream ss;

        ss << "Start: " << start.toString() << "\r\n";
        ss << "End: " << end.toString() << "\r\n";

        return ss.str();
    }
};
} // namespace justanlsp
