#pragma once
#include "ByteBuffer.h"

#define MAX_PACKET_SIZE 10000

enum CMSGPackets
{
    CMSG_INIT_PACKET = 1,
    CMSG_CHAT_MESSAGE,
    CMSG_SELECTED_CARDS,
    CMSG_CARD_ACTION,
    CMSG_DEFEND_SELF
};

enum SMSGPackets
{
    SMSG_INIT_RESPONSE = 1,
    SMSG_AVAILABLE_CARDS,
    SMSG_CHAT_MESSAGE,
    SMSG_WHISPER_FAILED,
    SMSG_SELECT_CARDS_FAILED,
    SMSG_SELECT_CARDS_WAIT_FOR_ANOTHER_PLAYER,
    SMSG_SELECT_CARDS,
    SMSG_DECK_CARDS,
    SMSG_ACTIVE_PLAYER,
    SMSG_PLAYER_DISCONNECTED,
    SMSG_ATTACK_RESULT,
    SMSG_END_GAME,
    SMSG_CARD_STAT_CHANGED,
    SMSG_SPELL_CAST_FAILED,
    SMSG_SPELL_DAMAGE,
    SMSG_APPLY_AURA,
    SMSG_SPELL_PERIODIC_DAMAGE,
    SMSG_CARD_HEALED
};

class Packet : public ByteBuffer
{
    public:
        Packet(uint32_t opcodeNumber);
        Packet(std::string const& data);

        void Initialize(uint32_t opcodeNumber);
        void AppendBuffer(ByteBuffer const& value) { append((uint8_t const*)&value.GetStorage()[0], value.GetStorage().size()); }
};