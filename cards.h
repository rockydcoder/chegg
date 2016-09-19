#include <iostream>
#include <string>
using namespace std;
enum faces {Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Joker};
enum suits {Clubs, Diamonds, Hearts, Spades, Stars, NotAvailable};
class Card {
public:
	faces face;
	suits suit;
	Card(faces face, suits suit);
	string toString();
};