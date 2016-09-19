#include "cards.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

void shuffleDeck(vector<Card> *deck) {
	mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<std::mt19937::result_type> dist(0,115);
	for (int i = 0; i < deck->size(); i++) {
		int randomIndex = dist(rng);
		Card randomCard = deck->at(randomIndex);
		(*deck)[randomIndex] = (*deck)[i];
		(*deck)[i] = randomCard;

	}

}

int main() {
	vector<Card> deck;
	for (int suit = Clubs; suit <= Stars; suit++) {
		for (int face = Three; face <= King; face++) {
			Card newCard = Card(static_cast<faces>(face), static_cast<suits>(suit));
			deck.push_back(newCard);
			deck.push_back(newCard);
		}
	}

	for (int i = 0; i < 6; i++) {
		Card newCard = Card(Joker, NotAvailable);
		deck.push_back(newCard);
	}

	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i].toString() << endl;
	}

	shuffleDeck(&deck);
	cout << "************SHUFFLED DECK****************" << endl;
 
	for (int i = 0; i < deck.size(); i++) {
		cout << deck[i].toString() << endl;
	}
}