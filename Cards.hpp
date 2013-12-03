#pragma once


#include "Card.hpp"


#define CARD(ID, ...)                                                         \
case ID: {                                                                    \
	static const class C : public Card { public: C() { __VA_ARGS__ } } c;       \
	return c;                                                                   \
}


static const Card & card(Card::Id id) {
	switch (id) {

CARD(0,
	name = "Zombie Token";
	type = Card::Type::CREATURE;
	power = 3;
	toughness = 3;
)

CARD(1,
	name = "Zombie Giant Token";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 6;
	toughness = 6;
)

CARD(2,
	name = "Brain Gorgers";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 4;
	toughness = 2;
	text = "When you play Brain Gorgers, any player may sacrifice a creature. If a player does, counter Brain Gorgers.";
)

CARD(3,
	name = "Death Baron";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Skeleton creatures you control and other Zombie creatures you control get +1/+1 and have deathtouch.";
)

CARD(4,
	name = "Phyrexian Crusader";
	type = Card::Type::CREATURE;
	subtype = "Zombie Knight";
	power = 2;
	toughness = 2;
	text = "First strike, protection from red and from white. Infect.";
)

CARD(5,
	name = "Fleshbag Marauder";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 3;
	toughness = 1;
	text = "When Fleshbag Marauder enters the battlefield, each player sacrifices a creature.";
)

CARD(6,
	name = "Grave Titan";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 6;
	toughness = 6;
	text = "Deathtouch. Whenever Grave Titan enters the battlefield or attacks, put two 2/2 black Zombie creature tokens onto the battlefield.";
)

CARD(7,
	name = "Infectious Horror";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Whenever Infectious Horror attacks, each opponent loses 2 life.";
)

CARD(8,
	name = "Maalfeld Twins";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 4;
	toughness = 4;
	text = "When Maalfeld Twins dies, put two 2/2 black Zombie creature tokens onto the battlefield.";
)

CARD(9,
	name = "Lord of the Undead";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Other Zombie creatures get +1/+1.";
)

CARD(10,
	name = "Nested Ghoul";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 4;
	toughness = 2;
	text = "Whenever a source deals damage to Nested Ghoul, put a 2/2 black Zombie creature token onto the battlefield.";
)

CARD(11,
	name = "Noxious Ghoul";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 3;
	toughness = 3;
	text = "Whenever Noxious Ghoul or another Zombie comes into play, all non-Zombie creatures get -1/-1 until end of turn.";
)

CARD(12,
	name = "Order of Yawgmoth";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Fear. Whenever Order of Yawgmoth deals damage to a player, that player discards a card.";
)

CARD(13,
	name = "Liliana's Reaver";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 4;
	toughness = 3;
	text = "Deathtouch. Whenever Liliana's Reaver deals combat damage to a player, that player discards a card and you put a 2/2 black Zombie creature token onto the battlefield tapped.";
)

CARD(14,
	name = "Mikaeus, the Unhallowed";
	supertype = Card::Supertype::LEGENDARY;
	type = Card::Type::CREATURE;
	subtype = "Zombie Cleric";
	power = 5;
	toughness = 5;
	text = "Intimidate. Whenever a Human deals damage to you, destroy it. Other non-Human creatures you control get +1/+1 and have undying.";
)

CARD(15,
	name = "Severed Legion";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 2;
	text = "Fear";
)

CARD(16,
	name = "Soulless One";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 0;
	toughness = 0;
	text = "Soulless One's power and toughness are each equal to the number of Zombies in play plus the number of Zombie cards in all graveyards.";
)

CARD(17,
	name = "Unbreathing Horde";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 0;
	toughness = 0;
	text = "Unbreathing Horde enters the battlefield with a +1/+1 counter on it for each other Zombie you control and each Zombie card in your graveyard. If Unbreathing Horde would be dealt damage, prevent that damage and remove a +1/+1 counter from it.";
)

CARD(18,
	name = "Undead Warchief";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 1;
	toughness = 1;
	text = "Zombie spells you cast cost 1 less to cast. Zombie creatures you control get +2/+1.";
)

CARD(19,
	name = "Vengeful Dead";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 3;
	toughness = 2;
	text = "Whenever Vengeful Dead or another Zombie is put into a graveyard from play, each opponent loses 1 life.";
)

CARD(20,
	name = "Geralf's Messenger";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 3;
	toughness = 2;
	text = "Geralf's Messenger enters the battlefield tapped. When Geralf's Messenger enters the battlefield, target opponent loses 2 life. Undying.";
)

CARD(21,
	name = "Wight of Precinct Six";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 1;
	toughness = 1;
	text = "Wight of Precinct Six gets +1/+1 for each creature card in your opponents' graveyards.";
)

CARD(22,
	name = "Yixlid Jailer";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 2;
	toughness = 1;
	text = "Cards in graveyards lose all abilities.";
)

CARD(23,
	name = "Zombie Goliath";
	type = Card::Type::CREATURE;
	subtype = "Zombie";
	power = 3;
	toughness = 5;
	text = "Whenever a creature dealt damage by Dread Slaver this turn dies, return it to the battlefield under your control. That creature is a black Zombie in addition to its other colors and types.";
)


CARD(24,
	name = "Bad Moon";
	type = Card::Type::ENCHANTMENT;
	text = "Black creatures get +1/+1.";
)

CARD(25,
	name = "Call to the Grave";
	type = Card::Type::ENCHANTMENT;
	text = "At the beginning of each player's upkeep, that player sacrifices a non-Zombie creature. At end of turn, if no creatures are in play, sacrifice Call to the Grave.";
)

CARD(26,
	name = "Endless Ranks of the Dead";
	type = Card::Type::ENCHANTMENT;
	text = "At the beginning of your upkeep, put X 2/2 black Zombie creature tokens onto the battlefield, where X is half the number of Zombies you control, rounded down.";
)

CARD(27,
	name = "Grave Pact";
	type = Card::Type::ENCHANTMENT;
	text = "Whenever a creature you control is put into a graveyard from play, each other player sacrifices a creature.";
)

CARD(28,
	name = "No Mercy";
	type = Card::Type::ENCHANTMENT;
	text = "Whenever a creature successfully deals damage to you, destroy it.";
)

CARD(29,
	name = "Painful Quandary";
	type = Card::Type::ENCHANTMENT;
	text = "Whenever an opponent casts a spell, that player loses 5 life unless he or she discards a card.";
)

CARD(30,
	name = "Army of the Damned";
	type = Card::Type::SORCERY;
	text = "Put thirteen 2/2 black Zombie creature tokens onto the battlefield tapped. Flashback 7+3black";
)

CARD(31,
	name = "Blood Tithe";
	type = Card::Type::SORCERY;
	text = "Each opponent loses 3 life. You gain life equal to the life lost this way.";
)

CARD(32,
	name = "Damnation";
	type = Card::Type::SORCERY;
	text = "Destroy all creatures. They can't be regenerated.";
)

CARD(33,
	name = "Delirium Skeins";
	type = Card::Type::SORCERY;
	text = "Each player discards three cards.";
)

CARD(34,
	name = "Living Death";
	type = Card::Type::SORCERY;
	text = "Set aside all creature cards in all graveyards. Then put each creature that's in play into its owner's graveyard. Then put each creature card set aside this way into play under its owner's control.";
)

CARD(35,
	name = "Moan of the Unhallowed";
	type = Card::Type::SORCERY;
	text = "Put two 2/2 black Zombie creature tokens onto the battlefield. Flashback 5+2black";
)

CARD(36,
	name = "Plague Wind";
	type = Card::Type::SORCERY;
	text = "Destroy all creatures you don't control. They can't be regenerated.";
)

CARD(37,
	name = "Shrivel";
	type = Card::Type::SORCERY;
	text = "All creatures get -1/-1 until end of turn.";
)

CARD(38,
	name = "Syphon Flesh";
	type = Card::Type::SORCERY;
	text = "Each other player sacrifices a creature. You put a 2/2 black Zombie creature token onto the battlefield for each creature sacrificed this way.";
)

CARD(39,
	name = "Twilight's Call";
	type = Card::Type::SORCERY;
	text = "You may play Twilight's Call any time you could play an instant if you pay 2 more to play it. Each player returns all creature cards from his or her graveyard to play.";
)

CARD(40,
	name = "Unnerve";
	type = Card::Type::SORCERY;
	text = "Each opponent discards two cards from his or her hand.";
)

CARD(41,
	name = "Zombie Apocalypse";
	type = Card::Type::SORCERY;
	text = "Return all Zombie creature cards from your graveyard to the battlefield tapped, then destroy all Humans.";
)

default:
	const static Card c;
	return c;

	}
}
