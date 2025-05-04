#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../IProvider.h"
#include "../Types/Location.h"
#include "../Types/Position.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @interface IDefinitionProvider
///
/// @brief Provides an interface for locating a definition
///        in a source code document.
///
//////////////////////////////////////////////////////////////
class IDefinitionProvider : public IProvider
{
public:
	//////////////////////////////////////////////////////////////
	///
	/// @brief Virtual destructor to ensure proper cleanup of derived classes.
	///
	//////////////////////////////////////////////////////////////
    virtual ~IDefinitionProvider() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Locates the definition of a symbol under the cursor
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
                                               const std::string& URI) = 0;
};
} // namespace ls6502
