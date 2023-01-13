#include "Dragon.h"
#include "../utilities.h"

Dragon::Dragon(): Card("Dragon"){}

void Dragon::print(std::ostream& out) const{
    printMonsterDetails(out, FORCE, DAMAGE, COINS, true);
}

void Dragon::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(COINS);
        printWinBattle(player.getName(), "Dragon");
    }
    else{
        player.damage(DAMAGE);
        printLossBattle(player.getName(), "Dragon");
    }
}

std::shared_ptr<Card> Dragon::getCard(){
    return DRAGON_CARD;
}
