#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "ls6502/lsp/messages/response/ResponseMessage.h"
#include "ls6502/infra/common/DependecyContainer.h"

#include "ls6502/core/Ls6502Client.h"
#include "ls6502/core/Ls6502Counter.h"
#include "ls6502/core/Ls6502ErrorHandler.h"
#include "ls6502/core/Ls6502ReqHandler.h"

namespace ls6502::core
{

//////////////////////////////////////////////////////////////
///
/// @class Ls6502Facade
///
/// @brief Single simplified interface for handling LSP request messages
///
//////////////////////////////////////////////////////////////
class Ls6502Facade
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    Ls6502Facade(const std::shared_ptr<DependencyContainer>& depencyContainer);
    Ls6502Facade(const Ls6502Facade&)            = delete;
    Ls6502Facade(Ls6502Facade&&)                 = delete;
    Ls6502Facade& operator=(const Ls6502Facade&) = delete;
    Ls6502Facade& operator=(Ls6502Facade&&)      = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Interface for handling all LSP requests
    ///
    /// @param [in] String representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleRequest(const nlohmann::json& request);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialize request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializeRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling shutdown request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleShutdownRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialized request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializedRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didOpen request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidOpenRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didChange request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidChangeRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/hover request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentHoverRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCompletionRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleExitRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCodeActionRequest(const nlohmann::json& request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/definition request
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDefintionRequest(const nlohmann::json& request);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Ensures no request is processed after shudtown request
    ///        has been received, except exit notification
    ///
    /// @param [in] jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void ensureNoReqIsProcessedAfterShutdown(const nlohmann::json& request);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Responsible for handling request such as init/shutdown
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Ls6502ReqHandler> m_ls6502ReqHandler = std::make_unique<Ls6502ReqHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Responsible for handling request such as init/shutdown
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Ls6502ErrorHandler> m_ls6502ErrorHandler = std::make_unique<Ls6502ErrorHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Request counters
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Ls6502Counter> m_ls6502Counters = std::make_unique<Ls6502Counter>();
};

} // namespace ls6502
