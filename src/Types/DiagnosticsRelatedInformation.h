#pragma once

#include <string>

#include "Location.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @struct DiagnosticRelatedInformation
///
/// @Brief  Represents a related message and source code
///         location for a diagnostic. This should be used to
///         point to code locations that cause or are related \
///         to a diagnostics, e.g when duplicating a symbol in a scope.
///
//////////////////////////////////////////////////////////////
struct DiagnosticRelatedInformation
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The location of this related diagnostic information.
    ///
    //////////////////////////////////////////////////////////////
    Location location;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The message of this related diagnostic information.
    ///
    //////////////////////////////////////////////////////////////
    std::string message;
};

} // namespace justanlsp
