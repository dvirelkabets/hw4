#ifndef HW4_GREMLIN
#define HW4_GREMLIN
#include "BattleCard.h"
class Gremlin: public BattleCard{
        int getForce() const override; 
        int getDamage() const override; 
        int getCoins() const override;
    public:
        Gremlin();
        static std::shared_ptr<Card> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Gremlin(const Gremlin&) = default;
    ~Gremlin() = default;
    Gremlin& operator=(const Gremlin& other) = default;

};

static std::shared_ptr<Gremlin> Gremlin_CARD = std::make_shared<Gremlin>();


#endif