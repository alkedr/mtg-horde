#pragma once

#include <cstdint>
#include <string>


class Card {
public:
	using Id = uint16_t;

	class Supertype {
	public:
		static const constexpr char * NONE = "";
		static const constexpr char * LEGENDARY = "Legendary";
	};

	class Type {
	public:
		static const constexpr char * NONE = "";
		static const constexpr char * ARTIFACT = "Artifact";
		static const constexpr char * CREATURE = "Creature";
		static const constexpr char * ENCHANTMENT = "Enchantment";
		static const constexpr char * INSTANT = "Instant";
		static const constexpr char * LAND = "Land";
		static const constexpr char * PLANESWALKER = "Planeswalker";
		static const constexpr char * SORCERY = "Sorcery";
	};


	Card() {
	}

	const char * name = "";
	int power = 0;
	int toughness = 0;
	const char * text = "";
	const char * supertype = Supertype::NONE;
	const char * type = Type::NONE;
	const char * subtype = "";
};

