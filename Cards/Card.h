#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include "../Players/Player.h"
#include "../Players/Warrior.h"
#include "../Players/Ninja.h"
#include "../Players/Healer.h"
#include <iostream>
#include <memory>

/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/

class Card {
std::string m_name;
public:
    /*
     * C'tor of Card class
     *
     * @parm name - The name of the card
     * @return
     *      A new instance of Card.
    */
    Card(std::string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;

    //adding print helper function 
    virtual void print(std::ostream& out) const;

    virtual std::shared_ptr<Card> getCard() = 0;


    friend std::ostream& operator << (std::ostream& out, const Card& card);
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    //Exeptions 
    class InvalidName{};
    

};


#endif //EX4_Card_H