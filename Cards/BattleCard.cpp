#include "BattleCrard.h"
#include"../utilities.h"

BattleCard::BattleCard(): Card("Battle Card"){}

void BattleCard::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= this->getForce()){
        player.levelUp();
        player.addCoins(this->getCoins());
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->getDamage());
        printLossBattle(player.getName(), this->m_name);
    }
}

 void BattleCard::print(std::ostream& out){
    Dragon* dragonPtr = dynamic_cast<Dragon*>(this);
    bool isDragon = !(dragonPtr == nullptr);
    printMonsterDetails(out, this->getForce(), this->getDamage(), this->getCoins(), isDragon);
 }

