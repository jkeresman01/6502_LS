////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "HoverClientCapabilities.h"

namespace ls6502
{


//////////////////////////////////////////////////////////////
HoverClientCapabilities::HoverClientCapabilities(const nlohmann::json& jsonRPC) :
m_isDynamicRegistrationSupported(false)
{
    m_contentFormats.reserve(static_cast<size_t>(MarkupKind::OPTIONS_NO));

    // TODO get contentForrmat from request and dynamic reg options
}


} // namespace ls6502
