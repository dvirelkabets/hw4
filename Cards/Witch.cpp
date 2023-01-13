#include "Witch.h"
#include "../utilities.h"

Witch::Witch(): Card("Witch"){}

void Witch::print(std::ostream& out) const{
    printMonsterDetails(out, FORCE, DAMAGE, COINS);
}

void Witch::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(COINS);
        printWinBattle(player.getName(), "Witch");
    }
    else{
        player.damage(DAMAGE);
        printLossBattle(player.getName(), "Witch");
    }
}

std::shared_ptr<Card> Witch::getCard(){
    return WITCH_CARD;
}

