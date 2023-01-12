#include "Card.h"
class Dragon: public Card{
        static const int FORCE = 25;
        static const int DAMAGE = Player::MAX_HP;
        static const int COINS = 1000;
    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;



};