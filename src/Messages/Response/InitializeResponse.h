#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <ostream>
#include <string>

#include "../Capabilities/Server/ServerCapabilities.h"
#include "../Results/InitializeResult.h"
#include "../Types/ServerInfo.h"
#include "ResponseError.h"
#include "ResponseMessage.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class InitializeResponse
///
/// @brief Represents the response to an "initialize" request
///        in the language server protocol (LSP).
///
//////////////////////////////////////////////////////////////
class InitializeResponse : public ResponseMessage
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs an InitializeResponse with the provided
    ///        server info and capabilities.
    ///
    /// @param [in] initializeResult
    ///
    //////////////////////////////////////////////////////////////
    InitializeResponse(const std::string& jsonRPC, const int64_t& id, const InitializeResult& initializeResult);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs an InitializeResponse with the provided
    ///        server info and capabilities.
    ///
    /// @param [in] initializeResult
    /// @param [in] responseError
    ///
    //////////////////////////////////////////////////////////////
    InitializeResponse(const InitializeResult& initializeResult, const ResponseError& responseErro);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the InitializeResponse to JSON format.
    ///
    /// @return Returns the response in JSON format.
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const override;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief String representation of InitializeResponse
    ///
    /// @return String representation of InitializeResponse
    ///
    //////////////////////////////////////////////////////////////
    std::string toString() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Overloads the output stream operator for InitializeResponse
    ///
    /// @param [in] out
    /// @param [in] responseMessage
    ///
    /// @return The modified output stream.
    ///
    //////////////////////////////////////////////////////////////
    friend std::ostream& operator<<(std::ostream& os, const InitializeResponse& initializeResponse);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Result of initliaziation request
    ///
    //////////////////////////////////////////////////////////////
    InitializeResult m_initializeResut;
};

} // namespace ls6502
