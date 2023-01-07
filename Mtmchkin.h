#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <functional>
#include <string>
#include <iostream>
#include <istream>
#include <vector>
#include <deque>
#include <stack>
#include <memory>
#include "Players/Player.h"
//#include "Cards/Card.h"
// #include "Cards/Witch.h"
// #include "Cards/Barfight.h"
// #include "Cards/Dragon.h"
// #include "Cards/Mana.h"
// #include "Cards/Gremlin.h"
// #include "Cards/Merchant.h"
// #include "Cards/Well.h"
// #include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include "utilities.h"

typedef std::string Card;
/*
Mtmchkin class:
@param m_players - the vector of the players that are playing
@param m_cards - the deck of the cards of the game
@praram m_winnerStack - holds the winners in a stack to help arrange in leader board.
@param m_loserStack - holds the losers in a stack to help arrange in leader board.
@param int m_index - the last card played.
*/

class Mtmchkin{
std::vector<Player> m_players;
std::vector<Card> m_cards;
std::stack<Player> m_winnerStack;
std::stack<Player> m_loserStack;
int m_index;
int m_roundCounter = 0;
 
/*
readCard function - recive father class smart pointer to Card type, and string that holds the type of card
try to create new card in given type.
in case of success it add the card to m_cards
in case of faliure throws exception.

@return void
*/
void readCard(std::unique_ptr<Card>& card, const std::string read);

 /*
 read file to deck function - recive file name and try to create new card deck according to the rules set 
 at the pdf.
 add cards to m_cards useing readCard function.
 in case of faliure throws the needed exception
 
 @return void
 */
void readFileToDeck (const std::string &fileName);

/*
is valid player name - check if the given player name in @param player is valid.
@return - 
in case of valid returns true.
in case of not valid returns false.
*/
bool isValidPlayerName (std::string player);

/*
assiagn job - try to create a new player of type job
@param player - smart pointer to father class Player
@param jobName - string that holds the GIVEN job name
@param playerName - string that holds the player name.

the function check if the player name is legel using isValidPlayerName function and try to assaign the
given job for him - create a new Ninja\Warrior\Healer class using smart pointers.

@return - 
in case something went wrong it returns false and print what went wrong.
in case of success returns true.
*/
bool assiagnJob (std::unique_ptr<Player>& player, std::string jobName, std::string playerName);

/*
readPlayer - read from defualt ostream the player name and job. add the player to m_players vector.
@param player - smart pointer to empty variable father class Player, create a new Ninja\Warrior\Healer using
assaignJob function and assaign this smart pointer to it.

read the player and job in the rules set in pdf. runs until gets legel names for player and for job.

@return void
*/
void readPlayer (std::unique_ptr<Player>& player);

/*
readPlayerNumber - read from the default ostream the number of players.
the players allowed are between 2 and 6.
@return -  the legal number after entered.
*/
int readPlayerNumber();


/*
    * Play the next Card - according to the instruction in the exercise document
    *
    * @return
    *      void
*/
void playNextCard();

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};



#endif /* MTMCHKIN_H_ */
