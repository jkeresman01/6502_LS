#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <nlohmann/json.hpp>

#include "../Types/Position.h"
#include "../Types/TextDocumentIdentifier.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class TextDocumentPositionParams
///
/// @brief Represents parameters specifying a text document and a
///        position within that document.
///
//////////////////////////////////////////////////////////////
class TextDocumentPositionParams
{
public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Constructs TextDocumentPositionParams from JSON RPC requst
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    explicit TextDocumentPositionParams(const nlohmann::json& jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for TextDocumentIdentifier
    ///
    /// @return text document identifier
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentIdentifier getTextDocumentIdentifier() const
    {
        return m_textDocument;
    };

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Accessor method for Position
    ///
    /// @return position
    ///
    //////////////////////////////////////////////////////////////
    Position getPosition() const
    {
        return m_position;
    };

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Initializes the text document identifier from JSON data.
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setTextDocumentIdentifier(const nlohmann::json& jsonRPC);

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Initializes the position within the text document from JSON data.
    ///
    /// @param [in] jsonRPC
    ///
    //////////////////////////////////////////////////////////////
    void setPosition(const nlohmann::json& jsonRPC);

private:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Identifies the text document associated with this request.
    ///
    //////////////////////////////////////////////////////////////
    TextDocumentIdentifier m_textDocument;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Specifies the position within the text document.
    ///
    //////////////////////////////////////////////////////////////
    Position m_position;
};

} // namespace ls6502
