#ifndef HW4_NINJA
#define HW4_NINJA
#include "Player.h"

class Ninja : public Player{
    
public:
    Ninja(const std::string name);
    void addCoins(int coinsToAdd) override;
    std::string getJob() const override;
    static std::shared_ptr<Player> getPlayer(const std::string name);
    
};

#endif // HW4_NINJA