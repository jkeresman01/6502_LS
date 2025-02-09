#include "Diagnostic.h"

namespace justanlsp
{
Diagnostic::Diagnostic(const Range &range, const DiagnosticSeverity &severity, const std::string &source,
                       const std::string &message)
    : m_range(range), m_severity(severity), m_source(source), m_message(message)
{
}

nlohmann::json Diagnostic::toJson() const
{
    return {
        {"range", m_range.toJson()}, {"severity", m_severity}, {"source", m_source}, {"message", m_message}};
}

} // namespace justanlsp
