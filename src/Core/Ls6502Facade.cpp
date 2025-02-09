#include "Ls6502Facade.h"

#include <exception>
#include <iostream>
#include <memory>
#include <vector>

#include "Ls6502Server.h"
#include "../Enums/ExitStatus.h"
#include "../Enums/RequestType.h"
#include "../Enums/TextDocumentSyncKind.h"
#include "../Messages/FactoryIml/MessageFactory.h"
#include "../Messages/Request/CodeActionRequest.h"
#include "../Messages/Request/DidChangeTextDocumentRequest.h"
#include "../Messages/Request/HoverRequest.h"
#include "../Messages/Request/ShutdownRequest.h"
#include "../Messages/Response/CompletionResponse.h"
#include "../Messages/Response/ResponseMessage.h"
#include "../Params/InitializeParams.h"
#include "../Rpc/Rpc.h"
#include "../Types/ClientInfo.h"
#include "../Types/CompletionItem.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"
#include "Ls6502Client.h"
#include "Ls6502Counter.h"
#include "Ls6502ErrorHandler.h"
#include "Ls6502Server.h"

namespace justanlsp
{

void Ls6502Facade::handleRequest(const nlohmann::json &request)
{
    switch (MessageUtil::getType(request))
    {
    case RequestType::INITIALIZE:
        handleInitializeRequest(request);
        break;
    case RequestType::INITIALIZED:
        handleInitializedRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_OPEN:
        handleTextDocumentDidOpenRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DID_CHANGE:
        handleTextDocumentDidChangeRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_COMPLETION:
        handleTextDocumentCompletionRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_HOVER:
        handleTextDocumentHoverRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_CODE_ACTION:
        handleTextDocumentCodeActionRequest(request);
        break;
    case RequestType::TEXT_DOCUMENT_DEFINITION:
        handleTextDocumentDefintionRequest(request);
        break;
    case RequestType::SHUTDOWN:
        handleShutdownRequest(request);
        break;
    case RequestType::EXIT:
        handleExitRequest(request);
        break;
    default:
        LS_6502_ERROR("Received request/notification with method: UNKNOWN_TYPE");
        break;
    }
}

void Ls6502Facade::handleInitializeRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: initialize");

    m_justAnLspCounters->increment(RequestType::INITIALIZE);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<InitializeRequest> initializeRequest = MessageFactory::createInitializeReq(request);

    m_ls6502ReqHandler->initializeReq(initializeRequest);
}

void Ls6502Facade::handleShutdownRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: shutdown");

    m_justAnLspCounters->increment(RequestType::SHUTDOWN);

    std::shared_ptr<ShutdownRequest> shutdownRequest = MessageFactory::createShutdownReq(request);

    m_ls6502ReqHandler->shutdownReq(shutdownRequest);
}

void Ls6502Facade::handleInitializedRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received notification with method: initialized");

    m_justAnLspCounters->increment(RequestType::INITIALIZED);

    ensureNoReqIsProcessedAfterShutdown(request);

    LS_6502_DEBUG("Successful connection between client and Ls6502Server has been established");
}

void Ls6502Facade::handleTextDocumentDidOpenRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received notification with method: textDocument/didOpen");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_OPEN);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DidOpenTextDocumentRequest> didOpenTextDocumentNotification =
        MessageFactory::createDidOpenTextDocumentReq(request);

    m_ls6502ReqHandler->textDocumentDidOpenReq(didOpenTextDocumentNotification);
}

void Ls6502Facade::handleTextDocumentDidChangeRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: textDocument/didChange");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DID_CHANGE);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DidChangeTextDocumentRequest> didChangeTextDocumentReq =
        MessageFactory::createDidChangeTextDocumentReq(request);

    m_ls6502ReqHandler->textDocumentDidChangeReq(didChangeTextDocumentReq);
}

void Ls6502Facade::handleTextDocumentCompletionRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: textDocument/completion");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_COMPLETION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<CompletionRequest> completionRequest = MessageFactory::createCompletionReq(request);

    m_ls6502ReqHandler->textDocumentCompletionReq(completionRequest);
}

void Ls6502Facade::handleExitRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received notification with method: exit");

    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        LS_6502_DEBUG("Exiting with status code 0 (successful shutdown)");
        std::exit(ExitStatus::SUCCESS);
    }
    else
    {
        LS_6502_ERROR("Exiting with status code 1 (shutdown not received)");
        std::exit(ExitStatus::FAILURE);
    }
}

void Ls6502Facade::handleTextDocumentHoverRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: textDocument/hover");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_HOVER);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<HoverRequest> hoverRequest = MessageFactory::createHoverReq(request);

    m_ls6502ReqHandler->textDocumentHoverReq(hoverRequest);
}

void Ls6502Facade::handleTextDocumentCodeActionRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: textDocument/codeAction");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_CODE_ACTION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<CodeActionRequest> codeActionRequest = MessageFactory::createCodeActionRequest(request);

    m_ls6502ReqHandler->textDocumentCodeActionReq(codeActionRequest);
}

void Ls6502Facade::handleTextDocumentDefintionRequest(const nlohmann::json &request)
{
    LS_6502_DEBUG("Received request with method: textDocument/codeAction");

    m_justAnLspCounters->increment(RequestType::TEXT_DOCUMENT_DEFINITION);

    ensureNoReqIsProcessedAfterShutdown(request);

    std::shared_ptr<DefintionRequest> definitionRequest =
        MessageFactory::createGoToDefinitionRequest(request);

    m_ls6502ReqHandler->textDocumentDefinitionReq(definitionRequest);
}

void Ls6502Facade::ensureNoReqIsProcessedAfterShutdown(const nlohmann::json &request)
{
    bool isShutdownReqReceived = m_justAnLspCounters->getValue(RequestType::SHUTDOWN) != 0;

    if (isShutdownReqReceived)
    {
        LS_6502_ERROR("Received request after shutdown");
        m_ls6502ErrorHandler->handleReceivedReqAfterShutdownError(request["id"]);
    }
}

} // namespace justanlsp
