#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace justanlsp
{
class HoverParams : public TextDocumentPositionParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the HoverParams object from JSON RPC
    ///
    /// @param jsonRPC JSON object containing hover parameters
    ///
    //////////////////////////////////////////////////////////////
    explicit HoverParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace justanlsp
