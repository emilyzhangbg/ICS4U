#include "Card.h"
#include "Player.h"

//different types of poker hands sorted from highest to lowest
const string Player::POKER_HANDS[10] = {"Royal Flush", "Straight Flush", "Four of a Kind", "Full House", "Flush", "Straight", "Three of a Kind", "Two Pair", "Pair", "High Card"};

//constructor and destructor
Player::Player() {
  hand = new Card[SIZE_OF_HAND];
  for (int i = 0; i < SIZE_OF_HAND; i++) {
    hand[i].setFace(0);
    hand[i].setSuit(0);
  }

  name = "undefined";
}

Player::~Player() {
  delete[] hand;
}

//getter and setters
string Player::getName() {
  return name;
}

void Player::setName(string name) {
  this->name = name;
}

void Player::setCard(Card c, int i) {
  hand[i] = c;
}

Card Player::getCard(int i) {
  return hand[i];
}

string Player::getPokerHandName(int i) {
  return Player::POKER_HANDS[i];
}

//compare which hand has higher value
int Player::compare(Player &other){
  if (this->handType() < other.handType())
    return 1;
  else if (this->handType() > other.handType())
    return 2;
  else
    return 0;
}

//counts what face and suits the player has and puts it in 2 arrays
void Player::organizeHand() {
  //initialize the arrays to 0
  for(int i = 0; i < 13; i++) {
    foundFace[i] = 0;
  }

  for(int i = 0; i < 4; i++) {
    foundSuit[i] = 0;
  }

  //count values
  for(int i = 0; i < 5; i++) {
    foundFace[hand[i].getFace()]++;
    foundSuit[hand[i].getSuit()]++;
  }
}

//check which hand type it is
int Player::handType() {
  //starts checking from the highest ranked hand
  if (this->flush()) {
    if (this->royal())
      return 0;
    else if (this->straight())
      return 1;
    else
      return 4;
  }
  else if (this->fourOfAKind())
    return 2;
  else if (this->fullHouse())
    return 3;
  else if (this->straight())
    return 5;
  else if (this->threeOfAKind())
    return 6;
  else if (this->twoPair())
    return 7;
  else if(this->pair())
    return 8;
  else
    return 9;
}

//types of hands
bool Player::flush(){
  for (int i = 0; i < 4; i++) {
    if (this->foundSuit[i] == 5)
      return true;
  }

  return false;
}

bool Player::royal() {
  if (foundFace[0] == 0)
    return false;
  for (int i = 9; i < 13; i++) {
    if (foundFace[i] == 0)
      return false;
  }
  return true;
}

bool Player::straight() {  
  int count = 0;

  for (int i = 0; i < 13 && count != 5; i++) {
    if (foundFace[i] > 0) {
      count++;
    }
    else
      count = 0;
  }
  
  return count == 5;
}

bool Player::fourOfAKind() {
  for (int i = 0; i < 13; i++) {
    if (foundFace[i] == 4) 
      return true;
  }  

  return false;
}

bool Player::fullHouse() {
  bool pair = false;
  bool triple = false;

  for (int i = 0; i < 13; i++) {
    if (foundFace[i] == 2)
      pair = true;
    else if (foundFace[i] == 3)
      triple = true;
  }
  
  return pair && triple;
}

bool Player::threeOfAKind() {
  for (int i = 0; i < 13; i++) {
    if (foundFace[i] == 3) 
      return true;
  }  

  return false;
}

bool Player::twoPair() {
  int count = 0;

  for (int i = 0; i < 13; i++) {
    if (foundFace[i] == 2) {
      count++;
    }
  }

  return count == 2;
}

bool Player::pair() {
  for (int i = 0; i < 13; i++) {
    if (foundFace[i] == 2) 
      return true;
  }  

  return false;
}

//print deck
void Player::printDeck() {
  for (int i = 0; i < SIZE_OF_HAND; i++) {
    cout << i+1 << ". " << hand[i] << endl;
  }
   cout << "----" << endl;
}
