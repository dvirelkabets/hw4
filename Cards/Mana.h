#ifndef EX4_Mana_H
#define EX4_Mana_H
#include "Card.h"
class Mana: public Card{
    static const int HP_TO_ADD = 10; 
    public: 
        Mana();
        void applyEncounter(Player& player) const override; 
        static std::shared_ptr<Mana> getCard();
        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Mana(const Mana&) = default;
        ~Mana() = default;
        Mana& operator=(const Mana& other) = default;
};


#endif //EX4_Mana_H