#include "card.cpp"
#include <vector>
class DeckofCards{
	private:
		std::vector<Card> deck;
		int currentCard;
	public:
		DeckofCards();
		void shuffle();
		Card dealCard();
		bool moreCards();
		int size();
};
