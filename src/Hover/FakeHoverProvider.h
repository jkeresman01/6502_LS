#pragma once

#include "IHoverProvider.h"

#include <string>

namespace ls6502
{

/////////////////////////////////////////////////////////////////////
///
/// @class FakeHoverProvider
///
/// @brief A mock implementation of the IHoverProvider interface
///
/////////////////////////////////////////////////////////////////////
class FakeHoverProvider : public IHoverProvider
{
  public:
    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor
    ///
    /////////////////////////////////////////////////////////////////////
    FakeHoverProvider() = default;

    /////////////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves hover information for a given document position
    ///
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return A HoverItem containing hover information
    ///
    /////////////////////////////////////////////////////////////////////
    HoverItem getHoverItem(const std::string &document, const Position &position) override;
};

} // namespace ls6502
