////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "CodeActionResult.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
nlohmann::json CodeActionResult::toJson() const
{
    nlohmann::json json = nlohmann::json::array();

    for (const auto& codeAction : m_codeActions)
    {
        json.push_back(codeAction.toJson());
    }

    return json;
}


} // namespace ls6502
