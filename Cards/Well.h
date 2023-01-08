#ifndef EX4_Well_H
#define EX4_Well_H
#include "Card.h" 
class Well: public Card{
    static const int DAMAGE = 10;

    public: 
        Well(); 
        void applyEncounter(Player& player) const override;

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Well(const Well&) = default;
        ~Well() = default;
        Well& operator=(const Well& other) = default;
};


#endif // EX4_Well_H