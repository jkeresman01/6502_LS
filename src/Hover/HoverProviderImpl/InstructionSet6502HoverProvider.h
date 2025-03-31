#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <vector>

#include "../../Repo/Instructions/IInstructionSetRepository.h"
#include "../../Types/Position.h"
#include "../IHoverProvider.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class InstructionSet6502HoverProvider
///
/// @brief Provides hover information based on the 6502
///        instruction set.
///
//////////////////////////////////////////////////////////////
class InstructionSet6502HoverProvider : public IHoverProvider
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructor.
    ///
    //////////////////////////////////////////////////////////////
    InstructionSet6502HoverProvider() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves a hover item based on the given document
    ///        and position.
    ///
    /// @param [in] document
    /// @param [in] position
    ///
    /// @return A HoverItem representing the hover information.
    ///
    //////////////////////////////////////////////////////////////
    HoverItem getHoverItem(const std::string &document, const Position &position) override;
};
} // namespace ls6502
