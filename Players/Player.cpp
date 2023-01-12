#include "Player.h"
#include "../Exception.h"
#include "../utilities.h"
Player::Player(const std::string name) :
   m_name(name), m_level(1), m_force(START_FORCE) , m_HP(MAX_HP), m_coins(START_COINS)
{
    if (name.length()>15 || name.length()<=0){
        throw Player::InvalidName();
    }

    for (char c : name){
        if (!isalpha(c)){
            throw Player::InvalidName();
        }
    }
}


void Player::levelUp(){
    if(m_level<10){
        m_level++;
    }
}

int Player::getCoins() const{
    return m_coins;
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(int forceToAdd){
    if (forceToAdd<0){
        return;
    }
    m_force += forceToAdd;
}

void Player::heal(int addHp){
    if (addHp<0){
        return;
    }
    m_HP += addHp;
    if(m_HP > MAX_HP){
        m_HP = MAX_HP;
    }
}

void Player::damage(int playerDamage){
    if (playerDamage<0){
        return;
    }
    m_HP -= playerDamage;
    if(m_HP<0){
        m_HP = 0;
    }
}

bool Player::isKnockedOut() const{
    if(m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd){
    if (coinsToAdd<0){
        return;
    }
    m_coins += coinsToAdd;
}

bool Player::pay(int coinsToPay){
    if (coinsToPay<0){
        return true;
    }
    int tmpCoins = m_coins - coinsToPay;
    if(tmpCoins < 0){
        return false;
    }
    m_coins = tmpCoins;
    return true;
}

int Player::getAttackStrength() const{
    return (m_force +m_level);
}

std::string Player::getJob() const{
    return "Hapash";
}

std::string Player::getName() const {
    return m_name;
}

std::ostream& operator<<(std::ostream& os , const Player& playerToWrite){
    printPlayerDetails(os, playerToWrite.m_name, playerToWrite.getJob(), playerToWrite.m_level,
     playerToWrite.m_force, playerToWrite.m_HP, playerToWrite.m_coins);
    return os;
}

