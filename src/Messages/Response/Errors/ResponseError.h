#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>
#include <string>

#include "../../Errors/ErrorCodes.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ResponseError
///
/// @brief Represents an error response in JSON-RPC.
///        This class encapsulates the error code and a message
///        describing the error encountered during a request.
///
//////////////////////////////////////////////////////////////
class ResponseError
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a ResponseError with a specific code and message.
    ///
    /// @param [in] errorCode
    /// @param [in] message
    ///
    //////////////////////////////////////////////////////////////
    ResponseError(const ErrorCodes& errorCode, const std::string& message);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for error code
    ///
    /// @return Error code
    ///
    //////////////////////////////////////////////////////////////
    ErrorCodes getErrorCode() const
    {
        return m_errorCode;
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for error message
    ///
    /// @return Error message
    ///
    //////////////////////////////////////////////////////////////
    std::string getErrorMessage() const
    {
        return m_message;
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of ResponseError
    ///
    /// @return String representation of ResponseError
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const;

    ///////////////////////////////////////////////////////////////
    ///
    /// @brief Sereializes ResponseError to JSON format
    ///
    /// @return ResponseError in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @class Builder
    ///
    /// @brief Builder class for constructing ResponseError instances.
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
    public:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the error code in response error
        ///
        //////////////////////////////////////////////////////////////
        Builder& withErrorCode(const ErrorCodes& errorCode);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the error message in response errror
        ///
        //////////////////////////////////////////////////////////////
        Builder& withErrorMessage(const std::string& message);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Creates an instance on ResponseError
        ///
        //////////////////////////////////////////////////////////////
        ResponseError build() const;

    private:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief The error code representing the type of error.
        ///
        //////////////////////////////////////////////////////////////
        ErrorCodes m_errorCode;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief A message providing additional information about the error.
        ///
        //////////////////////////////////////////////////////////////
        std::string m_message;
    };

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The error code representing the type of error.
    ///
    //////////////////////////////////////////////////////////////
    ErrorCodes m_errorCode;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief A message providing additional information about the error.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_message;
};

} // namespace ls6502
