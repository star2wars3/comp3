Aaron Milgram
Project2 (Poker Bot)


For my first attempt at coding the dealer's card drawing antics, I have the program randomly draw up to 3 cards. I do this by going through the dealers hand and for each card in their hand, If the dealer has not drawn 3 cards, if I roll a 1 on a 1d3 (rand() % 3) then I dra card to replace the card there. To gaurantee that at least 1 card is drawn if no cards have been drawn by the final card in the hand, a card is drawn there. 

**********Vs. Myself**********
My      Wins: 6
Program Wins: 7
Nobody  Wins: 7
**********Vs. Friend**********
Friend  Wins: 9
Program Wins: 2
Nobody  Wins: 9

**********Combined Total**********
Player  Wins: 15
Program Wins: 9
Nobody  Wins: 16

For my improvement to the dealer's card drawing algorithm, I programmed the dealer to bluff. For a given hand, the program has a 50% chance to bluff. If the program chooses to bluff. If it's actual hand is a good hand, it claims that it has a bad hand and vice versa. If the program chooses not to bluff then it tells the player the actual rank of it's hand.

The idea behind this is that if a player is told that the program has a significantly better hand than they have then they might be willing to take bigger risks. On the flip side, if the player is told that the program has a significantly worse hand than they do then they may tke less risks with their hand than they should.

**********Vs. Myself**********
My      Wins: 15
Program Wins: 1
Nobody  Wins: 4
**********Vs. Friend**********
Friend  Wins:5 
Program Wins:9 
Nobody  Wins:6

**********Combined Total**********
Player  Wins: 20
Program Wins: 10
Nobody  Wins: 10

In the second round of testing, The Program won 1 more game than in the previous round. At the same time, the players won 5 more games than in the first round of testing. It is notable that during the first round of testing I didn't have a good strategy whereas my friend had a better strategy which I utilised in the second round. This may have inflated the improvement rate of the players. That being said, even with my increase of skill between rounds, the program still won more rounds in the first round than in the second round which is an improvement.





