#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "ServerCapabilities.h"

namespace ls6502
{

//////////////////////////////////////////////////////////////
///
/// @class ServerCapabilitiesDirector
///
/// @brief Responsible for configuring default server
///        capabilities for the language server.
///
//////////////////////////////////////////////////////////////
class ServerCapabilitiesDirector
{
  public:
    //////////////////////////////////////////////////////////////
    ///
    /// @brief Deleted default constructor to prevent instantiation.
    ///
    //////////////////////////////////////////////////////////////
    ServerCapabilitiesDirector() = delete;

    //////////////////////////////////////////////////////////////
    ///
    /// @brief Configures default server capabilities
    ///        using the provided builder.
    ///
    /// @param [in] serverCapabilitesBuilder
    ///
    //////////////////////////////////////////////////////////////
    static void constructDefaultServerCapabilities(ServerCapabilities::Builder &serverCapabilitesBuilder)
    {
        serverCapabilitesBuilder.withTextDocumentSyncKind(TextDocumentSyncKind::FULL)
            .withHoverSupport(true)
            .withSnippetSupport(true)
            .withCompletionSupport(true)
            .withDefinitionSupport(true)
            .withCodeActionSupport(true);
    }
};

} // namespace ls6502
