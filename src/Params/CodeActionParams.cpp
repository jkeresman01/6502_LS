#include "CodeActionParams.h"

#include "../Utils/Logger.h"

namespace ls6052
{
CodeActionParams::CodeActionParams(const nlohmann::json &jsonRPC)
{
    setRange(jsonRPC);
    setURI(jsonRPC["textDocument"]);
    // TODO reset of the params
}

void CodeActionParams::setRange(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("range");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No range in textDocument/codeAction request");
        return;
    }

    nlohmann::json range = jsonRPC["range"];

    setStartPosition(range["start"]);
    setEndPosition(range["end"]);
}

void CodeActionParams::setStartPosition(const nlohmann::json &jsonRPC)
{
    m_range.start.line = jsonRPC["line"];
    m_range.start.character = jsonRPC["character"];
}

void CodeActionParams::setEndPosition(const nlohmann::json &jsonRPC)
{
    m_range.end.line = jsonRPC["line"];
    m_range.end.character = jsonRPC["character"];
}

void CodeActionParams::setURI(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("uri");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No document URI in textDocument/codeAction request");
        return;
    }

    m_URI = jsonRPC["uri"];
}
} // namespace ls6052
