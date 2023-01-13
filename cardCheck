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
#include "Cards/BattleCrard.h"
#include <iostream>

int main(){
    Warrior* n = new Warrior("maor");
    std::cout << *n << std::endl;
    Card* w = new Well();
    Card* t = new Treasure();
    w->applyEncounter(*n);
    std::cout << *n << std::endl;
    t->applyEncounter(*n);
    std::cout << *n << std::endl;
}