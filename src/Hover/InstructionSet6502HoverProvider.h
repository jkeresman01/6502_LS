#pragma once

#include <memory>
#include <vector>

#include "../Repo/IInstructionSetRepository.h"
#include "../Types/Position.h"
#include "IHoverProvider.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// Typedefs
///
//////////////////////////////////////////////////////////////
typedef std::unordered_map<std::string, Instruction> InstructionSetMapT;

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
    InstructionSet6502HoverProvider();

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

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Repository for retrieving 6502 instruction set data.
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IInstructionSetRepository> m_instructionSetRepository;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A mapping of instruction mnemonics to their details.
    ///
    //////////////////////////////////////////////////////////////
    InstructionSetMapT m_instructionSet;
};
} // namespace ls6502
