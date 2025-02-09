#include "CompletionItem.h"

namespace justanlsp
{

CompletionItem::CompletionItem(const std::string &label, const CompletionItemKind completionItemKind,
                               const std::string &detail, const std::string &documentation,
                               const std::string &insertedText)
    : m_label(label), m_detail(detail), m_documentation(documentation){};

CompletionItem::Builder &CompletionItem::Builder::withLabel(const std::string &label)
{
    m_label = label;
    return *this;
}

CompletionItem::Builder &CompletionItem::Builder::withDetail(const std::string detail)
{
    m_detail = detail;
    return *this;
}

CompletionItem::Builder &CompletionItem::Builder::withInsertedText(const std::string &insertedText)
{
    m_insertedText = insertedText;
    return *this;
}

CompletionItem::Builder &CompletionItem::Builder::withDocumentation(const std::string &documentation)
{
    m_documentation = documentation;
    return *this;
}

CompletionItem::Builder &CompletionItem::Builder::withCompletionItemKind(
    const CompletionItemKind &completionItemKind)
{
    m_completionItemKind = completionItemKind;
    return *this;
}

nlohmann::json CompletionItem::toJson() const
{
    return {{"label", m_label},
            {"detail", m_detail},
            {"insertText", m_insertText},
            {"kind", m_completionItemKind},
            {"documentation", m_documentation}};
}
}; // namespace justanlsp
