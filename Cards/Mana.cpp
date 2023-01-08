#include "Mana.h" 
#include <string> 
#include <typeinfo> 
#include "../utilities.h"

Mana::Mana(): Card("Mana"){}; 

void Mana::applyEncounter(Player& player) const{
    bool isHealer = false;
    if(typeid(player).name() == "Healer"){
        player.heal(HP_TO_ADD); 
        isHealer = true; 
    }
    printManaMessage(isHealer);
}