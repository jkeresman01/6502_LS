////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include "Ls6502Server.h"
#include <memory>
#include <string>

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

    ConfigurationManager::getInstance()->load();
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
void Ls6502Server::handleRequest(const std::string &request)
{
    nlohmann::json jsonRPC = MessageUtil::tryParse(request);
    m_6502Facade->handleRequest(jsonRPC);
}

} // namespace ls6502
