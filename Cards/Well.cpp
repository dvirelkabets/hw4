#include "Well.h"
#include "../utilities.h"
#include "string"
#include <typeinfo> 

Well::Well(): Card("Well"){};

void Well::applyEncounter(Player& player) const{
    bool isNinja = true;
    if(typeid(player).name() != "Ninja"){
        player.damage(DAMAGE); 
        isNinja = false; 
    }
    printWellMessage(isNinja);
};