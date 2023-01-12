#ifndef HW4_DRAGON
#define HW4_DRAGON
#include "Card.h"
class Dragon: public Card{
        static const int FORCE = 25;
        static const int DAMAGE = Player::MAX_HP;
        static const int COINS = 1000;
    public:
        Dragon();
        void applyEncounter(Player& player) const override;
        //helper print function 
        void print(std::ostream& out) const override;
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