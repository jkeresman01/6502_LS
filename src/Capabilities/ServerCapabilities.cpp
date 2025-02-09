#include "ServerCapabilities.h"

namespace justanlsp
{

ServerCapabilities::ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind,
                                       bool areSnippetsSupported, bool isHoverSupported,
                                       bool areComletionsSupported, bool areCodeActionsSupported,
                                       bool areDefintionsSupported)
    : m_textDocumentSyncKind(textDocumentSyncKind), m_areSnippetsSupported(areSnippetsSupported),
      m_areCompletionsSupported(areSnippetsSupported), m_isHoverSupported(isHoverSupported),
      m_areCodeActionsSupported(areCodeActionsSupported), m_areDefinitionsSupported(areSnippetsSupported)
{
}

nlohmann::json ServerCapabilities::toJson() const
{
    return {{"textDocumentSync", m_textDocumentSyncKind},
            {"completionProvider", "{}"},
            {"hoverProvider", true},
            {"codeActionProvider", true},
            {"definitionProvider", true}};
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withTextDocumentSyncKind(
    const TextDocumentSyncKind &textDocuemntSyncKind)
{
    m_textDocumentSyncKind = textDocuemntSyncKind;
    return *this;
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withSnippetSupport(bool areSnippetsSupported)
{
    m_areSnippetsSupported = areSnippetsSupported;
    return *this;
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withHoverSupport(bool isHoverSupported)
{
    m_isHoverSupported = isHoverSupported;
    return *this;
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withCompletionSupport(bool areCompletionsSupported)
{
    m_areCompletionsSupported = areCompletionsSupported;
    return *this;
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withCodeActionSupport(bool areCodeActionsSupported)
{
    m_areCodeActionsSupported = areCodeActionsSupported;
    return *this;
}

ServerCapabilities::Builder &ServerCapabilities::Builder::withDefinitionSupport(bool areDefintionsSupported)
{
    m_areDefinitionsSupported = areDefintionsSupported;
    return *this;
}

ServerCapabilities ServerCapabilities::Builder::build() const
{
    return ServerCapabilities(m_textDocumentSyncKind, m_areSnippetsSupported, m_isHoverSupported,
                              m_areCompletionsSupported, m_areCodeActionsSupported,
                              m_areDefinitionsSupported);
}

} // namespace justanlsp
