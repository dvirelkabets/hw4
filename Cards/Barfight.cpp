#include "Barfight.h"
#include "../utilities.h"
#include "string"
#include <typeinfo> 

Barfight::Barfight(): Card("Barfight"){};

void Barfight::applyEncounter(Player& player) const{
    bool isWarrior = true;
    if(typeid(player).name() != "Warrior"){
        player.damage(DAMAGE); 
        isWarrior = false; 
    }
    printBarfightMessage(isWarrior);
}