#include "Witch.h"
#include "../utilities.h"

Witch::Witch(): BattleCard("Witch"){}

int Witch::getForce() const{
    return 11;
}

int Witch::getDamage() const{
    return 10;
}

int Witch::getCoins() const{
    return 2;
}

std::shared_ptr<Card> Witch::getCard(){
    return Witch_CARD;
}


