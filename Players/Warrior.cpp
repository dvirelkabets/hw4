#include "Warrior.h"
Warrior::Warrior(const std::string name) :Player(name)
{}


int Warrior::getAttackStrength() const{
    return ((m_force*2) +m_level);
}

std::string Warrior::getJob() const{
    return "Warrior";
}

std::shared_ptr<Player> Warrior::getPlayer(const std::string name){
    return std::make_shared<Warrior>(name);
}