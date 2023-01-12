#include "Ninja.h"
Ninja::Ninja(const std::string name) :Player(name)
{}

void Ninja::addCoins(int coinsToAdd){
    if (coinsToAdd<0){
        return;
    }
    m_coins += 2*coinsToAdd;
}

std::string Ninja::getJob() const{
    return "Ninja";
}

std::shared_ptr<Player> Ninja::getPlayer(const std::string name){
    return std::make_shared<Ninja>(name);
}
