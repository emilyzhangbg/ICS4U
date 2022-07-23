#ifndef CARD_H
#define CARD_H

#include <iostream>
using namespace std;

class Card {
  private:
    static const string FACES[13];
    static const string SUITS[4];
    int face;
    int suit;

  public:
    //constructor
    Card();
    Card(int face, int suit);
    Card(const Card& other);
    //overloaded operators
    void operator = (const Card& other);
    friend ostream& operator << (ostream& output, Card& obj);
    //getter and setters
    int getFace();
    int getSuit();
    void setFace(int face);
    void setSuit(int suit);
};

#endif
