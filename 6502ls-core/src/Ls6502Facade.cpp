////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "ls6502/core/Ls6502Facade.h"

#include <iostream>
#include <memory>
#include <vector>

#include "ls6502/lsp/enums/ExitStatus.h"
#include "ls6502/lsp/enums/RequestType.h"
#include "ls6502/lsp/enums/TextDocumentSyncKind.h"

#include "ls6502/lsp/messages/factory/MessageFactory.h"

#include "ls6502/lsp/messages/request/CodeActionRequest.h"
#include "ls6502/lsp/messages/request/DidChangeTextDocumentRequest.h"
#include "ls6502/lsp/messages/request/HoverRequest.h"
#include "ls6502/lsp/messages/request/ShutdownRequest.h"

#include "ls6502/lsp/messages/response/CompletionResponse.h"
#include "ls6502/lsp/messages/response/ResponseMessage.h"

#include "ls6502/lsp/params/InitializeParams.h"
#include "ls6502/rpc/Rpc.h"
#include "ls6502/lsp/types/ClientInfo.h"
#include "ls6502/lsp/types/CompletionItem.h"
#include "ls6502/utils/Logger.h"
#include "ls6502/utils/MessageUtil.h"

#include "ls6502/core/Ls6502Client.h"
#include "ls6502/core/Ls6502Counter.h"
#include "ls6502/core/Ls6502ErrorHandler.h"
#include "ls6502/core/Ls6502ReqHandler.h"

namespace ls6502::core
{

////////////////////////////////////////////////////////////
void Ls6502Facade::handleRequest(const nlohmann::json& request)
{
    switch (utils::MessageUtil::getMethod(request))
    {
        case lsp::RequestType::INITIALIZE:
            handleInitializeRequest(request);
            break;
        case lsp::RequestType::INITIALIZED:
            handleInitializedRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_DID_OPEN:
            handleTextDocumentDidOpenRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_DID_CHANGE:
            handleTextDocumentDidChangeRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_COMPLETION:
            handleTextDocumentCompletionRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_HOVER:
            handleTextDocumentHoverRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_CODE_ACTION:
            handleTextDocumentCodeActionRequest(request);
            break;
        case lsp::RequestType::TEXT_DOCUMENT_DEFINITION:
            handleTextDocumentDefintionRequest(request);
            break;
        case lsp::RequestType::SHUTDOWN:
            handleShutdownRequest(request);
            break;
        case lsp::RequestType::EXIT:
            handleExitRequest(request);
            break;
        default:
            LS_6502_ERROR("Received request/notification with method: UNKNOWN_TYPE");
            break;
    }
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleInitializeRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: initialize");

    m_ls6502Counters->increment(lsp::RequestType::INITIALIZE);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto initializeRequest = lsp::MessageFactory::createInitializeReq(request);
    m_ls6502ReqHandler->initializeReq(initializeRequest);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleShutdownRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: shutdown");

    m_ls6502Counters->increment(lsp::RequestType::SHUTDOWN);

    auto shutdownRequest = lsp::MessageFactory::createShutdownReq(request);
    m_ls6502ReqHandler->shutdownReq(shutdownRequest);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleInitializedRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received notification with method: initialized");

    m_ls6502Counters->increment(lsp::RequestType::INITIALIZED);
    ensureNoReqIsProcessedAfterShutdown(request);

    LS_6502_DEBUG("Successful connection between client and Ls6502Server has been established");
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentDidOpenRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received notification with method: textDocument/didOpen");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_DID_OPEN);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto didOpen = lsp::MessageFactory::createDidOpenTextDocumentReq(request);
    m_ls6502ReqHandler->textDocumentDidOpenReq(didOpen);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentDidChangeRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: textDocument/didChange");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_DID_CHANGE);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto didChange = lsp::MessageFactory::createDidChangeTextDocumentReq(request);
    m_ls6502ReqHandler->textDocumentDidChangeReq(didChange);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentCompletionRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: textDocument/completion");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_COMPLETION);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto completionReq = lsp::MessageFactory::createCompletionReq(request);
    m_ls6502ReqHandler->textDocumentCompletionReq(completionReq);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleExitRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received notification with method: exit");

    bool shutdownReceived = m_ls6502Counters->getValue(lsp::RequestType::SHUTDOWN) != 0;

    if (shutdownReceived)
    {
        LS_6502_DEBUG("Exiting with status code 0 (successful shutdown)");
        std::exit(lsp::ExitStatus::SUCCESS);
    }
    else
    {
        LS_6502_ERROR("Exiting with status code 1 (shutdown not received)");
        std::exit(lsp::ExitStatus::FAILURE);
    }
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentHoverRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: textDocument/hover");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_HOVER);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto hoverReq = lsp::MessageFactory::createHoverReq(request);
    m_ls6502ReqHandler->textDocumentHoverReq(hoverReq);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentCodeActionRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: textDocument/codeAction");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_CODE_ACTION);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto codeActionReq = lsp::MessageFactory::createCodeActionRequest(request);
    m_ls6502ReqHandler->textDocumentCodeActionReq(codeActionReq);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::handleTextDocumentDefintionRequest(const nlohmann::json& request)
{
    LS_6502_DEBUG("Received request with method: textDocument/definition");

    m_ls6502Counters->increment(lsp::RequestType::TEXT_DOCUMENT_DEFINITION);
    ensureNoReqIsProcessedAfterShutdown(request);

    auto defRequest = lsp::MessageFactory::createGoToDefinitionRequest(request);
    m_ls6502ReqHandler->textDocumentDefinitionReq(defRequest);
}

////////////////////////////////////////////////////////////
void Ls6502Facade::ensureNoReqIsProcessedAfterShutdown(const nlohmann::json& request)
{
    if (m_ls6502Counters->getValue(lsp::RequestType::SHUTDOWN) != 0)
    {
        LS_6502_ERROR("Received request after shutdown");
        m_ls6502ErrorHandler->handleReceivedReqAfterShutdownError(request["id"]);
    }
}

} // namespace ls6502::core

