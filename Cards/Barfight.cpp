#include "Barfight.h"
#include "../utilities.h"

Barfight::Barfight(): Card("Barfight"){}

void Barfight::applyEncounter(Player& player) const{
    bool isWarrior = true;
    if(player.getJob() != "Warrior"){
        player.damage(DAMAGE); 
        isWarrior = false; 
    }
    printBarfightMessage(isWarrior);
}

std::shared_ptr<Card> Barfight::getCard(){
    return BAR_FIGHT_CARD;
}