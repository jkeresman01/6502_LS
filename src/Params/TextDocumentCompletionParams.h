#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
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
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentCompletionParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace justanlsp
