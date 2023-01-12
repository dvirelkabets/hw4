#include "Cards/Card.h"
#include "Cards/Barfight.h" 
#include "Cards/Mana.h"
#include "Cards/Well.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Witch.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Players/Player.h"
#include "Players/Ninja.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include <iostream>

int main(){
    Well m;
    Merchant m2;
    Ninja p = Ninja("maor");
    p.heal(95);
    std::cout << p << std::endl;
    m.applyEncounter(p);
    std::cout << p << std::endl;

    return 0;
}