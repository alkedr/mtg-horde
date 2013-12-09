#pragma once
#ifndef USE_PRECOMPILED
# include "precompiled.hpp"
#endif

#include "Cards.hpp"
#include "CardInGame.hpp"
#include "CardsModel.hpp"
#include "Decks.hpp"


class MainWindow : public QWidget {
public:
	MainWindow()
	: QWidget()
	, cardsTable(this)
	, hordeLibrarySizeLabel(QString::number(library_.size()), this)
	, playerHpPoisonLabel(QString::number(playerHp) + "/" + QString::number(playerPoison), this)
	{
		auto mainLayout = new QVBoxLayout(this);
		auto hpLayout = new QHBoxLayout();

		mainLayout->addLayout(hpLayout);
			hpLayout->addWidget(&hordeLibrarySizeLabel);
			hpLayout->addWidget(&playerHpPoisonLabel);
		mainLayout->addWidget(&cardsTable);

		cardsTable.setModel(&cardsModel);
		cardsTable.setSelectionBehavior(QAbstractItemView::SelectRows);
		cardsTable.setSelectionMode(QAbstractItemView::SingleSelection);
		cardsTable.horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

		addShortcut(Qt::Key_C, [this]() {
			while (library_.back() < 2) {
				putCardFromLibraryTo(Zone::BATTLEFIELD);
			}
			putCardFromLibraryTo(Zone::BATTLEFIELD);
		});

		addShortcut(Qt::Key_M, [this]() { putCardFromLibraryTo(Zone::GRAVEYARD); });

		addShortcut(Qt::Key_B, [this]() { putSelectedCardsTo(Zone::BATTLEFIELD); });
		addShortcut(Qt::Key_G, [this]() { putSelectedCardsTo(Zone::GRAVEYARD); });
		addShortcut(Qt::Key_E, [this]() { putSelectedCardsTo(Zone::EXILE); });

		addShortcut(Qt::Key_Minus, [this]() { changeHp(-1); });
		addShortcut(Qt::Key_Equal, [this]() { changeHp(+1); });
		addShortcut(Qt::Key_Underscore, [this]() { changePoison(-1); });
		addShortcut(Qt::Key_Plus      , [this]() { changePoison(+1); });

		addShortcut(Qt::Key_T  , [this]() { cardsModel.addCard(0); });
		addShortcut({"Shift+T"}, [this]() { cardsModel.addCard(1); });

		addShortcut(Qt::Key_H, [this]() { changeHp    (QInputDialog::getInt(this, "HP"    , "")); });
		addShortcut(Qt::Key_P, [this]() { changePoison(QInputDialog::getInt(this, "poison", "")); });
	}

private:
	std::vector<Card::Id> library_ = decks::zombies();
	int playerHp = 40;
	int playerPoison = 10;
	CardsModel cardsModel;
	QTableView cardsTable;
	QLabel hordeLibrarySizeLabel;
	QLabel playerHpPoisonLabel;


	template<class F>
	void addShortcut(QKeySequence keySequence, F f) {
		connect(new QShortcut(keySequence, this), &QShortcut::activated, f);
	}

	void putCardFromLibraryTo(Zone zone) {
		if (library_.empty()) {
			std::cout << "library is empty" << std::endl;
		} else {
			cardsModel.addCard(library_.back(), zone);
			library_.pop_back();
			hordeLibrarySizeLabel.setText(QString::number(library_.size()));
		}
	}

	void putSelectedCardsTo(Zone zone) {
		QModelIndexList indexes = cardsTable.selectionModel()->selectedRows();
		for (const auto & index : indexes) {
			cardsModel.setCardZone(index.row(), zone);
		}
	}

	void changeHp(int difference) {
		playerHp += difference;
		playerHpPoisonLabel.setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
	}

	void changePoison(int difference) {
		playerPoison += difference;
		playerHpPoisonLabel.setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
	}
};

