#include "BlackJack.h"
#include "Deck.h"

using namespace std;
using namespace blackjack;


BlackJack::BlackJack(Player player) {
	_player = player;
	Player _computer("House", 10000000);
}

void BlackJack::start() {																	//Blackjack game loop
	while (!stop()) {
		deck.deckReset();
		_player.placeBet();
		setTable();
		turn();
		getResults();
		calculate();
		printResult();
		if (_player.bankruptcy()) {
			cout << "Insuficient funds" << endl;
			break;
		}
		reset();
	}
	cout << _player.getPlayerName()<<" money: " << _player._playerMoney << endl;
			
}

void BlackJack::setTable() {																				//setting table for the first turn
	cout << endl;
	cout << "\n" << _player.getPlayerName() << " cards---------" << endl << endl;
	deck.getCard(_player);
	deck.getCard(_player);
	cout << "\n" << _player.getPlayerName() << " points: " << _player._playerPoints << endl;
	cout << "House card---------------------" << endl<<endl;
	deck.getCard(_computer);
	deck.firstCard(_computer);
	cout << "House first card unknown XXXXXX" << endl;
	cout << "--------------------------------------"<<endl<<endl;
}

bool BlackJack::hit()const {																			//hit option(continue withdrawing cards)
	string hit;
	cout << "HIT? y/n";
	cin >> hit;
	return hit == "y";
}
void BlackJack::turn() {																		//each additional turn implementation
	while(_player._playerPoints<21){
		if (hit()) {
			cout << "\n"<<_player.getPlayerName()<<" card---------"<<endl<<endl;
			deck.getCard(_player);
			cout << "\n"<<_player.getPlayerName()<<" points: " << _player._playerPoints << endl;
			cout << "------------------------------------------"<<endl;
		}
		else break;
	}
	while (_computer._playerPoints < 15 && _player._playerPoints <= 21) {
		cout << "\nHouse card---------------" << endl << endl;
		deck.getCard(_computer);
		cout << "House points: " << _computer._playerPoints << endl;
		cout << "--------------------------------------------"<<endl;
	}
	
}	

void BlackJack::getResults() {																	//fetching the winner
	if (_player._playerPoints > _computer._playerPoints && _player._playerPoints <= 21) { playerWon = true; }
	else if (_computer._playerPoints > _player._playerPoints && _computer._playerPoints <= 21) { computerWon = true; }
	else if (_player._playerPoints > _computer._playerPoints) { computerWon = true; }
	else if (_computer._playerPoints > _player._playerPoints) { playerWon = true; }
}


void BlackJack::reset() {																		
	_player._playerPoints = 0;
	_computer._playerPoints = 0;
	playerWon = false;
	computerWon = false;
}


bool BlackJack::stop() {																			
	cout << "Continue playing: y/n";
	string info;
	cin >> info;
	return info == "n";
}
void BlackJack::calculate() {																			//handling money bets
	if (playerWon)
		_player._playerMoney += _player._playerBet * 2;

	else if (!playerWon && !computerWon)
		_player._playerMoney += _player._playerBet;
}

void BlackJack::printResult()const {																			//outputing result
	cout << endl << endl;
	cout << "----------------- RESULTS -----------------" << endl;
	cout << endl;
	cout << _player.getPlayerName() << " points:" << _player._playerPoints << endl;
	cout << "House points:" << _computer._playerPoints << endl;
	cout << "----------------------------------------"<<endl;
	if (!computerWon && !playerWon)
		cout << "TIE";
	else if (playerWon)
		cout << _player.getPlayerName()<<" won";
	else if (computerWon)
		cout << "House won";
	cout << endl;
	cout << _player.getPlayerName()<<" money: " << _player._playerMoney << endl;
	cout << "----------------------------------------------" << endl;
	cout << endl << endl;
}
