#include "CodeActionResult.h"

namespace justanlsp
{
nlohmann::json CodeActionResult::toJson() const
{
    nlohmann::json json = nlohmann::json::array();

    for (const auto &codeAction : m_codeActions)
    {
        json.push_back(codeAction.toJson());
    }

    return json;
}
} // namespace justanlsp
