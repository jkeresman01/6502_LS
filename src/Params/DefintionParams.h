#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
{
class DefinitionParams : public TextDocumentPositionParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the DefinitionParams object from JSON RPC
    ///
    /// @param jsonRPC JSON object containing definition parameters
    ///
    //////////////////////////////////////////////////////////////
    explicit DefinitionParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace justanlsp
