#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class TextDocumentCompletionParams
///
/// @brief Represents parameters for a completion request in the
///        language server protocol
///
//////////////////////////////////////////////////////////////
class TextDocumentCompletionParams : public TextDocumentPositionParams
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs TextDocumentCompletionParams from a JSON RPC request.
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentCompletionParams(const nlohmann::json& jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace ls6502
