#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace ls6502
{
class DefinitionParams : public TextDocumentPositionParams
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the DefinitionParams object from JSON RPC
    ///
    /// @param [in] jsonRPC JSON object containing definition parameters
    ///
    //////////////////////////////////////////////////////////////
    explicit DefinitionParams(const nlohmann::json& jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace ls6502
