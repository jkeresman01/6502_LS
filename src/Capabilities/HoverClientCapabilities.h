#pragma once

#include <nlohmann/json.hpp>
#include <vector>

#include "../Enums/MarkupKind.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class Message
///
/// @brief Capabilities specific to the `textDocument/hover` request.
///
//////////////////////////////////////////////////////////////
class HoverClientCapabilities
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the HoverClientCapabilities from jsonRPC request
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit HoverClientCapabilities(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Client supports the follow content formats if the content
    ///        roperty refers to a `literal of type MarkupContent`.
    ///        The order describes the preferred format of the client.
    ///
    //////////////////////////////////////////////////////////////
    std::vector<MarkupKind> m_contentFormats;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Whether hover supports dynamic registration.
    ///
    //////////////////////////////////////////////////////////////
    bool m_isDynamicRegistrationSupported;
};

} // namespace justanlsp
