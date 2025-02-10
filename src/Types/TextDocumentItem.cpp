#include "TextDocumentItem.h"

#include "../Utils/Logger.h"

namespace ls6502
{
TextDocumentItem::TextDocumentItem(const nlohmann::json &jsonRPC)
{
    setURI(jsonRPC);
    setLanguageId(jsonRPC);
    setTextVersion(jsonRPC);
    setText(jsonRPC);
}

void TextDocumentItem::setURI(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No URI in textDocumentItemKind");
        return;
    }

    m_URI = jsonRPC["uri"];
}

void TextDocumentItem::setLanguageId(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("languageId");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No languageId in textDocumentItemKind");
        return;
    }

    m_languageId = jsonRPC["languageId"];
}

void TextDocumentItem::setTextVersion(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("version");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No version in textDocumentItemKind");
        return;
    }

    m_version = jsonRPC["version"];
}

void TextDocumentItem::setText(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("text");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No text in textDocumentItemKind");
        return;
    }

    m_text = jsonRPC["text"];
}
} // namespace ls6502
