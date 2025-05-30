#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @struct CodeDescription
///
/// @brief Structure to capture a description for an error code.
///
//////////////////////////////////////////////////////////////
struct CodeDescription
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief An URI to open with more information about the diagnostic error.
    ///
    //////////////////////////////////////////////////////////////
    std::string URI;
};
} // namespace ls6502
