#include "card.h"

Card::Card(int suit_, int face_)//:suit((Suit)suit_), face((Face)face_){}
{
	switch (face_){
		case 1:
			face = ACE;
			break;
		case 2:
			face = TWO;
			break;
		case 3:
			face = THREE;
			break;
		case 4:
			face = FOUR;
			break;
		case 5:
			face = FIVE;
			break;
		case 6:
			face = SIX;
			break;
		case 7:
			face = SEVEN;
			break;
		case 8:
			face = EIGHT;
			break;
		case 9:
			face = NINE;
			break;
		case 10:
			face = TEN;
			break;
		case 11:
			face = JACK;
			break;
		case 12:
			face = QUEEN;
			break;
		case 13:
		default:
			face = KING;
			break;
	};
	switch(suit_){
		case 1:
			suit = HEARTS;
			break; 
		case 2:
			suit = DIAMONDS;
			break;
		case 3:
			suit = SPADES;
			break; 
		case 4:
		default:
			suit = CLUBS;
			break; 
	};
}
//returns the string form of the card.
std::string Card::toString(){
	return getFaceString() + " of " + getSuitString();
}

//returns the string form of the face
std::string Card::getFaceString(){
	switch(face){
	case ACE:
		return "Ace";
	case TWO:
	case THREE:
	case FOUR:
	case FIVE:
	case SIX:
	case SEVEN:
	case EIGHT:
	case NINE:
	case TEN:
		return std::to_string((int)face);
	case JACK:
		return "Jack";
	case QUEEN:
		return "Queen";
	case KING:
		return "King";
	default:
		return "-1";
	};
}
//returns the string form of the suit
std::string Card::getSuitString(){
	switch(suit){
		case HEARTS:
			return "Hearts";
		case DIAMONDS:
			return "Diamonds";
		case SPADES:
			return "Spades";
		case CLUBS:
			return "Clubs";
		default:
			return "Null";

	};
}
//returns the int equivalent for a suit
int Card::getSuit(){
	switch(suit){
		case HEARTS:
			return 1;
		case DIAMONDS:
			return 2;
		case SPADES:
			return 3;
		case CLUBS:
			return 4;
		default:
			return -1;

	};
}
//returns the int equivalent of the face
int Card::getFace(){
	switch(face){
	case ACE:
		return 1;
	case TWO:
		return 2;
	case THREE:
		return 3;
	case FOUR:
		return 4;
	case FIVE:
		return 5;
	case SIX:
		return 6;
	case SEVEN:
		return 7;
	case EIGHT:
		return 8;
	case NINE:
		return 9;
	case TEN:
		return 10;
	case JACK:
		return 11;
	case QUEEN:
		return 12;
	case KING:
		return 13;
	default:
		return -1;
	};
}
