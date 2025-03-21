#pragma once

#include <string>

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @struct HoverItem
///
/// @brief Represents a hover item that contains text information
///        to be displayed when hovering over a specific position
///        in a document.
///
//////////////////////////////////////////////////////////////
struct HoverItem
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The text content of the hover item.
    ///
    //////////////////////////////////////////////////////////////
    std::string text;
};
} // namespace ls6502
