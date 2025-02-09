#include "PublishDiagnosticsParams.h"

namespace justanlsp
{

PublishDiagnosticsParams::PublishDiagnosticsParams(const std::string &URI,
                                                   const std::vector<Diagnostic> &diagnostics)
    : m_URI(URI), m_diagnostics(diagnostics){};

nlohmann::json PublishDiagnosticsParams::toJson() const
{
    return {
        {"uri", m_URI},
        {"diagnostics", dianosticItemsToJson()},
    };
}

nlohmann::json PublishDiagnosticsParams::dianosticItemsToJson() const
{
    std::vector<nlohmann::json> diagnostics(m_diagnostics.size());

    for (size_t i = 0; i < diagnostics.size(); ++i)
    {
        diagnostics[i] = m_diagnostics[i].toJson();
    }

    return diagnostics;
}

} // namespace justanlsp
