#include "CodeAction.h"

#include <string>

namespace justanlsp
{

CodeAction::CodeAction(const std::string &title, const CodeActionKind &codeActionKind, const bool isPreffered,
                       const WorkspaceEdit &edit)
    : m_title(title), m_codeActionKind(codeActionKind), m_isPreffered(isPreffered), m_workspaceEdit(edit){};

std::string CodeAction::toString() const
{
    std::stringstream ss;

    ss << "Title: " << m_title << "\r\n";
    ss << "Kind: " << static_cast<uint32_t>(m_codeActionKind) << "\r\n";
    ss << "Is preffered: " << (m_isPreffered ? "YES" : "NO") << "\r\n";
    ss << "Edit: " << m_workspaceEdit.toString() << "\r\n";

    return ss.str();
}

nlohmann::json CodeAction::toJson() const
{
    nlohmann::json json;

    json["title"] = m_title;
    json["kind"] = m_codeActionKind;
    json["isPreffered"] = m_isPreffered;
    json["edit"] = m_workspaceEdit.toJson();

    return json;
}

CodeAction::Builder &CodeAction::Builder::withTitle(const std::string &title)
{
    m_title = title;
    return *this;
}

CodeAction::Builder &CodeAction::Builder::withCodeActionKind(const CodeActionKind &codeActionKind)
{
    m_codeActionKind = codeActionKind;
    return *this;
}

CodeAction::Builder &CodeAction::Builder::withPrefferedFix(bool isPreffered)
{
    m_isPreffered = isPreffered;
    return *this;
}

CodeAction::Builder &CodeAction::Builder::withWorkspaceEdit(const WorkspaceEdit &workspaceEdit)
{
    m_workspaceEdit = workspaceEdit;
    return *this;
}

CodeAction CodeAction::Builder::build()
{
    return CodeAction(m_title, m_codeActionKind, m_isPreffered, m_workspaceEdit);
}
} // namespace justanlsp
