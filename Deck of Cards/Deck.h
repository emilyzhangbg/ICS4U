#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Player.h"

class Deck {
  private:
    const int SIZE_OF_DECK = 52;
    Card *deck;
    int currentCard = 0;

  public:
    //constructor and destructor
    Deck();
    ~Deck();

    //actions on deck
    void shuffle();
    void resetCurrentCard();
    Card dealCard();
    void dealHand(Player &p);
    bool moreCards();
    void replace(Player &p, int i);
    void printDeck();
};

#endif
