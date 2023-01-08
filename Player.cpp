#include "Player.h"
Player::Player(const std::string name, int max_HP, int force) :
   m_name(name), m_level(1), m_force(force) , m_maxHP(max_HP), m_HP(max_HP), m_coins(0)
{
    if (m_maxHP<=0){
        m_HP = 100;
        m_maxHP = 100;
    }
    if (m_force<=0){
        m_force = 5;
    }
}

void Player::printInfo() const{
    printPlayerInfo(m_name.data(), m_level, m_force, m_HP, m_coins);
}

void Player::levelUp(){
    if(m_level<10){
        m_level++;
    }
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
    if(m_HP > m_maxHP){
        m_HP = m_maxHP;
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

