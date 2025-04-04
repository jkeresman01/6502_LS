////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Ls6502ErrorHandler.h"

#include "../Messages/Response/ResponseMessage.h"
#include "../Rpc/Rpc.h"
#include "../Utils/Logger.h"
#include "Ls6502ErrorDirector.h"

namespace ls6502
{

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleServerNotInitalizedError(int64_t id)
{
    LS_6502_DEBUG("Handling server not initialized error");

    ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructServerNotInitializedError(errorBuilder);
    ResponseError serverNotInitializedError = errorBuilder.build();

    handleError(serverNotInitializedError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleParseError(int64_t id)
{
    LS_6502_DEBUG("Handling parse error");

    ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructParseError(errorBuilder);
    ResponseError parseError = errorBuilder.build();

    handleError(parseError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleMethodNotFoundError(int64_t id)
{
    LS_6502_DEBUG("Handling method not found error");

    ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructMethodNotFoundError(errorBuilder);
    ResponseError methodNotFoundError = errorBuilder.build();

    handleError(methodNotFoundError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleInternalError(int64_t id)
{
    LS_6502_DEBUG("Handling internal server error");

    ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructInternalServerError(errorBuilder);
    ResponseError internalServerError = errorBuilder.build();

    handleError(internalServerError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleReceivedReqAfterShutdownError(int64_t id)
{
    LS_6502_DEBUG("Handling invalid request error");

    ResponseError::Builder errorBuilder;
    Ls6502ErrorDirector::constructInternalServerError(errorBuilder);
    ResponseError invalidRequestError = errorBuilder.build();

    handleError(invalidRequestError, id);
}

////////////////////////////////////////////////////////////
void Ls6502ErrorHandler::handleError(const ResponseError& responseError, int64_t id)
{
    LS_6502_DEBUG(STR("Sending response error: %s", responseError.toString().c_str()));

    ResponseMessage responseMessage("2.0", id, responseError);

    Rpc::send(responseMessage);
}

} // namespace ls6502
