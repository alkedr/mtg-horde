#pragma once
#ifndef USE_PRECOMPILED
# include "precompiled.hpp"
#endif

#include "CardInGame.hpp"
#include "Cards.hpp"
#include <iostream>
#include <vector>
#include <cassert>


class CardsModel : public QAbstractTableModel {
public:
	virtual int rowCount(const QModelIndex & parent = QModelIndex()) const override {
		assert(cardsInGame_.size() < INT_MAX);

		if (parent.isValid()) return 0;
		return static_cast<int>(cardsInGame_.size());
	}

	virtual int columnCount(const QModelIndex & parent = QModelIndex()) const override {
		if (parent.isValid()) return 0;
		return 5;
	}

	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
		assert(section >= 0);

		if (role != Qt::DisplayRole) return QVariant();

		if (orientation == Qt::Horizontal) {
			assert(section < 5);
			static const char * headers[] = { "zone", "name", "type", "P/T", "text" };
			return headers[section];
		} else {
			return QString::number(section+1);
		}
	}

	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override {
		assert(index.row() >= 0);
		assert(index.column() >= 0);

		const auto & card = cardsInGame_.at(static_cast<std::size_t>(index.row()));
		if (role == Qt::DisplayRole) {
			switch (index.column()) {
				case 0: return QString::fromStdString(card.zoneStr());
				case 1:
					return QString::fromStdString(card.name()) + (
						(card.id() == 0 ? (" (" + QString::number(smallTokensCount) + ")") : QString()) +
						(card.id() == 1 ? (" (" + QString::number(  bigTokensCount) + ")") : QString())
					);
				case 2: return QString::fromStdString(card.type());
				case 3: return QString::fromStdString(card.ptStr());
				case 4: return QString::fromStdString(card.description());
			}
		} else if (role == Qt::BackgroundRole) {
			if (card.isToken()) return QBrush({255, 255, 255});
			switch (card.zone()) {
				case Zone::BATTLEFIELD: return QBrush({255, 255, 255});
				case Zone::GRAVEYARD: return QBrush({200, 200, 200});
				case Zone::EXILE: return QBrush({255, 200, 200});
				case Zone::HAND: return QVariant();
			}
		}
		return QVariant();
	}

	void addCard(Card::Id id, Zone zone = Zone::BATTLEFIELD) {
		if ((id < 2) && (zone == Zone::GRAVEYARD)) return;
		if (id == 0) {
			if (zone == Zone::BATTLEFIELD) smallTokensCount++;
		} else if (id == 1) {
			if (zone == Zone::BATTLEFIELD) bigTokensCount++;
		} else {
			beginInsertRows(QModelIndex(), rowCount(), rowCount());
			cardsInGame_.emplace_back(id, zone);
			endInsertRows();
		}

		sortCardsInGame();
	}

	void setCardZone(int row, Zone zone) {
		assert(row >= 0);

		int tokenIncrement = (zone == Zone::BATTLEFIELD) ? 1 : -1;

		if (row == 0) smallTokensCount += tokenIncrement; else
		if (row == 1) bigTokensCount += tokenIncrement; else
			cardsInGame_.at(static_cast<std::size_t>(row)).setZone(zone);

		if (smallTokensCount < 0) smallTokensCount = 0;
		if (bigTokensCount < 0) bigTokensCount = 0;
	
		sortCardsInGame();
	}

private:
	int smallTokensCount = 0;
	int bigTokensCount = 0;
	std::vector<CardInGame> cardsInGame_ = { {0, Zone::BATTLEFIELD}, {1, Zone::BATTLEFIELD} };

	void sortCardsInGame() {
		std::stable_sort(
			std::begin(cardsInGame_),
			std::end(cardsInGame_),
			[](const CardInGame & c1, const CardInGame & c2) { return c1.zone() < c2.zone(); }
		);
		emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
	}
};

