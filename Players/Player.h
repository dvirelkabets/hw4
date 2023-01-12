#ifndef EX4_Player_H
#define EX4_Player_H
#include <iostream>
#include <cstring>
#include <string>

class Player{
protected:
    std::string m_name;
    int m_level;
    int m_force; 
    int m_HP;
    int m_coins;
    friend std::ostream& operator<<(std::ostream& os , const Player& playerToWrite); // defining printing for the class

public:
    class InvalidName{};
    static const int START_FORCE = 5;
    static const int START_COINS = 10;
    static const int MAX_HP = 100;
    static const int MAX_LEVEL = 10;
    /*
     * Creates a player object with level 1, START_COINS coins, HP equals to MAX_HP, force equals to START_FORCE.
     *
     * @param name - The name of the player.
     * @return
     *      A new palyer object
    */
    Player(const std::string name);

   /*
   *Adds 1 to the player level if level is less then 10
   *If level is 10 does nothing 
   *@return void
   */
  void levelUp();

  /*
  *@return The player level
  */
 int getLevel() const;

 /*
 *Increase the power in the amount given
 *@parm forceToAdd - The amount of force we increase force with
 @return void
 */
void buff(int forceToAdd);

/*
*Increase HP with the amount given 
*The increase is only up to max HP
*@parm addHp - The amount of HP we add
*@return void
*/
virtual void heal(int addHp);

/*
*Decrease HP by the amount given up to 0
*@parm playerDamage - The amount you decrease HP by.
@return void 
*/
void damage(int playerDamage);

/*
*Checks if the HP has reached to 0
*@return if the HP is equal to 0
*/
bool isKnockedOut() const;

/*
*Adds the given amount to coins 
*@parm coinsToAdd - The amount of coins we add
*@return void
*/
virtual void addCoins(int coinsToAdd);

/*
*Takes the amount given out of the coins 
*If the player don't have enough coins we return false and don't take out any coins
*@parm coinsToPay - The amount of coins you take out of the player coins 
*@return True if the player could pay and Falase if he couldn't
*/
bool pay(int coinsToPay);

/*
*Returns the attack strength which is eqaul to force + level 
*@return attack strength
*/
virtual int getAttackStrength() const;

std::string getName() const;

virtual std::string getJob() const;

Player(const Player&)=default;
virtual ~Player() = default;
Player& operator=(const Player& other) = default;

};
#endif// EX4_player_H