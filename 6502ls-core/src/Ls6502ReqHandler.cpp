////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <vector>

#include "ls6502/core/Ls6502ReqHandler.h"

#include "ls6502/lsp/capabilities/server/ServerCapabilities.h"
#include "ls6502/lsp/capabilities/server/ServerCapabilitiesDirector.h"

#include "ls6502/lsp/codeactions/CodeActionsProviderFactory.h"
#include "ls6502/lsp/completions/CompletionProviderFactory.h"
#include "ls6502/lsp/definition/DefinitionProviderFactory.h"
#include "ls6502/lsp/diagnostics/DiagnosticsProviderFactory.h"
#include "ls6502/lsp/hover/HoverProviderFactory.h"
#include "ls6502/lsp/snippets/SnippetProviderFactory.h"

#include "ls6502/lsp/messages/request/InitializeRequest.h"
#include "ls6502/lsp/messages/request/DidOpenTextDocumentRequest.h"
#include "ls6502/lsp/messages/request/DidChangeTextDocumentRequest.h"
#include "ls6502/lsp/messages/request/ShutdownRequest.h"
#include "ls6502/lsp/messages/request/CompletionRequest.h"
#include "ls6502/lsp/messages/request/HoverRequest.h"
#include "ls6502/lsp/messages/request/CodeActionRequest.h"
#include "ls6502/lsp/messages/request/DefinitionRequest.h"

#include "ls6502/lsp/messages/notification/PublishDiagnosticsNotification.h"
#include "ls6502/lsp/messages/response/InitializeResponse.h"
#include "ls6502/lsp/messages/response/ShutdownResponse.h"
#include "ls6502/lsp/messages/response/CompletionResponse.h"
#include "ls6502/lsp/messages/response/HoverResponse.h"
#include "ls6502/lsp/messages/response/CodeActionResponse.h"

#include "ls6502/lsp/params/InitializeParams.h"
#include "ls6502/lsp/params/DidOpenTextDocumentParams.h"
#include "ls6502/lsp/params/DidChangeTextDocumentParams.h"
#include "ls6502/lsp/params/CodeActionParams.h"
#include "ls6502/lsp/params/HoverParams.h"
#include "ls6502/lsp/params/DefinitionParams.h"
#include "ls6502/lsp/params/PublishDiagnosticsParams.h"

#include "ls6502/lsp/types/TextDocumentItem.h"
#include "ls6502/lsp/types/ClientInfo.h"
#include "ls6502/lsp/types/CompletionItem.h"
#include "ls6502/lsp/types/Diagnostic.h"
#include "ls6502/lsp/types/Location.h"

#include "ls6502/lsp/results/InitializeResult.h"
#include "ls6502/lsp/results/CompletionResult.h"
#include "ls6502/lsp/results/HoverResult.h"
#include "ls6502/lsp/results/CodeActionResult.h"

#include "ls6502/lsp/rpc/Rpc.h"
#include "ls6502/utils/Logger.h"

namespace ls6502::core
{

////////////////////////////////////////////////////////////
Ls6502ReqHandler::Ls6502ReqHandler() :
    m_diagnosticsProvider(DiagnosticsProviderFactory::create()),
    m_completionProvider(CompletionProviderFactory::create()),
    m_definitionProvider(DefinitionProviderFactory::create()),
    m_hoverProvider(HoverProviderFactory::create()),
    m_snippetProvider(SnippetProviderFactory::create()),
    m_codeActionsProvider(CodeActionsProviderFactory::create())
{
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::initializeReq(const std::shared_ptr<InitializeRequest>& initializeRequest)
{
    LS_6502_DEBUG("Processing textDocument/initialize request");

    std::shared_ptr<InitializeParams>   initializeParams = initializeRequest->getInitializeParams();
    std::shared_ptr<ClientCapabilities> capabilities     = initializeParams->getClientCapabilites();

    const ClientInfo& clientInfo = initializeParams->getClientInfo();

    LS_6502_DEBUG(STR("Client: %s has sent initialization request", clientInfo.toString().c_str()));

    m_ls6502Client->saveInfo(clientInfo);
    m_ls6502Client->registerCapabilites(capabilities);

    ServerCapabilities::Builder serverCapabilitiesBuilder;
    ServerCapabilitiesDirector::constructDefaultServerCapabilities(serverCapabilitiesBuilder);
    ServerCapabilities serverCapabilities = serverCapabilitiesBuilder.build();

    InitializeResult   initializeResult({"Ls6502", "0.0.0.0.0.1-alpha"}, serverCapabilities);
    InitializeResponse initializeResponse("2.0", initializeRequest->getId(), initializeResult);

    Rpc::send(initializeResponse);

    LS_6502_DEBUG(STR("Initialize response was successfully sent for client: %s", clientInfo.toString().c_str()));
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentDidOpenReq(const std::shared_ptr<DidOpenTextDocumentRequest>& didOpenTextDocumentReq)
{
    LS_6502_DEBUG("Processing textDocument/didOpen request");

    std::shared_ptr<DidOpenTextDocumentParams> didOpenParams    = didOpenTextDocumentReq->getParams();
    std::shared_ptr<TextDocumentItem>          textDocumentItem = didOpenParams->getTextDocumentItem();

    const std::string& URI                 = textDocumentItem->getURI();
    const std::string& textDocumentContent = textDocumentItem->getText();

    m_ls6502Client->addDocument(URI, textDocumentContent);

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const std::vector<Diagnostic>& diagnostics = m_diagnosticsProvider->getDiagnostics(*documentOpt);

    auto diagnosticsParams = std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNotification notification("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(notification);

    LS_6502_DEBUG("Request with method: textDocument/didOpen was successfully processed");
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentDidChangeReq(const std::shared_ptr<DidChangeTextDocumentRequest>& didChangeTextDocumentReq)
{
    LS_6502_DEBUG("Processing textDocument/didChange request");

    auto didChangeParams = didChangeTextDocumentReq->getParams();
    const std::string& URI = didChangeParams->getChangedDocumentURI();
    const std::string& content = didChangeParams->getContentChanges();

    m_ls6502Client->updateDocumentWithURI(URI, content);

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const std::vector<Diagnostic>& diagnostics = m_diagnosticsProvider->getDiagnostics(*documentOpt);

    auto diagnosticsParams = std::make_shared<PublishDiagnosticsParams>(URI, diagnostics);
    PublishDiagnosticsNotification notification("textDocument/publishDiagnostics", diagnosticsParams);

    Rpc::send(notification);

    LS_6502_DEBUG("Response successfully sent for textDocument/didChange request");
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentCompletionReq(const std::shared_ptr<CompletionRequest>& completionReq)
{
    LS_6502_DEBUG("Processing textDocument/completion request");

    auto params = completionReq->getParams();
    const std::string& URI = params->getURI();
    const Position& position = params->getPosition();

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const std::vector<CompletionItem>& completions = m_completionProvider->getCompletions(*documentOpt, position);

    CompletionResult result(completions);
    CompletionResponse response("2.0", completionReq->getId(), result);

    Rpc::send(response);

    LS_6502_DEBUG("Response successfully sent for textDocument/completion request");
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentHoverReq(const std::shared_ptr<HoverRequest>& hoverTextDocumentReq)
{
    LS_6502_DEBUG("Processing textDocument/hover request");

    auto params = hoverTextDocumentReq->getParams();
    const std::string& URI = params->getTextDocumentIdentifier().URI;
    const Position& position = params->getPosition();

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const HoverItem& item = m_hoverProvider->getHoverItem(*documentOpt, position);

    HoverResult result(item.text);
    HoverResponse response("2.0", hoverTextDocumentReq->getId(), result);

    Rpc::send(response);
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentCodeActionReq(const std::shared_ptr<CodeActionRequest>& codeActionRequest)
{
    LS_6502_DEBUG("Processing textDocument/codeAction request");

    auto params = codeActionRequest->getParams();
    const std::string& URI = params->getURI();

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const std::vector<CodeAction>& actions = m_codeActionsProvider->getCodeActions(*documentOpt, URI);

    CodeActionResult result(actions);
    CodeActionResponse response("2.0", codeActionRequest->getId(), result);

    Rpc::send(response);
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::textDocumentDefinitionReq(const std::shared_ptr<DefintionRequest>& defintionRequest)
{
    LS_6502_DEBUG("Processing textDocument/definition request");

    auto params = defintionRequest->getParams();
    const std::string& URI = params->getTextDocumentIdentifier().URI;
    const Position& position = params->getPosition();

    auto documentOpt = m_ls6502Client->getDocumentByURI(URI);
    if (!documentOpt)
        return;

    const Location& location = m_definitionProvider->provideDefinitionLocation(*documentOpt, position, *documentOpt);
    // If you need to respond, build a proper DefinitionResponse and send it via Rpc
}

////////////////////////////////////////////////////////////
void Ls6502ReqHandler::shutdownReq(const std::shared_ptr<ShutdownRequest>& shutdownRequest)
{
    LS_6502_DEBUG("Processing shutdown request");

    ShutdownResponse response("2.0", shutdownRequest->getId());
    Rpc::send(response);

    LS_6502_DEBUG("Response was sent for shutdown request!");
}

} // namespace ls6502::core

