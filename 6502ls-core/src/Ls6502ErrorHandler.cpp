////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "ls6502/core/Ls6502ErrorHandler.h"

#include "ls6502/lsp/messages/response/ResponseMessage.h"
#include "ls6502/lsp/messages/response/ResponseError.h"
#include "ls6502/lsp/errors/ErrorCodes.h"
#include "ls6502/core/Ls6502ErrorDirector.h"
#include "ls6502/infra/logging/Logger.h"
#include "ls6502/rpc/Rpc.h"

namespace ls6502::core
{

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleServerNotInitalizedError(int64_t id)
{
    LS_6502_DEBUG("Handling server not initialized error");

    lsp::ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructServerNotInitializedError(errorBuilder);
    lsp::ResponseError serverNotInitializedError = errorBuilder.build();

    handleError(serverNotInitializedError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleParseError(int64_t id)
{
    LS_6502_DEBUG("Handling parse error");

    lsp::ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructParseError(errorBuilder);
    lsp::ResponseError parseError = errorBuilder.build();

    handleError(parseError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleMethodNotFoundError(int64_t id)
{
    LS_6502_DEBUG("Handling method not found error");

    lsp::ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructMethodNotFoundError(errorBuilder);
    lsp::ResponseError methodNotFoundError = errorBuilder.build();

    handleError(methodNotFoundError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleInternalError(int64_t id)
{
    LS_6502_DEBUG("Handling internal server error");

    lsp::ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructInternalServerError(errorBuilder);
    lsp::ResponseError internalServerError = errorBuilder.build();

    handleError(internalServerError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleReceivedReqAfterShutdownError(int64_t id)
{
    LS_6502_DEBUG("Handling invalid request error");

    lsp::ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructRequestReceivedAfterShutdownError(errorBuilder);
    lsp::ResponseError invalidRequestError = errorBuilder.build();

    handleError(invalidRequestError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleError(const lsp::ResponseError& responseError, int64_t id)
{
    LS_6502_DEBUG(STR("Sending response error: %s", responseError.toString().c_str()));

    lsp::ResponseMessage responseMessage("2.0", id, responseError);

    rpc::Rpc::send(responseMessage);
}

} // namespace ls6502::core

