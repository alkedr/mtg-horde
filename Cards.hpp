#pragma once


#include "Card.hpp"


#define CARD(ID, ...)                                                         \
case ID: {                                                                    \
	static const class C : public Card { public: C() { __VA_ARGS__ } } c;       \
	return c;                                                                   \
}

#define CREATURE(ID, ...)    CARD(ID, type = Card::Type::CREATURE;    __VA_ARGS__)
#define ENCHANTMENT(ID, ...) CARD(ID, type = Card::Type::ENCHANTMENT; __VA_ARGS__)
#define SORCERY(ID, ...)     CARD(ID, type = Card::Type::SORCERY;     __VA_ARGS__)


static const Card & card(Card::Id id) {
	switch (id) {

CREATURE(0,
	name = "Zombie Token";
	subtype = "Zombie";
	power = 3;
	toughness = 3;
)

CREATURE(1,
	name = "Zombie Giant Token";
	subtype = "Zombie";
	power = 6;
	toughness = 6;
)

CREATURE(2,
	name = "Brain Gorgers";
	subtype = "Zombie";
	power = 4;
	toughness = 2;
	text = "When you play Brain Gorgers, any player may sacrifice a creature. If a player does, counter Brain Gorgers.";
)

CREATURE(3,
	name = "Death Baron";
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Skeleton creatures you control and other Zombie creatures you control get +1/+1 and have deathtouch.";
)

CREATURE(4,
	name = "Phyrexian Crusader";
	subtype = "Zombie Knight";
	power = 2;
	toughness = 2;
	text = "First strike, protection from red and from white. Infect.";
)

CREATURE(5,
	name = "Fleshbag Marauder";
	subtype = "Zombie";
	power = 3;
	toughness = 1;
	text = "When Fleshbag Marauder enters the battlefield, each player sacrifices a creature.";
)

CREATURE(6,
	name = "Grave Titan";
	subtype = "Zombie";
	power = 6;
	toughness = 6;
	text = "Deathtouch. Whenever Grave Titan enters the battlefield or attacks, put two 2/2 black Zombie creature tokens onto the battlefield.";
)

CREATURE(7,
	name = "Infectious Horror";
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Whenever Infectious Horror attacks, each opponent loses 2 life.";
)

CREATURE(8,
	name = "Maalfeld Twins";
	subtype = "Zombie";
	power = 4;
	toughness = 4;
	text = "When Maalfeld Twins dies, put two 2/2 black Zombie creature tokens onto the battlefield.";
)

CREATURE(9,
	name = "Lord of the Undead";
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Other Zombie creatures get +1/+1.";
)

CREATURE(10,
	name = "Nested Ghoul";
	subtype = "Zombie";
	power = 4;
	toughness = 2;
	text = "Whenever a source deals damage to Nested Ghoul, put a 2/2 black Zombie creature token onto the battlefield.";
)

CREATURE(11,
	name = "Noxious Ghoul";
	subtype = "Zombie";
	power = 3;
	toughness = 3;
	text = "Whenever Noxious Ghoul or another Zombie comes into play, all non-Zombie creatures get -1/-1 until end of turn.";
)

CREATURE(12,
	name = "Order of Yawgmoth";
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Fear. Whenever Order of Yawgmoth deals damage to a player, that player discards a card.";
)

CREATURE(13,
	name = "Liliana's Reaver";
	subtype = "Zombie";
	power = 4;
	toughness = 3;
	text = "Deathtouch. Whenever Liliana's Reaver deals combat damage to a player, that player discards a card and you put a 2/2 black Zombie creature token onto the battlefield tapped.";
)

CREATURE(14,
	name = "Mikaeus, the Unhallowed";
	supertype = Card::Supertype::LEGENDARY;
	subtype = "Zombie Cleric";
	power = 5;
	toughness = 5;
	text = "Intimidate. Whenever a Human deals damage to you, destroy it. Other non-Human creatures you control get +1/+1 and have undying.";
)

CREATURE(15,
	name = "Severed Legion";
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Fear";
)

CREATURE(16,
	name = "Soulless One";
	subtype = "Zombie";
	power = 0;
	toughness = 0;
	text = "Soulless One's power and toughness are each equal to the number of Zombies in play plus the number of Zombie cards in all graveyards.";
)

CREATURE(17,
	name = "Unbreathing Horde";
	subtype = "Zombie";
	power = 0;
	toughness = 0;
	text = "Unbreathing Horde enters the battlefield with a +1/+1 counter on it for each other Zombie you control and each Zombie card in your graveyard. If Unbreathing Horde would be dealt damage, prevent that damage and remove a +1/+1 counter from it.";
)

CREATURE(18,
	name = "Undead Warchief";
	subtype = "Zombie";
	power = 1;
	toughness = 1;
	text = "Zombie spells you cast cost 1 less to cast. Zombie creatures you control get +2/+1.";
)

CREATURE(19,
	name = "Vengeful Dead";
	subtype = "Zombie";
	power = 3;
	toughness = 2;
	text = "Whenever Vengeful Dead or another Zombie is put into a graveyard from play, each opponent loses 1 life.";
)

CREATURE(20,
	name = "Geralf's Messenger";
	subtype = "Zombie";
	power = 3;
	toughness = 2;
	text = "Geralf's Messenger enters the battlefield tapped. When Geralf's Messenger enters the battlefield, target opponent loses 2 life. Undying.";
)

CREATURE(21,
	name = "Wight of Precinct Six";
	subtype = "Zombie";
	power = 1;
	toughness = 1;
	text = "Wight of Precinct Six gets +1/+1 for each creature card in your opponents' graveyards.";
)

CREATURE(22,
	name = "Yixlid Jailer";
	subtype = "Zombie";
	power = 2;
	toughness = 1;
	text = "Cards in graveyards lose all abilities.";
)

CREATURE(23,
	name = "Zombie Goliath";
	subtype = "Zombie";
	power = 3;
	toughness = 5;
	text = "Whenever a creature dealt damage by Dread Slaver this turn dies, return it to the battlefield under your control. That creature is a black Zombie in addition to its other colors and types.";
)


ENCHANTMENT(24,
	name = "Bad Moon";
	text = "Black creatures get +1/+1.";
)

ENCHANTMENT(25,
	name = "Call to the Grave";
	text = "At the beginning of each player's upkeep, that player sacrifices a non-Zombie creature. At end of turn, if no creatures are in play, sacrifice Call to the Grave.";
)

ENCHANTMENT(26,
	name = "Endless Ranks of the Dead";
	text = "At the beginning of your upkeep, put X 2/2 black Zombie creature tokens onto the battlefield, where X is half the number of Zombies you control, rounded down.";
)

ENCHANTMENT(27,
	name = "Grave Pact";
	text = "Whenever a creature you control is put into a graveyard from play, each other player sacrifices a creature.";
)

ENCHANTMENT(28,
	name = "No Mercy";
	text = "Whenever a creature successfully deals damage to you, destroy it.";
)

ENCHANTMENT(29,
	name = "Painful Quandary";
	text = "Whenever an opponent casts a spell, that player loses 5 life unless he or she discards a card.";
)

SORCERY(30,
	name = "Army of the Damned";
	text = "Put thirteen 2/2 black Zombie creature tokens onto the battlefield tapped. Flashback 7+3black";
)

SORCERY(31,
	name = "Blood Tithe";
	text = "Each opponent loses 3 life. You gain life equal to the life lost this way.";
)

SORCERY(32,
	name = "Damnation";
	text = "Destroy all creatures. They can't be regenerated.";
)

SORCERY(33,
	name = "Delirium Skeins";
	text = "Each player discards three cards.";
)

SORCERY(34,
	name = "Living Death";
	text = "Set aside all creature cards in all graveyards. Then put each creature that's in play into its owner's graveyard. Then put each creature card set aside this way into play under its owner's control.";
)

SORCERY(35,
	name = "Moan of the Unhallowed";
	text = "Put two 2/2 black Zombie creature tokens onto the battlefield. Flashback 5+2black";
)

SORCERY(36,
	name = "Plague Wind";
	text = "Destroy all creatures you don't control. They can't be regenerated.";
)

SORCERY(37,
	name = "Shrivel";
	text = "All creatures get -1/-1 until end of turn.";
)

SORCERY(38,
	name = "Syphon Flesh";
	text = "Each other player sacrifices a creature. You put a 2/2 black Zombie creature token onto the battlefield for each creature sacrificed this way.";
)

SORCERY(39,
	name = "Twilight's Call";
	text = "You may play Twilight's Call any time you could play an instant if you pay 2 more to play it. Each player returns all creature cards from his or her graveyard to play.";
)

SORCERY(40,
	name = "Unnerve";
	text = "Each opponent discards two cards from his or her hand.";
)

SORCERY(41,
	name = "Zombie Apocalypse";
	text = "Return all Zombie creature cards from your graveyard to the battlefield tapped, then destroy all Humans.";
)

default:
	const static Card c;
	return c;

	}
}
