#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator> 
#include <vector>
#include <ctime>
#include <algorithm> 
using namespace std;

class Card{
public:
	Card();
	~Card();

	void initialCardVectorType(); // To initialize the type of card vector

	
	vector<string>* getPointerToVector(); // To get pointers to the vectors 
	
	void printVectorCards(); // Prints the cards of the different vector types 

	
	void setCardType(int value); // Assigns to the cards their type based on a value from 0 to 4 
	
	string* getTypeOfCard(); //get card type 


private:
	vector<string> typesOfCards; // vector to store the different types of cards
	string* typeOfCard;// String to store the type of card 
};


class Deck : public Card {  

public:
	Deck();
	~Deck();
	
	void initialDeck(); // Initial deck of cards that has 25 cards, 5 of each type 

	void printDeck(); // Prints the cards in the deck 
	
	void printSizeOfDeck(); // Prints the size of the deck 

	Card* draw(); // Draws a random card remaining in the deck and returns it 

	void addCardToDeck(Card* somecard); // Returns played cards into the deck 

	//vector<Card*>* getCurrentDeck();  // Gets the current deck 

private:
	vector<Card*> deckOfCards;
	Card* pointerToCard; // pointer to card
	Card* cardTmp; // To draw and remove a card from deck 
};


class HandOfCards : public Card, public Deck { 

public:
	HandOfCards();
	~HandOfCards();
	
	void setHandCards(Card* somecard); // To set the cards of a HandOfCards
	
	void printHandCards(); // To print the cards of a HandOfCards
	
	void printCardsToPlay(); // To print the cards available to be played 

	void play(Card* somecard); // To play a card 

	void addPlayedCardToDeck(Deck* somedeck); // Adds a card that was played to the deck 


	vector<Card*>* getCardsInHand(); // Gets pointer to the cardsInHand vector
	
	vector<Card*>* getCardsToPlay(); // Gets pointer to the cardsToPlay vector

	
	void removePlayedCardsFromHand(Card* acard); // Removes a played card from HandOfCards
	
	void removeAllPlayedCardsFromHand(); // Removes all the played cards from HandOfCards
	
	void clearCardsToPlay; // Clears the CardsToPlay vector after a player has played 

private:
	vector<Card*> cardsInHand; // Stores the cards in hand
	vector<Card*> cardsToPlay; // Stores the cards to play 
};