#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>
#include <string>

#include "../IProvider.h"
#include "../Types/CodeAction.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ICodeActionsProvider
///
/// @brief Interface for providing code actions in response to
///        a given document URI.
///
//////////////////////////////////////////////////////////////
class ICodeActionsProvider : public IProvider
{
public:
	//////////////////////////////////////////////////////////////
	///
	/// @brief Virtual destructor to ensure proper cleanup of derived classes.
	///
	//////////////////////////////////////////////////////////////
    virtual ~ICodeActionsProvider() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Pure virtual function to retrieve code actions for
    ///        a specified document.
    ///
    /// @param [in] URI
    ///
    /// @return A vector of CodeAction objects representing the
    ///         available code actions for the document.
    ///
    //////////////////////////////////////////////////////////////
    virtual std::vector<CodeAction> getCodeActions(const std::string& document, const std::string& URI) = 0;
};

} // namespace ls6502
