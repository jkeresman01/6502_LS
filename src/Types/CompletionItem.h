#pragma once

#include "../Enums/CompletionItemKind.h"

#include <nlohmann/json.hpp>
#include <string>

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @struct CompletionItem
///
/// @brief Represents a completion item in the language server protocol,
///
//////////////////////////////////////////////////////////////
class CompletionItem
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs textDocument/completion item
    ///
    //////////////////////////////////////////////////////////////
    CompletionItem() = default;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs textDocument/completion item
    ///
    /// @param label
    /// @param detail
    /// @param documentation
    /// @param detail
    ///
    //////////////////////////////////////////////////////////////
    CompletionItem(const std::string &label, const CompletionItemKind completionItemKind,
                   const std::string &detail, const std::string &documentation,
                   const std::string &insertedText);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for inserted text
    ///
    /// @return insert text
    ///
    //////////////////////////////////////////////////////////////
    std::string getInsertedText() const { return m_insertText; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for inserted text
    ///
    //////////////////////////////////////////////////////////////
    std::string getLabel() const { return m_label; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for details
    ///
    /// @return details
    ///
    //////////////////////////////////////////////////////////////
    std::string getDetails() const { return m_detail; }

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Builder for construction textDocument/completion items
    ///
    //////////////////////////////////////////////////////////////
    class Builder
    {
      public:
        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the label of the completion item
        ///
        /// @param label
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withLabel(const std::string &label);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the details of the completion item
        ///
        /// @param label
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withDetail(const std::string detail);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the text that will be inserted for the completion item
        ///
        /// @param insertedText
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withInsertedText(const std::string &insertedText);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the documentaiton for completion item
        ///
        /// @param documentation
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withDocumentation(const std::string &documentation);

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Sets the completion item kind
        ///
        /// @param completionItemKind
        ///
        /// @return Reference to the Builder for method chaining.
        ///
        //////////////////////////////////////////////////////////////
        Builder &withCompletionItemKind(const CompletionItemKind &completionItemKind);

      private:
        std::string m_label;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Additional detail about the completion item.
        ///
        //////////////////////////////////////////////////////////////
        std::string m_detail;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Text to ne inserted by the editor
        ///
        //////////////////////////////////////////////////////////////
        std::string m_documentation;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Text to ne inserted by the editor
        ///
        //////////////////////////////////////////////////////////////
        std::string m_insertedText;

        //////////////////////////////////////////////////////////////
        ///
        /// @brief Completion item kind (QUICK_FIX, SNIPPET...)
        ///
        //////////////////////////////////////////////////////////////
        CompletionItemKind m_completionItemKind;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Serializes the completion item to JSON format.
    ///
    /// @return Returns a JSON object representing the completion item,
    ///
    //////////////////////////////////////////////////////////////
    nlohmann::json toJson() const;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief The label of the completion item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_label;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Additional detail about the completion item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_detail;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Documentation or extended information about the item.
    ///
    //////////////////////////////////////////////////////////////
    std::string m_documentation;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Text to ne inserted by the editor
    ///
    //////////////////////////////////////////////////////////////
    std::string m_insertText;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Completion item kind (QUICK_FIX, SNIPPET...)
    ///
    //////////////////////////////////////////////////////////////
    CompletionItemKind m_completionItemKind;
};

} // namespace ls6502
