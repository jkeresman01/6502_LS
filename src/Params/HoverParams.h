#pragma once

#include <nlohmann/json.hpp>

#include "TextDocumentPositionParams.h"

namespace ls6502
{
class HoverParams : public TextDocumentPositionParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the HoverParams object from JSON RPC
    ///
    /// @param [in] jsonRPC JSON object containing hover parameters
    ///
    //////////////////////////////////////////////////////////////
    explicit HoverParams(const nlohmann::json &jsonRPC) : TextDocumentPositionParams(jsonRPC){};
};

} // namespace ls6502
