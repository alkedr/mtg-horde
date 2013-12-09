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


template<class ForwardIterator>
static std::vector<Card::Id> generateLibrary(ForwardIterator begin, ForwardIterator end) {
	std::vector<Card::Id> res;
	std::for_each(begin, end, [&res](const DeckEntry & de) {
		for (decltype(de.count) i = 0; i < de.count; i++) res.push_back(de.cardId);
	});
	std::random_shuffle(res.begin(), res.end());
	return res;
}

}
}


#define DECK(NAME, ...)                                                               \
namespace decks {                                                                     \
static std::vector<Card::Id> NAME () {                                                \
	const static _::DeckEntry __deckList[] = { __VA_ARGS__ };                           \
	return generateLibrary(std::begin(__deckList), std::end(__deckList));               \
}                                                                                     \
}



DECK(zombies,
	{ 0, 55 }, { 1, 5 },
	2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
	12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
	22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
	32, 33, 34, 35, 36, 37, 38, 39, 40, 41
)

