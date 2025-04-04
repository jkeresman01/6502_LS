#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../../Types/Location.h"
#include "../IDefinitionProvider.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class DefinitionProvider
///
/// @brief Provides the location of a definition in the source code
///        based on a given document and position.
///
//////////////////////////////////////////////////////////////
class DefinitionProvider : public IDefinitionProvider
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Provides the location of a definition
    ///
    /// @param [in] document
    /// @param [in] position
    /// @param [in] URI
    ///
    /// @return The location of the definition, including
    ///         line and column information.
    ///
    //////////////////////////////////////////////////////////////
    virtual Location provideDefinitionLocation(const std::string& document,
                                               const Position&    position,
                                               const std::string& URI) override;
};
} // namespace ls6502
