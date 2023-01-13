#ifndef HW4_WITCH
#define HW4_WITCH
#include "BattleCrard.h"
class Witch: public BattleCard{
        int getForce() const override; 
        int getDamage() const override; 
        int getCoins() const override;
    public:
        Witch();
        static std::shared_ptr<Card> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Witch(const Witch&) = default;
    ~Witch() = default;
    Witch& operator=(const Witch& other) = default;

};

static std::shared_ptr<Witch> Witch_CARD = std::make_shared<Witch>();

#endif