#pragma once

#include <memory>
#include <nlohmann/json.hpp>

#include "../Types/TextDocumentItem.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class DidOpenTextDocumentParams
///
/// @brief Represents the parameters sent when a text document
///        is opened in the Language Server Protocol (LSP).
///
//////////////////////////////////////////////////////////////
class DidOpenTextDocumentParams
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs a DidOpenTextDocumentParams object
    ///        from a JSON-RPC request.
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit DidOpenTextDocumentParams(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for TextDocumentItem
    ///
    /// @return TextDocumentItem
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TextDocumentItem> getTextDocumentItem() const { return m_textDocumentItem; };

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for TextDocumentItem
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setTextDocumentItemKind(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Contains the details of the text document that was opened,
    ///        such as URI, language, version, and content.
    ///
    //////////////////////////////////////////////////////////////
    std::shared_ptr<TextDocumentItem> m_textDocumentItem;
};

} // namespace justanlsp
