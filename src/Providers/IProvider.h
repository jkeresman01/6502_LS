#pragma once

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class IProvider
///
/// @brief Semantic interface for different providers
///
//////////////////////////////////////////////////////////////
class IProvider
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Virtual destructor to ensure proper cleanup of derived classes.
    ///
    //////////////////////////////////////////////////////////////
    virtual ~IProvider() = default;
};
} // namespace ls6502