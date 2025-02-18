#pragma once

#include "ServerCapabilities.h"

namespace ls6502
{
class ServerCapabilitiesDirector
{
  public:
    ServerCapabilitiesDirector() = delete;

    static void createDefaultServerCapabilities(ServerCapabilities::Builder &serverCapabilitesBuilder)
    {
        serverCapabilitesBuilder.withTextDocumentSyncKind(TextDocumentSyncKind::FULL)
            .withHoverSupport(true)
            .withSnippetSupport(true)
            .withCompletionSupport(true)
            .withCodeActionSupport(true);
    }
};
} // namespace ls6502
