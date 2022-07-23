#include "Card.h"

const string Card::FACES[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const string Card::SUITS[4] = {"Hearts", "Spades", "Clubs", "Diamonds"};

//constructors
Card::Card() {
  face = 0;
  suit = 0;
}

Card::Card(int face, int suit) {
  if (face >= 0 && face < 13 && suit >= 0 && suit < 4) {
    this->face = face;
    this->suit = suit;
  }
  else {
    this->face = 0;
    this->suit = 0;
  }
}

Card::Card(const Card& other) {
  this->face = other.face;
  this->suit = other.suit;
}

//overloaded operators
void Card::operator = (const Card& other){
  if (this != &other) {
    this->face = other.face;
    this->suit = other.suit;
  }
}

ostream& operator << (ostream& output, Card& obj) {
  output << Card::FACES[obj.face] << " of " << Card::SUITS[obj.suit];
  return output;
}

//getter and settters
int Card::getFace(){
  return this->face;
}

int Card::getSuit(){
  return this->suit;
}

void Card::setFace(int face){
  if(face >= 0 && face < 13)
    this->face = face;
}

void Card::setSuit(int suit){
  if(suit >= 0 && suit < 4)
    this->suit = suit;
}
