#pragma once
#include "Player.h"
#include <vector>
#include <string>

using namespace std;
namespace blackjack{

class Card {
	string _name;
	string _type;
	int _value;
public:
	Card();
	Card(string name, string type, int value);
	string getName()const;
	string getType()const;
	int getValue()const;
	
};

class Deck:public Card {
	vector<Card> _deck;
	void create();
public:
	Deck();
	void getCard(Player &player);
	void firstCard(Player &player);
	void deckReset();
};
}