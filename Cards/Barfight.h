#ifndef EX4_Barfight_H
#define EX4_Barfight_H
#include "Card.h" 
class Barfight: public Card{
    static const int DAMAGE = 10;

    public: 
        Barfight(); 
        void applyEncounter(Player& player) const override;
        static std::shared_ptr<Card> getCard() ;

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Barfight(const Barfight&) = default;
        ~Barfight() = default;
        Barfight& operator=(const Barfight& other) = default;
};
static std::shared_ptr<Barfight> BAR_FIGHT_CARD = std::make_shared<Barfight>();


#endif // EX4_Barfight_H