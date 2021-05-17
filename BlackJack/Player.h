#pragma once
#include <string>
#include <iostream>


using namespace std;
namespace blackjack {

	class Player {
		string _playerName;
	public:
		int _playerPoints;
		int _playerMoney;
		int _playerBet;
		Player();
		Player(string name, int money);
		string getPlayerName()const;
		void placeBet();
		bool bankruptcy();
		friend istream& operator >> (istream& in, Player& player) {
			cout << "Enter your username: " << endl;
			in >> player._playerName;
			cout << "Buy in (Minimal buy in is 10):" << endl;
			in >> player._playerMoney;
			if (player._playerMoney < 10) {
				cout << "Buy in too low!" << endl;
				player._playerMoney = 0;
			}
			player._playerPoints = 0;
			return in;
		}
	};
}