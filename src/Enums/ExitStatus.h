#pragma once

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @enum ExitStatus
///
/// @brief Describes the status with which Ls6502 Server exited
///
///
//////////////////////////////////////////////////////////////
enum ExitStatus
{

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Successfull shutdown of Ls6502Server
    ///
    //////////////////////////////////////////////////////////////
    SUCCESS = 0,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Unsuccessfull shutdown of Ls6502Server
    ///
    //////////////////////////////////////////////////////////////
    FAILURE = 1,
};
} // namespace ls6502
