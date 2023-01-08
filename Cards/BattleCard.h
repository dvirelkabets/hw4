#include <string> 
#include "Card.h"
class BattleCard: public Card{
    public:
        //returns the values of the parmeters of the card
        virtual int getForce() = 0; 
        virtual int getLoot() = 0; 
        virtual int getDamage() = 0;

        virtual void applyEncounter(Player& player) const = 0;

        //still need to implement cout 



}