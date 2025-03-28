#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>

#include "../Types/HoverItem.h"
#include "../Types/Position.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class IHoverProvider
///
/// @brief An interface for providing hover items based on
///        document content and position.
///
//////////////////////////////////////////////////////////////
class IHoverProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a hover item for a given document
    ///        and position.
    ///
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return A HoverItem representing hover information.
    ///
    //////////////////////////////////////////////////////////////
    virtual HoverItem getHoverItem(const std::string &document, const Position &position) = 0;
};
} // namespace ls6502
