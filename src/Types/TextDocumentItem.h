#pragma once

#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>

namespace justanlsp
{
//////////////////////////////////////////////////////////////
///
/// @class TextDocumentItem
///
/// @brief Represents a text document in the language server protocol (LSP).
///        This class stores information about a document's URI, language,
///        version, and content, and can be constructed from a JSON-RPC request.
///
//////////////////////////////////////////////////////////////
class TextDocumentItem
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs the TextDocumentItem from a JSON-RPC request.
    ///
    /// @param jsonRPC The JSON object containing the TextDocumentItem information.
    ///
    //////////////////////////////////////////////////////////////
    explicit TextDocumentItem(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the URI of the text document.
    ///
    /// @return URI
    ///
    //////////////////////////////////////////////////////////////
    std::string getURI() const { return m_URI; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the language identifier of the text document.
    ///
    /// @return A string representing the language ID.
    ///
    //////////////////////////////////////////////////////////////
    std::string getLanguageId() const { return m_languageId; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the version of the text document.
    ///
    /// @return version
    ///
    //////////////////////////////////////////////////////////////
    int64_t getVersion() const { return m_version; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Retrieves the content of the text document.
    ///
    /// @return text
    ///
    //////////////////////////////////////////////////////////////
    std::string getText() const { return m_text; }

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for URI
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setURI(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for language ID
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setLanguageId(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for text version
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setTextVersion(const nlohmann::json &jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Mutator method for text content
    ///
    /// @param jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setText(const nlohmann::json &jsonRPC);

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief The URI of the text document.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_URI;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The language identifier for the text document.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_languageId;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The version of the text document.
    ///        This version number increases with every change, including undo/redo.
    ///
    //////////////////////////////////////////////////////////////
    int64_t m_version;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The content of the text document.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_text;
};

} // namespace justanlsp
