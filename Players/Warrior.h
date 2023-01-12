#ifndef HW4_WARRIOR
#define HW4_WARRIOR
#include "Player.h"

class Warrior : public Player{
    
public:
    Warrior(const std::string name);
    int getAttackStrength() const override;
    std::string getJob() const override;
    
};

#endif // HW4_WARRIOR