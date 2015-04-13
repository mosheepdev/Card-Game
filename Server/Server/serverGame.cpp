#include "serverGame.h"
#include "Player.h"
#include "../Shared/SharedDefines.h"

unsigned int ServerGame::m_clientId = 1;

// Looking for new connections and data from connected clients
void ServerGame::update()
{
    // get new clients
    if (m_network.AcceptNewClient(m_clientId))
    {
        DEBUG_LOG("Client %d has been connected to the server\n", m_clientId);
        m_clientId++;
    }

    receiveFromClients();
}

// Receive data from all clients
void ServerGame::receiveFromClients()
{
    PlayerMap::iterator iter = m_network.GetPlayers().begin();
    while (iter != m_network.GetPlayers().end())
    {
        // get data for that client
        int data_length = m_network.ReceiveData(iter->second, m_networkData);
        if (!data_length)
        {
            Player* player = iter->second;
            iter = m_network.GetPlayers().erase(iter);
            player->Disconnect();
            if (player->GetGame()->IsEmpty())
                delete player->GetGame();
            continue;
        }

        // invalid packet sended
        if (data_length < 2)
        {
            iter++;
            continue;
        }

        iter->second->ReceivePacket(data_length, m_networkData);
        iter++;
    }
}

// Infinite server pdate loop
void ServerGame::Loop()
{
    while (true)
        update();
}