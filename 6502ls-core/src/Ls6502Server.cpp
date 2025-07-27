////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Ls6502Server.h"
#include <memory>
#include <string>

#include "../Common/ClassRegistry.h"
#include "../Config/ConfigurationManager.h"
#include "../Rpc/Rpc.h"
#include "../Utils/Logger.h"
#include "../Utils/MessageUtil.h"
#include "Ls6502Facade.h"

namespace ls6502
{


////////////////////////////////////////////////////////////
void Ls6502Server::init()
{
    LS_6502_DEBUG("Initializing Ls6502 server");

    initConfigurationManager();
    registerProviders();

    LS_6502_DEBUG("Ls6502 server successfully initliazed");
}


////////////////////////////////////////////////////////////
void Ls6502Server::initConfigurationManager()
{
    LS_6502_DEBUG("Initializing configuration manager");

    ConfigurationManager::getInstance()->init();

    LS_6502_DEBUG("Configuration manager successfully initialzed");
}


////////////////////////////////////////////////////////////
void Ls6502Server::registerProviders()
{
    LS_6502_DEBUG("Registering all providers in class registry");

    REGISTER_CLASS(ICodeActionsProvider, CodeActionProvider)
    REGISTER_CLASS(ICodeActionsProvider, FakeCodeActionProvider)

    REGISTER_CLASS(ICompletionProvider, CompletionProvider)
    REGISTER_CLASS(ICompletionProvider, FakeCompletionProvider)

    REGISTER_CLASS(IDefinitionProvider, DefinitionProvider)
    REGISTER_CLASS(IDefinitionProvider, FakeDefinitionProvider)

    REGISTER_CLASS(IDiagnosticsProvider, DiagnosticsProvider)
    REGISTER_CLASS(IDiagnosticsProvider, FakeDiagnosticsProvider)

    REGISTER_CLASS(IHoverProvider, HoverProvider)
    REGISTER_CLASS(IHoverProvider, FakeHoverProvider)

    REGISTER_CLASS(ISnippetProvider, SnippetProvider)
    REGISTER_CLASS(ISnippetProvider, FakeSnippetProvider)

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
        handleRequest(Rpc::receive());
    }
}


////////////////////////////////////////////////////////////
void Ls6502Server::handleRequest(const std::string& request)
{
    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
    m_6502Facade->handleRequest(jsonRPC);
}


} // namespace ls6502
