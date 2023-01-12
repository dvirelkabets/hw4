#include "Gremlin.h"
#include "../utilities.h"

Gremlin::Gremlin(): Card("Gremlin"){}

void Gremlin::print(std::ostream& out) const{
    printMonsterDetails(out, FORCE, DAMAGE, COINS);
}

void Gremlin::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= FORCE){
        player.levelUp();
        player.addCoins(COINS);
        printWinBattle(player.getName(), "Gremlin");
    }
    else{
        player.damage(DAMAGE);
        printLossBattle(player.getName(), "Gremlin");
    }
}

std::shared_ptr<Card> Gremlin::getCard(){
    return std::make_shared<Gremlin>();
}
