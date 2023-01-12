#ifndef HW4_GREMLIN
#define HW4_GREMLIN
#include "Card.h"
class Gremlin: public Card{
        static const int FORCE = 5;
        static const int DAMAGE = 10;
        static const int COINS = 2;
    public:
        Gremlin();
        void applyEncounter(Player& player) const override;
        //helper print function 
        void print(std::ostream& out) const override;
        static std::shared_ptr<Card> getCard();


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Gremlin(const Gremlin&) = default;
    virtual ~Gremlin() = default;
    Gremlin& operator=(const Gremlin& other) = default;

};

#endif