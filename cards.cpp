#include "cards.h"
#include <iostream>
#include <string>
using namespace std;

string getTextForSuit( suits suit )
{
  switch( suit )
  {
  case Clubs:
    return "Clubs";

  case Diamonds:
  	return "Diamonds";

  case Hearts:
 	return "Hearts";

  case Spades:
  	return "Spades";

  case Stars:
  	return "Stars";

  default:
    return "Not recognized..";
  }
}

string getTextForFace( faces face) {
	switch( face ) {
		case Three:
			return "Three";
		case Four:
			return "Four";
		case Five:
			return "Five";
		case Six:
			return "Six";
		case Seven:
			return "Seven";
		case Eight:
			return "Eight";
		case Nine:
			return "Nine";
		case Ten:
			return "Ten";
		case Jack:
			return "Jack";
		case Queen:
			return "Queen";
		case King:
			return "King";
		default:
			return "Not recognized..";
	}
}

Card::Card(faces face, suits suit) {
	this->face = face;
	this->suit = suit;
}

string Card::toString() {
	if (this->face == Joker)
		return "Joker";
	return getTextForFace(face) + " of " + getTextForSuit(suit);
}
