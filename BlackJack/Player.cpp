#include "Player.h"
#include <iostream>

using namespace std;
using namespace blackjack;

Player::Player() { }
Player::Player(string name, int money) { 
	_playerName = name;
	_playerMoney = money;
}
string Player::getPlayerName()const {
	return _playerName;
}
void Player::placeBet() {															//individual player bet provided by input
	cout << "Place your bet" << endl;
	cin >> _playerBet;
	if (_playerBet < 10 || _playerBet > _playerMoney)_playerBet = 10;
	_playerMoney -= _playerBet;
}
bool Player::bankruptcy() {															//handling funds
	return _playerMoney <= 10;
}
