#pragma once

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @enum TextDocumentSyncKind
///
/// @brief Defines how the host (editor) should sync document
///        changes to the Ls6502 server
///
///
//////////////////////////////////////////////////////////////
enum class TextDocumentSyncKind
{
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Documents should not be synced at all.
    ///
    //////////////////////////////////////////////////////////////
    NONE = 0,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Documents are synced by always sending the
    ///        full content of the document
    ///
    //////////////////////////////////////////////////////////////
    FULL = 1,

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Documents are synced by sending the full
    ///        content on open. After that only incremental updates
    ///        to the document are sent.
    ///
    //////////////////////////////////////////////////////////////
    INCREMENTAL = 2,
};

} // namespace ls6502
