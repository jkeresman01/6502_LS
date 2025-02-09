#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "TextDocumentCapabilities.h"

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class ClientCapabilities
///
/// @brief ClientCapabilities define capabilities for dynamic
///        registration, workspace and text document features
///        the client supports.
///
//////////////////////////////////////////////////////////////
class ClientCapabilities
{
    // TODO reset of the capilites (only text is provided for now)

  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Default constructor for ClientCapabilities
    ///
    //////////////////////////////////////////////////////////////
    ClientCapabilities() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the ClientCapabilities from jsonRPC request
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit ClientCapabilities(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief  Accessor method for text document features that
    ///         client (editor or tool) supports.
    ///
    /// @return TextDocumentCapabilities
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TextDocumentCapabilities> getTextDocumentCapabilities() const { return m_textDocument; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief TextDocumentClientCapabilities define capabilities
    ///        the editor / tool provides on text documents.
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TextDocumentCapabilities> m_textDocument;
};
} // namespace justanlsp
