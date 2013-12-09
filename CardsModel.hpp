#pragma once
#ifndef USE_PRECOMPILED
# include "precompiled.hpp"
#endif

#include "CardInGame.hpp"
#include "Cards.hpp"
#include <iostream>
#include <vector>


class CardsModel : public QAbstractTableModel {
public:
	virtual int rowCount(const QModelIndex & parent = QModelIndex()) const override {
		if (parent.isValid()) return 0;
		return (int)(cardsInGame_.size() + 2);
	}

	virtual int columnCount(const QModelIndex & parent = QModelIndex()) const override {
		if (parent.isValid()) return 0;
		return 5;
	}

	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
		if (role != Qt::DisplayRole) return QVariant();

		if (orientation == Qt::Horizontal) {
			switch (section) {
				case 0: return QString("zone");
				case 1: return QString("name");
				case 2: return QString("type");
				case 3: return QString("P/T");
				case 4: return QString("text");
			}
		} else {
			return QString::number(section+1);
		}
		return QVariant();
	}

	virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override {
		std::size_t cardIndex = static_cast<std::size_t>(index.row());
		if (role == Qt::DisplayRole) {
			if (cardIndex == 0) {
				if (index.column() == 0) return "battlefield";
				if (index.column() == 1) return QString(card(0).name) + " (" + QString::number(smallTokensCount) + ")";
				if (index.column() == 2) return "Creature";
				if (index.column() == 3) return "3/3";
				if (index.column() == 4) return "";
			} else if (cardIndex == 1) {
				if (index.column() == 0) return "battlefield";
				if (index.column() == 1) return QString(card(1).name) + " (" + QString::number(bigTokensCount) + ")";
				if (index.column() == 2) return "Creature";
				if (index.column() == 3) return "6/6";
				if (index.column() == 4) return "";
			}

			switch (index.column()) {
				case 0: return QString::fromStdString(cardsInGame_.at(cardIndex-2).zoneStr());
				case 1: return QString::fromStdString(cardsInGame_.at(cardIndex-2).name());
				case 2: return QString::fromStdString(cardsInGame_.at(cardIndex-2).type());
				case 3: return QString::fromStdString(cardsInGame_.at(cardIndex-2).ptStr());
				case 4: return QString::fromStdString(cardsInGame_.at(cardIndex-2).description());
			}
		} else if (role == Qt::BackgroundRole) {
			if (cardIndex < 2) return QBrush({255, 255, 255});
			switch (cardsInGame_.at(cardIndex-2).zone()) {
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
			if (zone == Zone:: BATTLEFIELD) bigTokensCount++;
		} else {
			beginInsertRows(QModelIndex(), rowCount(), rowCount());
			cardsInGame_.emplace_back(id, zone);
			endInsertRows();
		}

		sortCardsInGame();
	}

	void setCardZone(int row, Zone zone) {
		int tokenIncrement = (zone == Zone::BATTLEFIELD) ? 1 : -1;

		if (row == 0) smallTokensCount += tokenIncrement; else
		if (row == 1) bigTokensCount += tokenIncrement; else
			cardsInGame_.at(static_cast<std::size_t>(row)-2).setZone(zone);

		if (smallTokensCount < 0) smallTokensCount = 0;
		if (bigTokensCount < 0) bigTokensCount = 0;
	
		sortCardsInGame();
	}

private:

	void sortCardsInGame() {
		std::stable_sort(
			std::begin(cardsInGame_),
			std::end(cardsInGame_),
			[](const CardInGame & c1, const CardInGame & c2) {
				if (c1.zone() != c2.zone()) return c1.zone() < c2.zone();
				return false;
			}
		);

		emit dataChanged(index(0, 0), index(rowCount(), columnCount()));
	}


	int smallTokensCount = 0;
	int bigTokensCount = 0;
	std::vector<CardInGame> cardsInGame_;
};

