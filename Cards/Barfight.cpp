#include "Barfight.h"
#include "../utilities.h"
#include "string" 

Barfight::Barfight(): Card("Barfight"){}

void Barfight::applyEncounter(Player& player) const{
    bool isWarrior = true;
    if(player.getJob() != "Warrior"){
        player.damage(DAMAGE); 
        isWarrior = false; 
    }
    printBarfightMessage(isWarrior);
}

std::shared_ptr<Barfight> Barfight::getCard(){
    return std::make_shared<Barfight>;
}