#pragma once

#include "../Messages/Response/ResponseError.h"

namespace ls6502
{
class Ls6502ErrorDirector
{
  public:
    static void buildServerNotInitializedError(ResponseError::Builder &responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::SERVER_NOT_INITIALIZED)
            .withErrorMessage("Received request before initiliazition request was send!");
    }

    static void buildParseError(ResponseError::Builder &responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::PARSE_ERROR)
            .withErrorMessage("Parsing error happened, while processing request!");
    }

    static void buildMethodNotFoundError(ResponseError::Builder &responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::METHOD_NOT_FOUND)
            .withErrorMessage("Didn't find method for given request");
    }

    static void buildInternalServerError(ResponseError::Builder &responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::INTERNAL_ERROR)
            .withErrorMessage("Internal error happened");
    }

    static void buildRequestReceivedAfterShutdownError(ResponseError::Builder &responseErrorBuilder)
    {
        responseErrorBuilder.withErrorCode(ErrorCodes::INVALID_REQUEST)
            .withErrorMessage("Received request after shutdown");
    }
};
} // namespace ls6502
