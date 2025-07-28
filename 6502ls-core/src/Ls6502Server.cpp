////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////


#include <memory>
#include <string>

#include "ls6502/core/Ls6502Server.h"

#include "ls6502/infra/common/ClassRegistry.h"
#include "ls6502/infra/config/ConfigurationManager.h"
#include "ls6502/rpc/Rpc.h"
#include "ls6502/infra/logging/Logger.h"
#include "ls6502/utils/MessageUtil.h"

#include "ls6502/core/Ls6502Facade.h"

#include "ls6502/diagnostics/interface/IDiagnosticsProvider.h"
#include "ls6502/diagnostics/include/DiagnosticsProvider.h"
#include "ls6502/diagnostics/include/FakeDiagnosticsProvider.h"

#include "ls6502/codeaction/interface/ICodeActionsProvider.h"
#include "ls6502/codeaction/include/CodeActionProvider.h"
#include "ls6502/codeaction/include/FakeCodectionsProvider.h"

#include "ls6502/completion/interface/ICompletionProvider.h"
#include "ls6502/completion/include/InstructionSetCompletionProvider.h"
#include "ls6502/completion/include/FakeCompletionProvider.h"

#include "ls6502/definition/interface/IDefinitionProvider.h"
#include "ls6502/definition/include/DefinitionProvider.h"
#include "ls6502/definition/include/FakeDefinitionProvider.h"

#include "ls6502/hover/interface/IHoverProvider.h"
#include "ls6502/hover/include/InstructionSet6502HoverProvider.h"
#include "ls6502/hover/include/FakeHoverProvider.h"

#include "ls6502/snippets/interface/ISnippetProvider.h"
#include "ls6502/snippets/interface/SnipetProvider.h"
#include "ls6502/snippets/interface/FakeSnippetProvider.h"

namespace ls6502::core
{

////////////////////////////////////////////////////////////
void Ls6502Server::init()
{
    LS_6502_DEBUG("Initializing Ls6502 server");

    initConfigurationManager();
    registerProviders();

    LS_6502_DEBUG("Ls6502 server successfully initialized");
}


////////////////////////////////////////////////////////////
void Ls6502Server::initConfigurationManager()
{
    LS_6502_DEBUG("Initializing configuration manager");

    infra::ConfigurationManager::getInstance()->init();

    LS_6502_DEBUG("Configuration manager successfully initialized");
}


////////////////////////////////////////////////////////////
void Ls6502Server::registerProviders()
{
    LS_6502_DEBUG("Registering all providers in class registry");

    REGISTER_CLASS(codeaction::ICodeActionsProvider, codeaction::CodeActionProvider)
    REGISTER_CLASS(codeaction::ICodeActionsProvider, codeaction::FakeCodeActionProvider)

    REGISTER_CLASS(completion::ICompletionProvider, completion::InstructionSetCompletionProvider)
    REGISTER_CLASS(completion::ICompletionProvider, completion::FakeCompletionProvider)

    REGISTER_CLASS(definition::IDefinitionProvider, definition::DefinitionProvider)
    REGISTER_CLASS(definition::IDefinitionProvider, definition::FakeDefinitionProvider)

    REGISTER_CLASS(diagnostics::IDiagnosticsProvider, diagnostics::DiagnosticsProvider)
    REGISTER_CLASS(diagnostics::IDiagnosticsProvider, diagnostics::FakeDiagnosticsProvider)

    REGISTER_CLASS(hover::IHoverProvider, hover::InstructionSet6502HoverProvider)
    REGISTER_CLASS(hover::IHoverProvider, hover::FakeHoverProvider)

    REGISTER_CLASS(snippets::ISnippetProvider, snippets::SnippetProvider)
    REGISTER_CLASS(snippets::ISnippetProvider, snippets::FakeSnippetProvider)

    LS_6502_DEBUG("All providers successfully registered");
}

////////////////////////////////////////////////////////////
void Ls6502Server::shutdown()
{
    LS_6502_DEBUG("Successful shutdown of Ls6502 server");
}


////////////////////////////////////////////////////////////
void Ls6502Server::run()
{
    LS_6502_DEBUG("Ls6502 server successfully started");

    for (;;)
    {
        handleRequest(rpc::Rpc::receive());
    }
}


////////////////////////////////////////////////////////////
void Ls6502Server::handleRequest(const std::string& request)
{
    nlohmann::json jsonRPC = utils::MessageUtil::tryParse(request);
    m_6502Facade->handleRequest(jsonRPC);
}

} // namespace ls6502::core

