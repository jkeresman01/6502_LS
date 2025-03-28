////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "DidOpenTextDocumentRequest.h"

#include "../Utils/Logger.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
DidOpenTextDocumentRequest::DidOpenTextDocumentRequest(const nlohmann::json &jsonRPC)
    : NotificationMessage(jsonRPC)
{
    setParams(jsonRPC);
}

////////////////////////////////////////////////////////////
void DidOpenTextDocumentRequest::setParams(const nlohmann::json &jsonRPC)
{
    auto it = jsonRPC.find("params");

    if (it == jsonRPC.end())
    {
        LS_6502_ERROR("No textDocumentDidChange params in textDocument/DidChange request");
        return;
    }

    m_params = std::make_shared<DidOpenTextDocumentParams>(jsonRPC["params"]);
}

} // namespace ls6502
