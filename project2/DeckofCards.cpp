#include "DeckofCards.h"
DeckofCards::DeckofCards(): currentCard(0){
	for (int i = HEARTS; i <= CLUBS; ++i){
		for (int j = ACE; j <= KING; ++j){
			Card card(i,j);
			deck.push_back(card);
		}
	}
}
/*
	returns all cards to the deck (sets currentCard to 0)
	then shuffles the deck
*/
void DeckofCards::shuffle(){
	currentCard = 0;
	for (int i = 0; i < deck.size();++i){
		int temp = rand() % deck.size();
		Card tempCard = deck.at(temp);
		deck[temp] = deck.at(i);
		deck[i] = tempCard;
		
	}
}
/*
	If there are any cards left:	
		returns the current card and increments the currentCard
	else retuns the last card dealt;
*/
Card DeckofCards::dealCard(){
	if (moreCards()){
		++currentCard;
	}
	return deck.at(currentCard-1);
}
/*
	returns if there are any cards left in the deck
*/
bool DeckofCards::moreCards(){
	return currentCard < deck.size();
}

int DeckofCards::size(){
	return deck.size();
}
