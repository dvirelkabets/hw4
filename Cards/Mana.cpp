#include "Mana.h" 
#include <string> 
#include "../utilities.h"

Mana::Mana(): Card("Mana"){}

void Mana::applyEncounter(Player& player) const{
    bool isHealer = false;
    if(player.getJob() == "Healer"){
        player.heal(HP_TO_ADD); 
        isHealer = true; 
    }
    printManaMessage(isHealer);
}

std::shared_ptr<Card> Mana::getCard(){
    return MANA_CARD;
}