#ifndef EX4_BATTLE_CARD
#define EX4_BATTLE_CARD
#include "Card.h"
class BattleCard: public Card{     
    protected: 
        virtual int getForce() const = 0; 
        virtual int getDamage() const = 0 ;
        virtual int getCoins() const = 0; 
    
    public:
        BattleCard(std::string name);
        virtual void applyEncounter(Player& player) const;
        //helper print function 
        void print(std::ostream& out) const override;
        static std::shared_ptr<BattleCard> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCard(const BattleCard&) = default;
    ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& other) = default;



};

#endif