#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <functional>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <deque>
#include <map>
#include <stack>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Witch.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Mana.h"
#include "Cards/Gremlin.h"
#include "Cards/Merchant.h"
#include "Cards/Well.h"
#include "Cards/Treasure.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Exception.h"
#include "utilities.h"

typedef std::shared_ptr<Card> (*getCard)();
static std::map<std::string, getCard> m_cardMap = {{"Well", &Well::getCard},{"Gremlin", &Gremlin::getCard},{"Witch", &Witch::getCard},
                                                   {"Dragon",&Dragon::getCard},{"Merchant", &Merchant::getCard},{"Treasure",&Treasure::getCard},
                                                   {"Barfight",&Barfight::getCard},{"Mana",&Mana::getCard}};

typedef std::shared_ptr<Player> (*getPlayer)(const std::string name);
static std::map<std::string, getPlayer> m_playerMap = {{"Ninja", &Ninja::getPlayer}, {"Warrior", &Warrior::getPlayer}, {"Healer",&Healer::getPlayer}};

/*
Mtmchkin class:
@param m_players - the vector of the players that are playing
@param m_cards - the deck of the cards of the game
@param m_winnerVector - holds the winners in a vector to help arrange in leader board.
@param m_loserVector - holds the losers in a vector to help arrange in leader board.
@param int m_index - the last card played.
@param m_roundCounter - counts the rounds of the game.
@param m_cardMap - hash table with card types as keys and a function that returns a shared pointer to specific card as value.
@param m_playerMap - hash table with jobs types as keys and a function that returns a shared pointer to a new object of that job (every player is different but needs to be shared pointer to
 not have dangling reference).
*/

class Mtmchkin{

    std::vector<std::shared_ptr<Player>> m_players;
    std::vector<std::shared_ptr<Card>> m_cards;
    std::vector<std::shared_ptr<Player>> m_winnerVector;
    std::vector<std::shared_ptr<Player>> m_loserVector;
    int m_index;
    int m_roundCounter = 0;

    /*
    read file to deck function - recive file name and try to create new card deck according to the rules set
    at the pdf.
    add cards to m_cards
    in case of faliure throws the needed exception

    @return void
    */
    void readFileToDeck (const std::string &fileName);

    /*
    readPlayerNumber - read from the default ostream the number of players.
    the players allowed are between 2 and 6.
    @return -  the legal number after entered.
    */
    int readPlayerNumber() const;

    /*
    readPlayer - read from default ostream the player name and job. add the player to m_players vector.
    @param player - smart pointer to empty variable father class Player, create a new Ninja\Warrior\Healer using
    assignJob function and assign this smart pointer to it.

    read the player and job in the rules set in pdf. runs until gets legal names for player and for job.

    @return void
    */
    void readPlayer (std::shared_ptr<Player>& player);

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
    bool assignJob (std::shared_ptr<Player>& player, std::string jobName, std::string playerName);

    /*
    * Play the next Card - according to the instruction in the exercise document
    * @return void
    */
    void playNextCard(std::shared_ptr<Player>& player);

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