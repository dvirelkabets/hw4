#include "Card.h"
#include "Dragon.h"
class BattleCard: public Card{     
    protected: 
        virtual int getForce() const = 0; 
        virtual int getDamage() const = 0 ;
        virtual int getCoins() const = 0; 
    
    public:
        BattleCard();
        virtual void applyEncounter(Player& player) const;
        //helper print function 
        void print(std::ostream& out) override;
        static std::shared_ptr<BattleCard> getCard();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCard(const BattleCard&) = default;
    ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& other) = default;



};