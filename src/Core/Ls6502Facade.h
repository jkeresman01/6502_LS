#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>

#include "../Messages/Response/ResponseMessage.h"
#include "Ls6502Client.h"
#include "Ls6502Counter.h"
#include "Ls6502ErrorHandler.h"
#include "Ls6502ReqHandler.h"

namespace ls6052
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
    Ls6502Facade() = default;
    Ls6502Facade(const Ls6502Facade &) = delete;
    Ls6502Facade(Ls6502Facade &&) = delete;
    Ls6502Facade &operator=(const Ls6502Facade &) = delete;
    Ls6502Facade &operator=(Ls6502Facade &&) = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Interface for handling all LSP requests
    ///
    /// @param String representation of incoming request
    ///
    //////////////////////////////////////////////////////////////
    void handleRequest(const nlohmann::json &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialize request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializeRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling shutdown request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleShutdownRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling initialized request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleInitializedRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didOpen request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidOpenRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/didChange request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDidChangeRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/hover request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentHoverRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCompletionRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleExitRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/completion request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentCodeActionRequest(const nlohmann::json &request);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Entry point for handling textDocument/definition request
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void handleTextDocumentDefintionRequest(const nlohmann::json &request);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Ensures no request is processed after shudtown request
    ///        has been received, except exit notification
    ///
    /// @param jsonRPC request
    ///
    //////////////////////////////////////////////////////////////
    void ensureNoReqIsProcessedAfterShutdown(const nlohmann::json &request);

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
    std::unique_ptr<Ls6502ErrorHandler> m_ls6502ErrorHandler =
        std::make_unique<Ls6502ErrorHandler>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Request counters
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Ls6502Counter> m_ls6502Counters = std::make_unique<Ls6502Counter>();
};

} // namespace ls6052
