#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

#include "../Enums/TextDocumentSyncKind.h"

namespace justanlsp
{

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilities
///
/// @brief Encapsulates server capabilities, including support for
///        text synchronization, hover, snippet completions, and
///        other features of the language server.
///
//////////////////////////////////////////////////////////////
class ServerCapabilities
{
    // TODO: Extend the implementation for additional capabilities.

  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs server capabilities
    ///
    /// @param textDocumentSyncKind
    /// @param areSnippetsSupported
    /// @param isHoverSupported
    /// @param areCompletionsSupported
    /// @param areCodeActionsSupported
    /// @param areDefinitionsSupported
    ///
    //////////////////////////////////////////////////////////////
    ServerCapabilities(const TextDocumentSyncKind &textDocumentSyncKind, bool areSnippetsSupported,
                       bool isHoverSupported, bool areCompletionsSupported, bool areCodeActionsSupported,
                       bool areDefintionsSupported);

    //////////////////////////////////////////////////////////////
    ///
    /// @class Builder
    ///
    /// @brief Constructs instances of ServerCapabilities using a
    ///        fluent interface for customization.
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
      public:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the text document synchronization kind.
        ///
        /// @param textDocuemntSyncKind TextDocumentSyncKind enum value.
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withTextDocumentSyncKind(const TextDocumentSyncKind &textDocuemntSyncKind);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables snippet support.
        ///
        /// @param areSnippetsSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withSnippetSupport(bool areSnippetsSupported);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables hover functionality.
        ///
        /// @param isHoverSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withHoverSupport(bool isHoverSupported);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables completion support.
        ///
        /// @param areCompletionsSupported
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCompletionSupport(bool areCompletionsSupported);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables code action support.
        ///
        /// @param areCodeActions
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCodeActionSupport(bool areCodeActionsSupported);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Enables or disables code action support.
        ///
        /// @param areCodeActions
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withDefinitionSupport(bool areDefintionsSupported);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Constructs a ServerCapabilities instance based on
        ///        the set parameters.
        ///
        /// @return A ServerCapabilities instance.
        ///
        //////////////////////////////////////////////////////////////
        ServerCapabilities build() const;

      private:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Synchronization kind for text documents.
        ///
        //////////////////////////////////////////////////////////////
        TextDocumentSyncKind m_textDocumentSyncKind;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether snippets are supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areSnippetsSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether completions are supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areCompletionsSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether hover functionality is supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_isHoverSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether code action functionality is supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areCodeActionsSupported;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Indicates whether go to definition functionality is supported.
        ///
        //////////////////////////////////////////////////////////////
        bool m_areDefinitionsSupported;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Converts the ServerCapabilities instance to its
    ///        JSON representation.
    ///
    /// @return server capabilities in JSON format
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

  private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Synchronization kind for text documents.
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentSyncKind m_textDocumentSyncKind;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether snippets are supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areSnippetsSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether completions are supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areCompletionsSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether hover functionality is supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_isHoverSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether hover functionality is supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areCodeActionsSupported;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Indicates whether go to definition functionality is supported.
    ///
    //////////////////////////////////////////////////////////////
    bool m_areDefinitionsSupported;
};
} // namespace justanlsp
