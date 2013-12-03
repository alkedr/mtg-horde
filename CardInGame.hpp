#pragma once

#include "Card.hpp"
#include "Cards.hpp"

#include <string>



enum class Zone : uint8_t {
	HAND,
	BATTLEFIELD,
	GRAVEYARD,
	EXILE
};


class CardInGame {
public:
	CardInGame(Card::Id id, Zone zone) : id_(id), zone_(zone) {
	}

	Card::Id id() const {
		return id_;
	}

	std::string name() const {
		return card(id_).name;
	}

	std::string type() const {
		return card(id_).type;
	}

	std::string zoneStr() const {
		switch (zone_) {
			case Zone::HAND: return "hand";
			case Zone::BATTLEFIELD: return "battlefield";
			case Zone::GRAVEYARD: return "graveyard";
			case Zone::EXILE: return "exile";
		}
	}

	Zone zone() const {
		return zone_;
	}

	void setZone(Zone value) {
		zone_ = value;
	}

	std::string ptStr() const {
		if (card(id_).type != Card::Type::CREATURE) return "";
		return std::to_string(card(id_).power) + "/" + std::to_string(card(id_).toughness);
	}

	std::string description() const {
		return card(id_).text;
	}

private:
	Card::Id id_;
	Zone zone_ = Zone::BATTLEFIELD;
};

