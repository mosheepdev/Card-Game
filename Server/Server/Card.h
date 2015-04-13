#pragma once
#include <cstdint>

#define MAX_CARDS_COUNT 5
#define MAX_CARDS_ON_DECK 4

enum CardType
{
    CARD_TYPE_MELEE = 1,
    CARD_TYPE_RANGED,
    CARD_TYPE_DEFENSE
};

enum FailReson
{
    INVALID_CARD_COUNT = 1,
    INVALID_CARD_ID
};

class Card
{
    private:
        uint32_t m_id;
        uint8_t m_type;
        uint64_t m_guid;
        uint8_t m_hp;
        uint8_t m_damage;
        uint8_t m_mana;
        uint8_t m_defense;
        bool m_isDefending;
        bool m_onDeck;

    public:
        Card(uint32_t id, uint8_t type, uint8_t hp, uint8_t damage, uint8_t mana, uint8_t defense);

        void Die();
        void Defend();
        void StopDefending();
        void DealDamage(uint32_t damage) { m_hp -= damage; }

        bool IsDefending() const { return m_isDefending; }
        bool IsAlive() const { return m_hp > 0; }
        uint32_t GetId() const { return m_id; }
        uint8_t GetType() const { return m_type; }
        uint8_t GetDamage() const { return m_damage; }
        uint8_t GetDefense() const { return m_defense; }
        uint8_t GetMana() const { return m_mana; }
        uint8_t GetHealth() const { return m_hp; }
        uint64_t GetGuid() const { return m_guid; }
        
        void SetGuid(uint64_t guid) { m_guid = guid; }
};
