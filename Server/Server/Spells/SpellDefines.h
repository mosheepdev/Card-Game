#pragma once

enum SpellAuraEffects
{
    SPELL_AURA_EFFECT_DAMAGE = 0,
    SPELL_AURA_EFFECT_MODIFY_STAT,
    SPELL_AURA_EFFECT_HEAL,
    MAX_SPELL_AURA_VALUE
};

enum SpellAttributes
{
    SPELL_ATTRIBUTE_TARGET_MELEE    = 0x01,
    SPELL_ATTRIBUTE_TARGET_SELF     = 0x02,
    SPELL_ATTRIBUTE_APPLY_DEFENSE   = 0x04
};

enum SpellTargets
{
    TARGET_UNIT_TARGET_ENEMY = 0,
    TARGET_UNIT_TARGET_FRIEND,
    TARGET_UNIT_CLEAVE_ENEMY,
    MAX_SPELL_EFFECT_TARGET
};

