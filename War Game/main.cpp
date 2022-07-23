//Emily Zhang
//ICS4U
//Mr. Hudson
//October 14, 2021
//https://replit.com/@EMILYZHANG7/War-Game-Without-Classes#main.cpp

//Card game war in C++

#include <iostream>
#include <string>
#include <string.h>
#include <cctype>
#include <random>
#include <ctime>
using namespace std;

const string FACE[] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const string SUIT[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

//ANSI Codes to change colour of text
const string ANSI_RED = "\u001b[31;1m";
const string ANSI_BLUE = "\u001b[36m";
const string ANSI_RESET = "\u001b[0m";
const string ANSI_BOLD = "\u001b[1m";
const string ANSI_UNDERLINE = "\u001b[4m";

//emoji codes
const string FIRE_EMOJI = "\U0001F525";
const string WAVE_EMOJI = "\U0001F44B";
const string OPENHAND_EMOJI = "\U0001F917";
const string STAR_EMOJI = "\u2B50";
const string QUESTION_EMOJI = "\u2753";

//changes string to all uppercase
string upper(string a);

//deals cards
void initDeck(string deck[]);

//shuffles cards
void shuffle(string deck[], int size);

//deals cards
void deal(string deck[], string player_deck1[], string player_deck2[]);

//takes 4 cards from playing deck
void takeFour(string current_cards[], string deck[], int *size);

//print 4 cards
void showFour(string deck[], string name, string colour);

//get order player wants to play the cards
void getOrder(int order[], string name, string colour);

//check which card is bigger
bool player1Wins(string card1, string card2);

//finds value of cards
int faceValue(string card);

int suitValue(string card);

//prints how many cards each player has
void printStats(string name, string colour, int size1, int size2);

//merge and shuffles 2 decks
void mergeDeck(string deck1[], int *size1, string deck2[], int *size2);

//check if user wants to play again
bool yes_no(string question);

//main
int main() {
  //initialize variables
  string deck[52];

  //create players' decks
  string name1 = "Player 1";
  string name2 = "Player 2";

  string player_deck1[52];
  string player_deck2[52];
  int deck_size1 = 26;
  int deck_size2 = 26;

  string discard_deck1[52];
  string discard_deck2[52];
  int discard_size1 = 0;
  int discard_size2 = 0;

  string current_cards1[4];
  string current_cards2[4];
  int deck_order1[4];
  int deck_order2[4];

  //welcomes user
  cout << "--------------------------------\n";
  cout << FIRE_EMOJI << " Welcome to the game of War " << FIRE_EMOJI << endl;
  cout << "--------------------------------\n";
  cout << endl;

  cout << OPENHAND_EMOJI << " Player 1, what's your name?: " << ANSI_RED;
  getline(cin, name1);
  cout << ANSI_RESET << OPENHAND_EMOJI << " Player 2, what's your name?: " << ANSI_BLUE;
  getline(cin, name2);
  cout << ANSI_RESET << endl;

  name1 = upper(name1);
  name2 = upper(name2);

  string garbage;

  if (yes_no("Do you want to read the instructions?")) {
    cout << ANSI_BOLD << ANSI_UNDERLINE << "INSTRUCTIONS" << ANSI_RESET << endl;
    cout << "Each player will be given cards and they will order them and compare with the cards of the other player. The card with the larger value wins and the winner gets to put both cards in their discard pile. When a player has less then 4 cards in their main pile they need to shuffle their main and discard pile together. The player who has less than 4 cards in both their main and discard pile first loses." << endl;
    cout << endl;
    cout << "Note: The lowest card is Deuce and highest card is Ace. The suits from lowest to highest is Clubs, Diamonds, Hearts, Spades" << endl;
    cout << endl;
    cout << "Press enter to continue";
    getline(cin, garbage);
    cout << endl;
  } 


  cout << ANSI_RESET << WAVE_EMOJI << " Hi " << ANSI_RED << name1 << ANSI_RESET << " and " << ANSI_BLUE << name2 << ANSI_RESET << ". Let's start the game!" << endl;

  do {
    //create deck
    initDeck(deck);
    shuffle(deck, 52);

    //deal
    deal(deck, player_deck1, player_deck2);
    deck_size1 = 26;
    deck_size2 = 26;
    discard_size1 = 0;
    discard_size2 = 0;
    
    int round = 1;

    //game begins
    //check if players have enough cards
    while (((deck_size1 + discard_size1) > 3) && ((deck_size2 + discard_size2) > 3)) {
      cout << endl;
      cout << ANSI_BOLD << ANSI_UNDERLINE << "ROUND " << round << ANSI_RESET << endl;
      cout << endl;

      //take 4 cards
      takeFour(current_cards1, player_deck1, &deck_size1);
      takeFour(current_cards2, player_deck2, &deck_size2);

      //show player cards
      //ask for order to play
      showFour(current_cards1, name1, ANSI_RED);
      getOrder(deck_order1, name1, ANSI_RED);
      showFour(current_cards2, name2, ANSI_BLUE);
      getOrder(deck_order2, name2, ANSI_BLUE);

      //show player round result
      cout << ANSI_BOLD << "RESULTS: " << ANSI_RESET << endl;
      for (int i = 0; i < 4; i++) {
        //check who's card is higher
        //print winner
        //move card to discard pile of winner
        if (player1Wins(current_cards1[deck_order1[i]], current_cards2[deck_order2[i]])) {
          cout << current_cards1[deck_order1[i]] << " beats " << current_cards2[deck_order2[i]] << " --> ";
          cout << ANSI_RED << name1 << ANSI_RESET << " wins!" << endl;

          discard_deck1[discard_size1] = current_cards1[deck_order1[i]];
          discard_deck1[discard_size1+1] = current_cards2[deck_order2[i]];

          discard_size1 += 2;
        }
        else {
          //system("Color 4");
          cout << current_cards2[deck_order2[i]] << " beats " << current_cards1[deck_order1[i]] << " --> ";
          cout << ANSI_BLUE << name2 << ANSI_RESET << " wins!" << endl;

          discard_deck2[discard_size2] = current_cards1[deck_order1[i]];
          discard_deck2[discard_size2+1] = current_cards2[deck_order2[i]];

          discard_size2 += 2;
        }
      }

      //print how many cards each player has
      printStats(name1, ANSI_RED, deck_size1, discard_size1);
      printStats(name2, ANSI_BLUE, deck_size2, discard_size2);

      cout << "____________________________________________" << endl;

      //shuffle playing and discard deck together if not enough cards
      if (deck_size1 < 4) {
        mergeDeck(player_deck1, &deck_size1, discard_deck1, &discard_size1);
      }

      if (deck_size2 < 4) {
        mergeDeck(player_deck2, &deck_size2, discard_deck2, &discard_size2);
      }

      round++;
    }

    cout << endl;

    //whoever has > 4 cards wins
    if((deck_size1 + discard_size1) > 4) {
      cout << STAR_EMOJI << ANSI_RED << " " << name1 << ANSI_RESET << " wins " << STAR_EMOJI << endl;
    }
    else {
      cout << STAR_EMOJI << ANSI_BLUE << " " << name2 << ANSI_RESET << " wins" << STAR_EMOJI << endl;
    }
    
    cout << endl;

  } while(yes_no("Do you want to play again?"));

  cout << WAVE_EMOJI << " Goodbye" << endl;
}

//changes string to upper case
string upper(string a) {
  int n = a.length();

  for (int i = 0; i < n; i++) {
    a[i] = toupper(a[i]);
  }

  return a;
}

//initialize deck of cards
void initDeck(string deck[]) {
  int n = 0;

  for (int i = 0; i < 13; i++) {
    for (int j = 0; j < 4; j++) {
      deck[n] = FACE[i] + " of " + SUIT[j];
      n++;
    }
  }
}

//shuffles cards
//randomly switch position of 2 cards 100 times
void shuffle(string deck[], int size) {
  int n1;
  int n2;
  string temp;
  
  srand(time(0)); 

  for (int i = 0; i < 100; i++) {
    n1 = rand() % size;
    n2 = rand() % size;

    temp = deck[n1];
    
    deck[n1] = deck[n2];
    deck[n2] = temp;
  }
}

//deal cards
void deal(string deck[], string player_deck1[], string player_deck2[]) {
    for (int i = 0; i < 52; i += 2) {
		player_deck1[i/2] = deck[i];
		player_deck2[i/2] = deck[i+1];
	}
}

//takes 4 cards from playing deck
void takeFour(string current_cards[], string deck[], int *size) {
  for (int i = *size - 1; i > *size - 5; i--) {
    current_cards[*size - 1 - i] = deck[i];
  }
  *size -= 4;
}

//print 4 cards
void showFour(string deck[], string name, string colour) {
  cout << colour << name << "'s cards" << ANSI_RESET << endl;
  for (int i = 0; i < 4; i++) {
    cout << i+1 << ". " << deck[i] << endl;
  }
  cout << endl;

}

void getOrder(int order[], string name, string colour) {
  //keeps track of if the # corresponding to that index has been entered already
  bool inputted[4] = {false, false, false, false};
  //input is bad
  bool bad_input = false;

  string input = "";

  do {
    //prompt user to enter
    if (bad_input) {
      for (int i = 0; i < 4; i++) {
        inputted[i] = false;
      }
      bad_input = false;
      cout << "Please check your input and reenter (ex. 2 3 1 4)\n";
    }
    else {
      cout << "Hi " << colour << name  << ANSI_RESET << "! What order do you want to play the cards? (ex. 2 3 1 4)\n";
    }

    //get input
    cout << "Order: ";
    getline(cin, input);

    //error trap
    //check length is valid
    if (input.length() == 7 || input.length() == 8) {
      //check # are valid
      for (int i = 0; i < 7; i += 2) {
        if ((isdigit(input[i]) == 0) || ((int)input[i]) < 49 || ((int)input[i]) > 52 || (inputted[((int)input[i])-49] == true)) {
          bad_input = true;
          break;
        }
        else {
          //record input
          order[i/2] = ((int)input[i]) - 49;
          inputted[order[i/2]] = true;
        }
      }
      
      //check spaces are valid
      for (int i = 1; i < input.length()-1; i += 2) {
        if (input[i] != ' ') {
          bad_input = true;
          break;
        }
      }
    } else {
      bad_input = true;
    }

    cout << endl;
  } while (bad_input);
}

//check if player 1's card is bigger
bool player1Wins(string card1, string card2) {
  bool win = true;

  if(faceValue(card1) < faceValue(card2)) {
    win = false;
  }
  else if (faceValue(card1) == faceValue(card2)) {
    if (suitValue(card1) < suitValue(card2)) {
      win = false;
    }
  }
  
  return win;
}

//find index value of card 
int faceValue(string card) {
  for (int i = 0; i < 13; i++) {
    if (card.find(FACE[i]) != string::npos) {
      return i;
      break;
    }
  }

  return 0;
}

int suitValue(string card) {
  for (int i = 0; i < 4; i++) {
    if (card.find(SUIT[i]) != string::npos) {
      return i;
      break;
    }
  }

  return 0;
}

//prints how many cards each player has
void printStats(string name, string colour, int size1, int size2) {
  cout << endl;
  cout << colour << name << ANSI_RESET << endl;
  cout << "pile: " << size1 << " cards" << endl;
  cout << "discard: " << size2 << " cards" << endl;
}

//merge and shuffles 2 decks
void mergeDeck(string deck1[], int *size1, string deck2[], int *size2) {
  for (int i = 0; i < *size2; i++) {
    deck1[*size1 + i] = deck2[i]; 
  }

  *size1 += *size2;
  *size2 = 0;

  shuffle(deck1, *size1);
}

//checks if user wants to play again
bool yes_no(string question) {
  bool play_again = false;
  string input = "Y";

  //get input
  //error trap
  do {
    cout << QUESTION_EMOJI << " " << question << " (Y/N): ";
     getline(cin, input);

    input = upper(input);

  } while (input != "Y" && input != "N");

  cout << endl;

  //returns answer
  if (input == "Y") {
    return true;
  }
  else {
    return false;
  }
}
