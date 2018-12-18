#include <iostream>


typedef enum{ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING} Face;
typedef enum{HEARTS=1,DIAMONDS,SPADES,CLUBS} Suit;

class Card{
	private:
		Suit suit;
		Face face;
	public:
		Card(int suit_ = 1, int face_ = 1);
		std::string getSuitString();
		std::string getFaceString();
		std::string toString();
		int getSuit();
		int getFace();
};
