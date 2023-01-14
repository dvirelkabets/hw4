#ifndef HW4_DRAGON
#define HW4_DRAGON
#include "BattleCard.h"
class Dragon: public BattleCard{
        int getForce() const override; 
        int getDamage() const override; 
        int getCoins() const override;
    public:
        Dragon();
        static std::shared_ptr<Card> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;

};

static std::shared_ptr<Dragon> DRAGON_CARD = std::make_shared<Dragon>();

#endif