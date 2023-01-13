#include "Dragon.h"
#include "../utilities.h"

Dragon::Dragon(): BattleCard("Dragon"){}

int Dragon::getForce() const{
    return 25;
}

int Dragon::getDamage() const{
    return Player::MAX_HP;
}

int Dragon::getCoins() const{
    return 1000;
}

std::shared_ptr<Card> Dragon::getCard(){
    return DRAGON_CARD;
}
