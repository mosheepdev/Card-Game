﻿using Client.Enums;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Client.Game
{
    public class SpellTargetSelector
    {
        private static readonly Func<Player, Player, SpellAttributes, IEnumerable<UInt64>>[] targetSelectors =
        {
            HandleTargetUnitTargetEnemy,    // TARGET_UNIT_TARGET_ENEMY
            HandleTargetUnitFriend,         // TARGET_UNIT_TARGET_FRIEND
            HandleTargetUnitCleaveEnemy,    // TARGET_UNIT_CLEAVE_ENEMY
            HandleTargetUnitSelf            // TARGET_UNIT_SELF
        };

        public static Func<Player, Player, SpellAttributes, IEnumerable<UInt64>> GetTargetSelector(byte target)
        {
            if (target >= (byte)SpellTargets.MaxSpellTarget)
                return null;

            return targetSelectors[target];
        }

        private static IEnumerable<UInt64> HandleTargetUnitTargetEnemy(Player player, Player enemy, SpellAttributes attributes)
        {
            if ((attributes & SpellAttributes.TargetMelee) == SpellAttributes.None)
                return enemy.CardDeck.Where(x => x != null).Select(x => x.Guid);

            var card = enemy.CardDeck.ElementAtOrDefault(player.ActiveCardPosition);
            return card != null ? new List<UInt64>() { card.Guid } : new List<UInt64>();
        }

        private static IEnumerable<UInt64> HandleTargetUnitFriend(Player player, Player enemy, SpellAttributes attributes)
        {
            var query = player.CardDeck.Where(x => x != null);
            if ((attributes & SpellAttributes.TargetExcludeSelf) != SpellAttributes.None)
                query = query.Where(x => x.Guid != player.ActiveCard?.Guid);

            return query.Select(x => x.Guid);
        }

        private static IEnumerable<UInt64> HandleTargetUnitCleaveEnemy(Player player, Player enemy, SpellAttributes attributes) => HandleTargetUnitTargetEnemy(player, enemy, attributes);

        private static IEnumerable<UInt64> HandleTargetUnitSelf(Player player, Player enemy, SpellAttributes attributes)
        {
            var card = player.ActiveCard;
            return card == null ? new List<UInt64>() : new List<UInt64>() { card.Guid };
        }
    }
}
