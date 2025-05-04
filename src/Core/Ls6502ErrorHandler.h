#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>
#include <string>

#include "../Errors/ErrorCodes.h"
#include "../Messages/Response/ResponseError.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class Ls6502ErrorHandler
///
/// @brief Responsible for handling Ls6502 errors
///
//////////////////////////////////////////////////////////////
class Ls6502ErrorHandler
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    Ls6502ErrorHandler()                                     = default;
    Ls6502ErrorHandler(const Ls6502ErrorHandler&)            = delete;
    Ls6502ErrorHandler(Ls6502ErrorHandler&&)                 = delete;
    Ls6502ErrorHandler& operator=(const Ls6502ErrorHandler&) = delete;
    Ls6502ErrorHandler& operator=(Ls6502ErrorHandler&&)      = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the server not initialized error
    ///
    /// @param [in] message id
    ///
    //////////////////////////////////////////////////////////////
    void handleServerNotInitalizedError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the parse error
    ///
    /// @param [in] message id
    ///
    //////////////////////////////////////////////////////////////
    void handleParseError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the method not found error
    ///
    /// @param [in] message id
    ///
    //////////////////////////////////////////////////////////////
    void handleMethodNotFoundError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the internal error
    ///
    /// @param [in] message id
    ///
    //////////////////////////////////////////////////////////////
    void handleInternalError(int64_t id);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the invalid request after shutdown
    ///
    /// @param [in] message id
    ///
    //////////////////////////////////////////////////////////////
    void handleReceivedReqAfterShutdownError(int64_t id);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the error
    ///
    /// @param [in] responseError
    /// @param [in] id
    ///
    //////////////////////////////////////////////////////////////
    void handleError(const ResponseError& responseError, int64_t id);
};
} // namespace ls6502
