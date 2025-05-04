#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <memory>

#include "../CodeActions/ICodeActionsProvider.h"
#include "../Completions/ICompletionProvider.h"
#include "../Definition/IDefinitionProvider.h"
#include "../Diagnostics/IDiagnosticsProvider.h"
#include "../Hover/IHoverProvider.h"
#include "../Messages/Request/CodeActionRequest.h"
#include "../Messages/Request/CompletionRequest.h"
#include "../Messages/Request/DefinitionRequest.h"
#include "../Messages/Request/DidChangeTextDocumentRequest.h"
#include "../Messages/Request/DidOpenTextDocumentRequest.h"
#include "../Messages/Request/HoverRequest.h"
#include "../Messages/Request/InitializeRequest.h"
#include "../Messages/Request/ShutdownRequest.h"
#include "../Snippets/ISnippetProvider.h"
#include "Ls6502Client.h"
#include "Ls6502Counter.h"

namespace ls6502
{
//////////////////////////////////////////////////////////////
///
/// @class Ls6502ReqHandler
///
/// @brief Responsible for handling Ls6502 requests
///        (init, shutdown, register/unregister capabilites)
///
//////////////////////////////////////////////////////////////
class Ls6502ReqHandler
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructors (default, copy, move)
    ///        and assignment operators
    ///
    //////////////////////////////////////////////////////////////
    Ls6502ReqHandler();
    Ls6502ReqHandler(const Ls6502ReqHandler&)            = delete;
    Ls6502ReqHandler(Ls6502ReqHandler&&)                 = delete;
    Ls6502ReqHandler& operator=(const Ls6502ReqHandler&) = delete;
    Ls6502ReqHandler& operator=(Ls6502ReqHandler&&)      = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the initialization request
    ///
    /// @param [in] initializeRequest
    ///
    //////////////////////////////////////////////////////////////
    void initializeReq(const std::shared_ptr<InitializeRequest>& initializeRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles the shutdown request
    ///
    /// @param [in] shutdownRequest
    ///
    //////////////////////////////////////////////////////////////
    void shutdownReq(const std::shared_ptr<ShutdownRequest>& shutdownRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/didOpen request
    ///
    /// @param [in] textDocument/didOpen request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDidOpenReq(const std::shared_ptr<DidOpenTextDocumentRequest>& didOpenTextDocumentReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/completion request
    ///
    /// @param [in] textDocument/completion  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentCompletionReq(const std::shared_ptr<CompletionRequest>& completionReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/didChange request
    ///
    /// @param [in] textDocument/didChange  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDidChangeReq(const std::shared_ptr<DidChangeTextDocumentRequest>& didChangeTextDocumentReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/hover request
    ///
    /// @param [in] textDocument/hover  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentHoverReq(const std::shared_ptr<HoverRequest>& hoverTextDocuementReq);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/codeAction request
    ///
    /// @param [in] textDocument/codeAction  request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentCodeActionReq(const std::shared_ptr<CodeActionRequest>& codeActionRequest);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Handles textDocument/definition request
    ///
    /// @param [in] textDocument/definition request
    ///
    //////////////////////////////////////////////////////////////
    void textDocumentDefinitionReq(const std::shared_ptr<DefintionRequest>& defintionRequest);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Ls6502Client - editor or tool attached to
    ///        Ls6502 server
    ///
    //////////////////////////////////////////////////////////////
    std::unique_ptr<Ls6502Client> m_ls6502Client = std::make_unique<Ls6502Client>();

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to completions provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ICompletionProvider> m_completionProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to diagnostics provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IDiagnosticsProvider> m_diagnosticsProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to code actions provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ICodeActionsProvider> m_codeActionsProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to hover provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IHoverProvider> m_hoverProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to snippet provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<ISnippetProvider> m_snippetProvider;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief shared pointer to snippet provider object
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<IDefinitionProvider> m_definitionProvider;
};
} // namespace ls6502
