#include "Cards.h"

int main() {

	HandOfCards HandCard1;   // Creates a HandOfCards object  
	Deck deck1;              // Creates a deck object and initializing it 
	deck1.initialDeck();

	deck1.printSizeOfDeck(); // Prints the size of the deck 
	//deck1.printDeck();     // Prints all cards of the deck; there are 25 cards of 25 different types

	
	cout << "Test to create 5 cards of different types and adding them to the hand " << endl;  // Generating 5 random cards then adding them to the hand
	cout << "\n" << endl;
	for (int j = 0; j < 5; j++) {
		HandCard1.setHandCards(deck1.draw());
	}

	deck1.printSizeOfDeck();     // Prints the size of the deck 
	HandCard1.printHandCards();  // Prints the cards that are currently in the hand
	
	cout << "Test to play all of the cards in the HandOfCards and places them into the cardsToPlay" << endl; 
	cout << "\n" << endl;
	for (int i = 0; i < HandCard1.getCardsInHand()->size(); i++) {
		HandCard1.play(HandCard1.getCardsInHand()->at(i));
	}
	
	HandCard1.printHandCards();			      // Prints the cards in the current hand
	HandCard1.printCardsToPlay();		      // Prints the cardstoplay
	HandCard1.addPlayedCardToDeck(&deck1);    // Adds the played cards to the deck
	deck1.printSizeOfDeck();				  // Tests the size of the deck 
	HandCard1.removeAllPlayedCardsFromHand(); // Removes all played cards of the cards in hand
	HandCard1.clearCardsToPlay();			  // Removes playcards from the cardstoplay 

	HandCard1.printHandCards();			      // Prints the cards in the current hand
	HandCard1.printCardsToPlay();			  // Prints the cardstoplay

}