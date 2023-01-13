#ifndef EX4_Well_H
#define EX4_Well_H
#include "Card.h" 
class Well: public Card{
    static const int DAMAGE = 10;

    public: 
        Well(); 
        void applyEncounter(Player& player) const override;
        static std::shared_ptr<Card> getCard();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Well(const Well&) = default;
        ~Well() = default;
        Well& operator=(const Well& other) = default;
};

static std::shared_ptr<Well> WELL_CARD = std::make_shared<Well>();

#endif // EX4_Well_H