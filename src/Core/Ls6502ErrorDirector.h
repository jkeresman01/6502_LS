#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "../Messages/Response/ResponseError.h"

namespace ls6502
{
class Ls6502ErrorDirector
{
public:
    ////////////////////////////////////////////////////////////
    static void constructServerNotInitializedError(ResponseError::Builder& responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::SERVER_NOT_INITIALIZED)
            .withErrorMessage("Received request before initiliazition request was send!");
    }


    ////////////////////////////////////////////////////////////
    static void constructParseError(ResponseError::Builder& responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::PARSE_ERROR)
            .withErrorMessage("Parsing error happened, while processing request!");
    }


    ////////////////////////////////////////////////////////////
    static void constructMethodNotFoundError(ResponseError::Builder& responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::METHOD_NOT_FOUND)
            .withErrorMessage("Didn't find method for given request");
    }


    ////////////////////////////////////////////////////////////
    static void constructInternalServerError(ResponseError::Builder& responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::INTERNAL_ERROR)
            .withErrorMessage("Internal error happened");
    }

    ////////////////////////////////////////////////////////////
    static void constructRequestReceivedAfterShutdownError(ResponseError::Builder& responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::INVALID_REQUEST)
            .withErrorMessage("Received request after shutdown");
    }
};
} // namespace ls6502
