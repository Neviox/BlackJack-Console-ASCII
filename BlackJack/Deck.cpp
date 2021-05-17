#include "Deck.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>   
using namespace std;
using namespace blackjack;

string Card::getName()const {
	return _name;
}
string Card::getType()const {
	return _type;
}
int Card::getValue()const{
	return _value;
}
Card::Card() { ; }

Card::Card(string name, string type, int value) {						
	_name = name;
	_type = type;
	_value = value;
}


void Deck::create() {																				//fill deck vector
	string cardNames[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	int cardValue=1;
	int cardIdentifier = 0;
	string cardType[4] = { "Spades","Clubs","Hearts","Diamonds" };
		for (int i = 0; i < 53; ++i) {
			int j = i % 4;
			if (cardIdentifier > 12) {
				cardIdentifier = 0;
				cardValue = 1;
			}
			if (cardIdentifier > 9) {
				cardValue = 10;
			}
		_deck.push_back(Card(cardNames[cardIdentifier], cardType[j], cardValue));
		cardIdentifier++;
		cardValue++;
		}
		srand(time(NULL));
		for (int i = _deck.size() - 1; i > 0; --i) {												//shuffle the deck
			int k = rand() % (i + 1);
			Card temp = _deck[i];
			_deck[i] = _deck[k];
			_deck[k] = temp;
		}
}
Deck::Deck() {																			
}

void Deck::getCard(Player &player) {													//get last card from deck and add points to player
	Card card = _deck.back();
	cout << card.getName() << " of " << card.getType() << "! Value:" << card.getValue() << endl;
	if (player._playerPoints + 11 < 21 && card.getName() == "ace") player._playerPoints+=11;
	player._playerPoints += card.getValue();
	_deck.pop_back();
	auto it = _deck.insert(_deck.begin(), card);
}
void Deck::firstCard(Player &player) {													//hidden dealer card
	Card card = _deck.back();
	player._playerPoints += card.getValue();
	_deck.pop_back();
	auto it = _deck.insert(_deck.begin(), card);
	

}
void Deck::deckReset() {																//remake the deck
	create();
}

