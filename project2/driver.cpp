/*
	Aaron Milgram
	Project2 (Poker Bot)
	18 Dec, 2018
*/
#include "DeckofCards.cpp"
#include <ctime>
#include <algorithm>
const int handSize = 5;

void printHand(std::vector<Card> hand){
	for (int i = 0; i < hand.size(); ++i){
		std::cout << "Card " << i << ": ";
		std::cout << hand.at(i).toString() << std::endl;
	}
}
//returns true if a hand contains a single pair
bool contains2ofKind(std::vector<Card> hand){
	const int ofakind = 2;
	int face1 = 0;
	int face2 = 0;
	int face3 = 0;
	int face4 = 0;
	int numFace1 = 0;
	int numFace2 = 0;
	int numFace3 = 0;
	int numFace4 = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (face1 == 0){
			face1 = hand.at(i).getFace();
			++numFace1;
		}
		else if (hand.at(i).getFace() == face1){
			++numFace1;
		}
		else if (face2 == 0){
			face2 = hand.at(i).getFace();
			++numFace2;
		}
		else if (hand.at(i).getFace() == face2){
			++numFace2;
		}
		else if (face3 == 0){
			face3 = hand.at(i).getFace();
			++numFace3;
		}
		else if (hand.at(i).getFace() == face3){
			++numFace3;
		}
		else if (face4 == 0){
			face4 = hand.at(i).getFace();
			++numFace4;
		}
		else if (hand.at(i).getFace() == face4){
			++numFace4;
		}
		else{
			return false;
		}
	}
	return numFace1 == ofakind || numFace2 == ofakind || numFace3 == ofakind || numFace4 == ofakind;
}

//returns true if a hand contains a pair and a 3 of a kind
bool contains2pairs(std::vector<Card> hand){
	const int pair = 2;
	int face1 = 0;
	int face2 = 0;
	int face3 = 0;
	int numFace1 = 0;
	int numFace2 = 0;
	int numFace3 = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (face1 == 0){
			face1 = hand.at(i).getFace();
			++numFace1;
		}
		else if (hand.at(i).getFace() == face1){
			++numFace1;
		}
		else if (face2 == 0){
			face2 = hand.at(i).getFace();
			++numFace2;
		}
		else if (hand.at(i).getFace() == face2){
			++numFace2;
		}
		else if (face3 == 0){
			face3 = hand.at(i).getFace();
			++numFace3;
		}
		else if (hand.at(i).getFace() == face3){
			++numFace3;
		}
		else{
			return false;
		}
	}
	int numPairs = 0;
	if (numFace1 == pair){
		++numPairs;
	}
	if (numFace2 == pair){
		++numPairs;
	}
	if (numFace3 == pair){
		++numPairs;
	}
	return numPairs == pair;
}


//returns true if a hand contains 1 pair and a 3 of a kind
bool containsFullHouse(std::vector<Card> hand){
	const int pair = 2;
	const int _3kind = 3;
	int face1 = 0;
	int face2 = 0;
	int face3 = 0;
	int numFace1 = 0;
	int numFace2 = 0;
	int numFace3 = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (face1 == 0){
			face1 = hand.at(i).getFace();
			++numFace1;
		}
		else if (hand.at(i).getFace() == face1){
			++numFace1;
		}
		else if (face2 == 0){
			face2 = hand.at(i).getFace();
			++numFace2;
		}
		else if (hand.at(i).getFace() == face2){
			++numFace2;
		}
		else if (face3 == 0){
			face3 = hand.at(i).getFace();
			++numFace3;
		}
		else if (hand.at(i).getFace() == face3){
			++numFace3;
		}
		else{
			return false;
		}
	}
	int numPairs = 0;
	if (numFace1 == pair){
		++numPairs;
	}
	if (numFace2 == pair){
		++numPairs;
	}
	if (numFace3 == pair){
		++numPairs;
	}
	int num3kind = 0;
	if (numFace1 == _3kind){
		++num3kind;
	}
	if (numFace2 == _3kind){
		++num3kind;
	}
	if (numFace3 == _3kind){
		++num3kind;
	}
	return numPairs == 1 && num3kind == 1;
}

//returns true if hand contains exactly 3 of a kind
bool contains3ofKind(std::vector<Card> hand){
	const int ofakind = 3;
	int face1 = 0;
	int face2 = 0;
	int face3 = 0;
	int numFace1 = 0;
	int numFace2 = 0;
	int numFace3 = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (face1 == 0){
			face1 = hand.at(i).getFace();
			++numFace1;
		}
		else if (hand.at(i).getFace() == face1){
			++numFace1;
		}
		else if (face2 == 0){
			face2 = hand.at(i).getFace();
			++numFace2;
		}
		else if (hand.at(i).getFace() == face2){
			++numFace2;
		}
		else if (face3 == 0){
			face3 = hand.at(i).getFace();
			++numFace3;
		}
		else if (hand.at(i).getFace() == face3){
			++numFace3;
		}
		else{
			return false;
		}
	}
	return (numFace1 == ofakind && numFace2 != 2 && numFace3 != 2) || 
		   (numFace2 == ofakind && numFace1 != 2 && numFace3 != 2) ||
		   (numFace3 == ofakind && numFace1 != 2 && numFace1 != 2);
}
//returns true if hand contains exactly 4 of a kind
bool contains4ofKind(std::vector<Card> hand){
	const int ofakind = 4;
	int face1 = 0;
	int face2 = 0;
	int numFace1 = 0;
	int numFace2 = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (face1 == 0){
			face1 = hand.at(i).getFace();
			++numFace1;
		}
		else if (hand.at(i).getFace() == face1){
			++numFace1;
		}
		else if (face2 == 0){
			face2 = hand.at(i).getFace();
			++numFace2;
		}
		else if (hand.at(i).getFace() == face2){
			++numFace2;
		}
		else{
			return false;
		}
	}
	return numFace1 == ofakind || numFace2 == ofakind;
}
// returns true if all cards in the hand are of the same suit.
bool containsFlush(std::vector<Card> hand){
	int suit = 0;
	for (int i = 0; i < hand.size(); ++i){
		if (suit == 0){
			suit = hand.at(i).getSuit();
		}
		else if (suit != hand.at(i).getSuit()){
			return false;
		}
	}
	return true;
}
//returns true if hand consists of a run of 5
bool containsStraight(std::vector<Card> hand){
	std::vector<int> cardValues;
	for (int i = 0; i < hand.size(); ++i){
		cardValues.push_back(hand.at(i).getFace());
	}
	std::sort(cardValues.begin(), cardValues.end());
	for (int i = 1; i < cardValues.size(); ++i){
		if (cardValues.at(i) -1 != cardValues.at(i-1)){
			return false;
		}
	}
	return true;
}
//returns the poker rank for the given hand or -1 for unranked hand
int getRank(std::vector<Card> hand){
	if (contains4ofKind(hand)){
		return 2;
	}
	else if (containsFullHouse(hand)){
		return 3;
	}
	else if (contains3ofKind(hand)){
		return 6;
	}
	else if (contains2pairs(hand)){
		return 7;
	}
	else if (contains2ofKind(hand)){
		return 8;
	}
	else if (containsStraight(hand)){
		if (containsFlush(hand)){
			return 1;
		}
		else {
			return 5;
		}
	}
	else if (containsFlush(hand)){
		return 4;
	}
	else{
		return -1;
	}
}
//returns 1 on victory, -1 on defeat, and 0 on a tie
int didIWin(int myRank, int opponentRank){
	if (myRank == opponentRank){
		return 0;
	}
	else if (opponentRank > 0 && myRank > 0){
		if (myRank < opponentRank){
			return 1;
		}
		else{
			return -1;
		}
	}
	else if (opponentRank <= 0 && myRank > 0){
		return 1;
	}
	else{
		return -1;
	}	
}

int main(){
	//variable declaration
	std::vector<Card> hand;
	std::vector<Card> dHand;
	int handRank;
	int dHandRank;
	int victor;
	int bluff;
	int cardRemQuantity;
	std::vector<int> cardsToRemove;
	int cardRemovalIndex;
	//Initialization of the deck
	srand(time(0));
	DeckofCards deck;
	deck.shuffle();

	//Deal cards to intitial hands
	for (int i =0; i < handSize; ++i){
		hand.push_back(deck.dealCard());//1st dealer deals a card to the player
		dHand.push_back(deck.dealCard());//then to him or herself
	}//this continues until all hands are the proper size (5 cards)
	
	
	
	
	//print the player's starting hand
	std::cout << "Here is you're starting hand:" << std::endl;
	printHand(hand);
	handRank = getRank(hand);
	dHandRank = getRank(dHand);
	if (handRank > 0){
		std::cout << "You're hand is currently ranked: " << handRank << std::endl;
	}
	else{
		std::cout << "You're hand is currently unranked." << std::endl;
	}
	
	
	//Program card drawing algorithm 1
	for (int i = 0, drawCounter = 0; i < dHand.size() && drawCounter < 3; ++i){
		if (i == dHand.size()-1 && drawCounter == 0){
			dHand[i] = deck.dealCard();
		}
		else{
			int temp = rand() % 3;
			if (temp == 1){
				dHand[i] = deck.dealCard();
			}
		}
	}
	
	//improvement to card drawing algorithm 1 (bluffing)
	dHandRank = getRank(dHand);
	bluff = rand() % 2;
	if (bluff == 1){
		int bluffRank;
		if (dHandRank <= 7  && dHandRank > 0){
			bluffRank = rand() % 3;
			std::cout << "[POKER-BOT]: My hand is rank ";
			std::cout << bluffRank + 3 << ". How about you?" << std::endl;
		}
		else{
			bluffRank = rand() % 5;
			if (bluffRank > 8){
				std::cout << "[POKER-BOT]: My hand is rank ";
				std::cout << dHandRank << ". How about you?" << std::endl;
			}
			else{
				std::cout << "[POKER-BOT]: My hand is rank ";
				std::cout << bluffRank + 4 << ". How about you?" << std::endl;
			}
		}
	}
	else {
		if (dHandRank <= 0){
			std::cout << "[POKER-BOT]: My hand is unranked";
			std::cout << ". How about you?" << std::endl;
		}
		else{
			std::cout << "[POKER-BOT]: My hand is rank ";
			std::cout << dHandRank << ". How about you?" << std::endl;
		}
	}
	
	
	
	
	
	
	
	//player gets to exchange cards
	std::cout << "To exchange cards, enter in the amount of cards you want to switch\n";
	std::cout << "Followed by the number for each card you want removed. (Max 3)" << std::endl;
	std::cout << "[num cards to remove] [cardNum1] [cardNum2] [cardNum3]" << std::endl; 
	std::cin >> cardRemQuantity;
	if (cardRemQuantity > 0 && cardRemQuantity <= 3){
		for (int i = 0; i < cardRemQuantity; ++i){
			std::cin >> cardRemovalIndex;
			bool isValid = cardRemovalIndex < hand.size() && cardRemovalIndex >= 0;
			for (int j = 0; j < cardsToRemove.size() && isValid;++j){
				if (cardsToRemove.at(j) == cardRemovalIndex){
					isValid = false;
					break;
				}
			}
			if (isValid){
				cardsToRemove.push_back(cardRemovalIndex);
				if (deck.moreCards()){
					hand[cardRemovalIndex] = deck.dealCard();
				}
			}
		}
	}
	

	
	
	
	
	//Print you're new hand and rank
	std::cout << "Here is you're new hand:" << std::endl;
	printHand(hand);
	handRank = getRank(hand);
	if (handRank > 0){
		std::cout << "You're new hand is ranked: " << handRank << std::endl;
	}
	else{
		std::cout << "You're new hand is unranked." << std::endl;
	}
	
	
	//print you're opponent's new hand and rank
	std::cout << "Here is you're opponent's hand:" << std::endl;
	printHand(dHand);
		if (dHandRank > 0){
		std::cout << "You're opponent's hand is ranked: " << dHandRank << std::endl;
	}
	else{
		std::cout << "You're opponent's hand is unranked." << std::endl;
	}
	
	
	//Determine who won based on hand rank and print it to the screen
	victor = didIWin(handRank,dHandRank);
	if (victor > 0){
		std::cout << "You Won. Great Job!" << std::endl;
	}
	else if (victor < 0){
		std::cout << "You Lost. Better Luck Next Time." << std::endl;
	}
	else{
		std::cout << "You Tied. Round 2?" << std::endl;
	}
	return 0;
}























