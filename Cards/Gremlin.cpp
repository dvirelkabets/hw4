#include "Gremlin.h"
#include "../utilities.h"

Gremlin::Gremlin(): BattleCard("Gremlin"){}

int Gremlin::getForce() const{
    return 5;
}

int Gremlin::getDamage() const{
    return 10;
}

int Gremlin::getCoins() const{
    return 2;
}

std::shared_ptr<Card> Gremlin::getCard(){
    return Gremlin_CARD;
}
