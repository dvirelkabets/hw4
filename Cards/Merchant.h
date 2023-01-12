#ifndef EX4_Merchant_H
#define EX4_Merchant_H
#include "Card.h" 
class Merchant: public Card{
    private:
    static const int AMOUNT_OF_LIFE_PLAYER_GETS = 1;
    static const int PRICE_FOR__LIFE = 5;
    static const int AMOUNT_OF_FORCE_PLAYER_GETS = 1;
    static const int PRICE_FOR_FORCE = 10;
    static const int INPUT_TO_DO_NOTHING = 0;
    static const int INPUT_TO_BUY_LIFE = 1;
    static const int INPUT_TO_BUY_FORCE = 2;

    /*
    *This function checks if the input string from the user is valid (which means only numbers).
    *If the input is valid returns the int value of the input 
    *Else throws an exception
    *@parm str - The string we get from the user
    *@return - The int value of the string
    */
    int getValidIntValue(const std::string& str) const;

    /*
    *This function gets input from the user until it recives the right type of input for Merchant card 
    *@return - The value of the correct input 
    */
   int getValidInput() const;

    //private exceptions 
    class InvalidInput{};



    public: 
        Merchant(); 
        void applyEncounter(Player& player) const override;
        static std::shared_ptr<Card> getCard();

        /*
        * Here we are explicitly telling the compiler to use the default methods
        */
        Merchant(const Merchant&) = default;
        ~Merchant() = default;
        Merchant& operator=(const Merchant& other) = default;
};

static std::shared_ptr<Merchant> MERCHENT_CARD = std::make_shared<Merchant>();

#endif // EX4_Merchant_H