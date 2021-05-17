#pragma once
#include "Deck.h"
#include "Player.h"
using namespace std;

namespace blackjack {
	class BlackJack {
		void setTable();
		bool hit()const;
		void turn();
		void getResults();
		void printResult()const;
		void calculate();
		void reset();
		bool stop();
		Player _player;
		Player _computer;
		Deck deck;
		bool playerWon;
		bool computerWon;
	public:
		BlackJack(Player player);
		void start();
	};
}