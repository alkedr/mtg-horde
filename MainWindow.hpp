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
	MainWindow() {
		auto mainLayout = new QVBoxLayout(this);
			auto hpLayout = new QHBoxLayout();
				auto hordeLibrarySizeLabel = new QLabel(QString::number(library_.size()));
				auto playerHpPoisonLabel = new QLabel(QString::number(playerHp) + "/" + QString::number(playerPoison));
			auto cardsTable = new QTableView;

		mainLayout->addLayout(hpLayout);
			hpLayout->addWidget(hordeLibrarySizeLabel);
			hpLayout->addWidget(playerHpPoisonLabel);
		mainLayout->addWidget(cardsTable);

		cardsTable->setModel(&cardsModel);
		cardsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
		cardsTable->resizeColumnsToContents();

		connect(
			new QShortcut(Qt::Key_C, this),
			&QShortcut::activated,
			[this, cardsTable, hordeLibrarySizeLabel]() {
				while (!library_.empty()) {
					auto cardId = library_.back();
					library_.pop_back();
					cardsModel.addCard(cardId);
					if (cardId > 1) break;
				}
				cardsTable->resizeColumnsToContents();
				hordeLibrarySizeLabel->setText(QString::number(library_.size()));
			}
		);

		connect(
			new QShortcut(Qt::Key_M, this),
			&QShortcut::activated,
			[this, cardsTable, hordeLibrarySizeLabel]() {
				if (!library_.empty()) {
					cardsModel.addCard(library_.back(), Zone::GRAVEYARD);
					library_.pop_back();
				}
				cardsTable->resizeColumnsToContents();
				hordeLibrarySizeLabel->setText(QString::number(library_.size()));
			}
		);

		connect(
			new QShortcut(Qt::Key_B, this),
			&QShortcut::activated,
			[this, cardsTable]() {
				QModelIndexList indexes = cardsTable->selectionModel()->selectedRows();
				for (const auto & index : indexes) {
					cardsModel.setCardZone(index.row(), Zone::BATTLEFIELD);
				}
				cardsTable->resizeColumnsToContents();
			}
		);

		connect(
			new QShortcut(Qt::Key_G, this),
			&QShortcut::activated,
			[this, cardsTable]() {
				QModelIndexList indexes = cardsTable->selectionModel()->selectedRows();
				for (const auto & index : indexes) {
					cardsModel.setCardZone(index.row(), Zone::GRAVEYARD);
				}
				cardsTable->resizeColumnsToContents();
			}
		);

		connect(
			new QShortcut(Qt::Key_E, this),
			&QShortcut::activated,
			[this, cardsTable]() {
				QModelIndexList indexes = cardsTable->selectionModel()->selectedRows();
				for (const auto & index : indexes) {
					cardsModel.setCardZone(index.row(), Zone::EXILE);
				}
				cardsTable->resizeColumnsToContents();
			}
		);

		connect(
			new QShortcut(Qt::Key_Minus, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				playerHp--;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);

		connect(
			new QShortcut(Qt::Key_Equal, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				playerHp++;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);

		connect(
			new QShortcut(Qt::Key_Underscore, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				playerPoison--;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);

		connect(
			new QShortcut(Qt::Key_Plus, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				playerPoison++;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);

		connect(
			new QShortcut(Qt::Key_T, this),
			&QShortcut::activated,
			[this, cardsTable]() {
				cardsModel.addCard(0);
				cardsTable->resizeColumnsToContents();
			}
		);

		connect(
			new QShortcut(QKeySequence("Shift+T"), this),
			&QShortcut::activated,
			[this, cardsTable]() {
				cardsModel.addCard(1);
				cardsTable->resizeColumnsToContents();
			}
		);

		connect(
			new QShortcut(Qt::Key_H, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				int deltaHP = QInputDialog::getInt(this, "HP", QString());
				playerHp += deltaHP;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);

		connect(
			new QShortcut(Qt::Key_P, this),
			&QShortcut::activated,
			[this, playerHpPoisonLabel]() {
				int delta = QInputDialog::getInt(this, "poison", QString());
				playerPoison += delta;
				playerHpPoisonLabel->setText(QString::number(playerHp) + "/" + QString::number(playerPoison));
			}
		);
	}

private:
	std::vector<Card::Id> library_ = decks::zombies();
	int playerHp = 40;
	int playerPoison = 10;
	CardsModel cardsModel;
};

