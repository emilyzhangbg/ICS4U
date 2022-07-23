#include <ctime>
#include "Deck.h"
#include "Card.h"
#include "Player.h"

//getter and setters
Deck::Deck() {
  deck = new Card[SIZE_OF_DECK];
  int count = 0;

  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      deck[count].setFace(i);
      deck[count].setSuit(j);
      count++;
    }
  }
}

Deck::~Deck() {
  delete[] deck;
}

//shuffle deck
void Deck::shuffle() {
  int num1;
  int num2;
  Card temp;
  srand(time(0));
  
  for (int i = 0; i < 100; i++) {
    num1 = rand()%52;
    num2 = rand()%52;
    
    temp = deck[num1];
    deck[num1] = deck[num2];
    deck[num2] = temp;
  }
}

//reset current card to 0
void Deck::resetCurrentCard() {
  currentCard = 0;
}

//deals one card
Card Deck::dealCard() {
  Card temp;
  
  if (moreCards()) {
    return deck[currentCard++];
  }
  else {
    cout << "no more cards" << endl;
    Card c;
    return c;
  }
}

//takes 5 cards from the deck and puts them in the player's hand
void Deck::dealHand(Player &p) {
  for(int i = 0; i < 5; i++) {
    p.setCard(this->dealCard(), i);
  }
}

//checks if theres more cards in the deck
bool Deck::moreCards() {
  return currentCard < 52;
}

//replace one card in the player's hand with a new card from the deck
void Deck::replace(Player &p, int i) {
  p.setCard(this->dealCard(), i);
}

//print the deck
void Deck::printDeck() {
  int i = 0;
  for (int i = 0; i < 52; i++) {
    cout << i+1 << ". " << deck[i] << endl;
  }
  cout << "---" << endl;
}
