#pragma once

#include <vector>
#include "Card.hpp"


namespace decks {
namespace _ {

struct DeckEntry {
	Card::Id cardId;
	uint8_t count;

	DeckEntry(Card::Id cardId_, uint8_t count_ = 1) : cardId(cardId_), count(count_) {}
};


static std::vector<Card::Id> generateLibrary(const DeckEntry * deckList, std::size_t entryCount) {
	std::vector<Card::Id> res;
	for (std::size_t i = 0; i < entryCount; i++) {
		for (uint32_t j = 0; j < deckList[i].count; j++) {
			res.push_back(deckList[i].cardId);
		}
	}
	std::random_shuffle(res.begin(), res.end());
	return res;
}

}
}


#define DECK(NAME, ...)                                     \
namespace decks {                                           \
static std::vector<Card::Id> NAME () {                             \
	const static _::DeckEntry __deckList[] = { __VA_ARGS__ };    \
	return generateLibrary(__deckList, sizeof(__deckList) / sizeof(__deckList[0]));   \
}                                                           \
}



DECK(zombies,
	{ 0, 55 }, { 1, 5 },
	2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
	12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
	32, 33, 34, 35, 36, 37, 38, 39, 40, 41
)

