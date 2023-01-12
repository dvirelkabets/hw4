#include "Healer.h"

Healer::Healer(const std::string name) :Player(name)
{}

void Healer::heal(int addHp){
    if (addHp<0){
        return;
    }
    m_HP += 2*addHp;
    if(m_HP > MAX_HP){
        m_HP = MAX_HP;
    }
}

std::string Healer::getJob() const{
    return "Healer";
}

std::shared_ptr<Healer> Healer::getPlayer(const std::string name){
    return std::make_shared<Healer>(name);
}