#include "JUstAnLSPClientService.h"

#include "../Utils/Logger.h"

namespace justanlsp
{

uint32_t Ls6502ClientService::m_clientId = 0;

void Ls6502ClientService::registerClient(const Ls6502Client &client)
{
    m_registeredClients.emplace(++m_clientId, client);

    LS_6502_INFO(STR("Client with ID: %u, ( %s ) has been successfully registered!", m_clientId,
                  client.getInfo().c_str()));
}

Ls6502Client Ls6502ClientService::getClientById(uint32_t clientId) const
{
    auto it = m_registeredClients.find(clientId);

    if (it == m_registeredClients.end())
    {
        LS_6502_ERROR(STR("There are no registered clients with ID: %u!", clientId));
    }

    return it->second;
}

Ls6502ClientService &Ls6502ClientService::getInstance()
{
    static Ls6502ClientService instance;
    return instance;
}

} // namespace justanlsp
