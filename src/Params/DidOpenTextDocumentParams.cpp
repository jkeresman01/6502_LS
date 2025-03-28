////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "DidOpenTextDocumentParams.h"

#include "../Utils/Logger.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
DidOpenTextDocumentParams::DidOpenTextDocumentParams(const nlohmann::json &jsonRPC)
{
    setTextDocumentItemKind(jsonRPC);
}

////////////////////////////////////////////////////////////
void DidOpenTextDocumentParams::setTextDocumentItemKind(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("textDocument");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No textDocument in textDocument/didOpen request");
        return;
    }

    m_textDocumentItem = std::make_shared<TextDocumentItem>(jsonRPC["textDocument"]);
}
} // namespace ls6502
