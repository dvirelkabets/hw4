#include "Card.h"
class Witch: public Card{
        static const int FORCE = 11;
        static const int DAMAGE = 10;
        static const int COINS = 2;
    public:
        Witch();
        void applyEncounter(Player& player) const override;
        //helper print function 
        void print(std::ostream& out) const override;
        static std::shared_ptr<Witch> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Witch(const Witch&) = default;
    ~Witch() = default;
    Witch& operator=(const Witch& other) = default;



};