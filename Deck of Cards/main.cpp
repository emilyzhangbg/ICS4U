#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
using namespace std;

void playerTurn(Player &p, Deck &d);
bool playAgain();

int main() {
  Deck d;
  Player p1;
  Player p2;
  string name;

  //welcomes player
  cout << "Welcome to Pandemic Poker" << endl;
  cout << "¸.•♥•.¸¸.•♥•.¸¸.•♥•.¸¸.•♥•.¸" << endl;
  cout << "You get a hand of 5 cards and different hands have different values, please consult google for the exact hands. After you get your five cards, you are allowed to replace as many as you want for a new card. The player with the better hand wins\n" << endl;

  cout << "Player 1 Name: ";
  getline(cin, name);
  p1.setName(name);
  cout << "Player 2 Name: ";
  getline(cin, name);
  p2.setName(name);
  cout << endl;

  do {
    //reset everything
    d.shuffle();
    d.resetCurrentCard();
    d.dealHand(p1);
    d.dealHand(p2);
    
    //player 1 and player 2 turns
    playerTurn(p1, d);
    cout << "------------------\n" << endl;
    playerTurn(p2, d);

    //compare who wins
    if (p1.compare(p2) == 1)
      cout << p1.getName() << " wins\n" << endl;
    else if (p1.compare(p2) == 2)
      cout << p2.getName() << " wins\n" << endl;
    else 
      cout << "It's a tie\n" << endl;
  } while(playAgain());
  
  cout << "Goodbye" << endl;
}

//turn of a player
void playerTurn(Player &p, Deck &d) {
  //show player their cards
  cout << p.getName() << ", here are your cards:" << endl;
  p.printDeck();
  
  //ask player if they want to switch certain cards
  int N;
  int loc;

  cout << "How many cards do you want to switch? (enter an integer): ";
  cin >> N;

  while (N < 0 || N > 5) { //error trap
    cout << "Please enter a value between 0 and 5 inclusive: ";
    cin >> N;
  }

  //switches the cards
  if (N != 0) { 
    cout << "Which cards do you want to switch? (enter a list of integers separated by spaces): ";
    for (int i = 0; i < N; i++) {
      cin >> loc;
      while (loc < 1 || loc > 5) { //error trap
        cout << "Please enter a value between 1 and 5 inclusive: ";
        cin >> N;
      }
      d.replace(p, loc-1); //replace card at loc-1 in the deck with a new card
    }
  }
  
  //shows player their new hand
  cout << "\nYour final hand is: " << endl;
  p.printDeck();
  p.organizeHand(); //counts what face and suits the player has and puts them in array

  //output the type of the hand
  cout << "Type: " << Player::getPokerHandName(p.handType()) << endl;
  cout << endl;
}

//asks user if they want to play again
bool playAgain() {
  string playAgain;
  getline(cin, playAgain);//taking in garbage

  do {
    cout << "Do you want to play again (Y/N): ";
    getline(cin, playAgain);
    playAgain[0] = toupper(playAgain[0]);
  } while(playAgain[0] != 'Y' && playAgain[0] != 'N');

  cout << endl;

  return playAgain[0] == 'Y';
}
