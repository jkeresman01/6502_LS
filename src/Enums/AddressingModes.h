#pragma once

namespace ls6052
{
// TODO finish documention

//////////////////////////////////////////////////////////////
///
/// @enum AddressingMode
///
/// @brief Addressing modes implemented by the 6502 processor
///
//////////////////////////////////////////////////////////////
enum class AddressingMode
{
    ZERO_PAGE_X,
    ZERO_PAGE_Y,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief In immediate addressing, the operand value immediatly
    ///        follows the opcode in memmory
    ///
    //////////////////////////////////////////////////////////////
    IMMEDIATE,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief In absoule (direct) addressing, we specify the the
    ///        memmory location containg the value to be read or
    ///        written by the instruction
    ///
    //////////////////////////////////////////////////////////////
    ABSOLUTE_X,
    ABSOLUTE_Y,

    INDIRECT_X,
    INDIRECT_Y,

    INVALID,
};
} // namespace ls6052
