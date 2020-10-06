#include "Cards.h"

void Card::initialCardVectorType() { // Pushes all the types of cards to the stack 

	typesOfCards.push_back("boomb");
	typesOfCards.push_back("reinforcement");
	typesOfCards.push_back("blockade");
	typesOfCards.push_back("airlift");
	typesOfCards.push_back("displomacy");
}

void Card::setCardType(int value) {
	typeOfCard = &typesOfCards.at(value);
}

string* Card::getTypeOfCard() {
	return typeOfCard;
}

Card::Card(){  // Initialises new card objects
	initialCardVectorType();
}

Card::~Card(){ // Deletes the value of the card when no longer needed 
	//delete pointer
	//delete(typeOfCard);
}

vector<string>* Card::getPointerToVector(){
	return &typesOfCards;
}

void Card::printVectorCards(){
	cout << "This vector contains the following cards:  " << endl;
	for (int j = 0; j < typesOfCards.size(); j++) {
		cout << typesOfCards.at(j) << endl;
	}
}

void Deck::initialDeck() {

	for (int i = 0; i < 25; i++) {
		pointerToCard = new Card;
		if (i < 5) {
			pointerToCard->setCardType(0);
			deckOfCards.push_back(pointerToCard);
		}
		if (i >= 5 && i < 10) {
			pointerToCard->setCardType(1);
			deckOfCards.push_back(pointerToCard);
		}
		if (i >= 10 && i < 15) {
			pointerToCard->setCardType(2);
			deckOfCards.push_back(pointerToCard);
		}
		if (i >= 15 && i < 20) {
			pointerToCard->setCardType(3);
			deckOfCards.push_back(pointerToCard);
		}
		if (i >= 20 && i < 25) {
			pointerToCard->setCardType(4);
			deckOfCards.push_back(pointerToCard);
		}
	}
}

Deck::Deck(){  // Default deck object 
}

Deck::~Deck(){  // Deletes the value of the deck when no longer needed
	//delete ptr
	//delete(pointerToCard);
	//delete(cardTmp);
}

void Deck::printSizeOfDeck(){
	cout << "\n" << endl;
	cout << "This deckOfCards has " << deckOfCards.size() << " cards. " << endl;
	cout << "\n" << endl;
}

void Deck::printDeck(){
	cout << "\n" << endl;
	cout << "This deckOfCards has " << deckOfCards.size() << " cards. " << endl;
	cout << "\n" << endl;
	for (int j = 0; j < deckOfCards.size(); j++) {
		cout << "The card at " << j << " is " << *deckOfCards.at(i)->getTypeOfCard() << endl;
	}
}

void Deck::addCardToDeck(Card* somecard) { // To add a card to deckOfCards
	deckOfCards.push_back(somecard);
}

Card* Deck::draw(){ // Draws a random card from the remaining cards in the deckOfCards (from 0 to the size of the deckOfCards)

	srand(time(0));
	int random = rand();
	int tmp = (random % deckOfCards.size());
	tmpCard = deckOfCards.at(tmp);
	deckOfCards.erase(deckOfCards.begin() + tmp); 
	return tmpCard;
}

void HandOfCards::setHandCards(Card* somecard) { // To add a card to the HandOfCards
	cardsInHand.push_back(somecard);
}

HandOfCards::HandOfCards(){ // Default HandOfCards object
}

HandOfCards::~HandOfCards(){ // Deletes the value of the Hand when no longer needed
}

void HandOfCards::printHandCards(){
	if (cardsInHand.size() > 0) {
		cout << "The hand of cards has" << cardsInHand.size() << " cards " << endl;
		for (int k = 0; k < cardsInHand.size(); k++) {
			cout << "The card at " << k << " is " << *cardsInHand.at(j)->getTypeOfCard() << endl;
		}
	}
	else {
		cout << "\n" << endl;
		cout << "There are no cards in the hand" << endl;
	}
}

void HandOfCards::addPlayedCardToDeck(Deck* somedeck) { // Adds a played card to deck 
	for (int k = 0; k < cardsToPlay.size(); k++) {
		somedeck->addCardToDeck(cardsToPlay.at(n));
	}
}

vector<Card*>* HandOfCards::getCardsInHand() { // Gets the cards in hand 
	return &cardsInHand;
}

void HandOfCards::printCardsToPlay(){
	if (cardsToPlay.size() > 0) {
		cout << "Here is the order of the playcards: " << endl;
		for (int k = 0; k < cardsToPlay.size(); k++) {
			cout << "The card at " << k << " is " << *cardsToPlay.at(i)->getTypeOfCard() << endl;
		}
	}
	else {
		cout << "\n" << endl;
		cout << "There are no cards in the playcards" << endl;
	}
}

vector<Card*>* HandOfCards::getCardsToPlay() {
	return &cardsToPlay;
}

void HandOfCards::play(Card* somecard){ // Pushes a card to the playcards
	cardsToPlay.push_back(somecard);
}

void HandOfCards::clearCardsToPlay() {  // To clear playcards after they were played 
	cardsToPlay.clear();
	cout << "\n" << endl;
	cout << "The playcards have been cleared." << endl;
}

void HandOfCards::play(Card* somecard) { // Pushes a card to the playcards
	cardsToPlay.push_back(somecard);
}

void HandOfCards::removeAllPlayedCardsFromHand(){ // To remove a played card from handOfCards
	for (int i = 0; i < cardsToPlay.size(); i++) {
		removePlayedCardsFromHand(cardsToPlay.at(i));
	}
}

void HandOfCards::removePlayedCardsFromHand(Card* acard) { // Removes a card of the hand if already a card of the same type
	for (int k = 0; k < cardsInHand.size(); k++) {
		if (*cardsInHand.at(k)->getTypeOfCard() == *acard->getTypeOfCard()) {
			cardsInHand.erase(cardsInHand.begin() + k);
			cout << "Removing the card from hand" << *acard->getTypeOfCard() << endl;
			return;
		}
	}
}
