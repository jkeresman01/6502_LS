#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../Messages/Request/CodeActionRequest.h"
#include "../Messages/Request/CompletionRequest.h"
#include "../Messages/Request/DefinitionRequest.h"
#include "../Messages/Request/DidChangeTextDocumentRequest.h"
#include "../Messages/Request/DidOpenTextDocumentRequest.h"
#include "../Messages/Request/HoverRequest.h"
#include "../Messages/Request/InitializeRequest.h"
#include "../Messages/Request/ShutdownRequest.h"
#include "../Utils/Logger.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class MessageFactory
///
/// @brief Factory class to create instances of various LSP request
///        message objects.
///
//////////////////////////////////////////////////////////////
class MessageFactory
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    MessageFactory() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an InitializeRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an InitializeRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<InitializeRequest> createInitializeReq(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<InitializeRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an ShutdownRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an ShutdownRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<ShutdownRequest> createShutdownReq(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<ShutdownRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an DidOpenTextDocumentRequest message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an DidOpenTextDocumentRequest object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<DidOpenTextDocumentRequest> createDidOpenTextDocumentReq(
        const nlohmann::json &jsonRPC)
    {
        return std::make_shared<DidOpenTextDocumentRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an DidChangeTextDocument message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an DidChangeTextDocument object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<DidChangeTextDocumentRequest> createDidChangeTextDocumentReq(
        const nlohmann::json &jsonRPC)
    {
        return std::make_shared<DidChangeTextDocumentRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an Completion request message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an Completion request object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<CompletionRequest> createCompletionReq(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<CompletionRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an Hover request message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an Hover request object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<HoverRequest> createHoverReq(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<HoverRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an Code action request message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an code action request object.
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<CodeActionRequest> createCodeActionRequest(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<CodeActionRequest>(jsonRPC);
    }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Creates an go to definition request message object.
    ///
    /// @param jsonRPC The JSON object containing the request data.
    ///
    /// @return A shared pointer to an go to definition request objecy
    ///
    //////////////////////////////////////////////////////////////
    static std::shared_ptr<DefintionRequest> createGoToDefinitionRequest(const nlohmann::json &jsonRPC)
    {
        return std::make_shared<DefintionRequest>(jsonRPC);
    }
};

} // namespace justanlsp
