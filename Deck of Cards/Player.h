#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"

class Player {
  private:
    static const string POKER_HANDS[10];
    const int SIZE_OF_HAND = 5;
    Card *hand;
    string name;
    int foundFace[13];
    int foundSuit[4];

  public:
    Player();
    ~Player();

    static string getPokerHandName(int i);

    //getter and setters
    string getName();
    void setName(string name);
    void setCard(Card c, int i);
    Card getCard(int i);

    //compare which hand is higher
    int compare(Player &other);
    //counts what face and suits the player has and puts it in 2 arrays
    void organizeHand();

    //hand types
    int handType(); //calls the functions below
    bool flush();
    bool straight();
    bool royal();
    bool fourOfAKind();
    bool fullHouse();
    bool threeOfAKind();
    bool twoPair();
    bool pair();

    //print deck
    void printDeck();
};

#endif
