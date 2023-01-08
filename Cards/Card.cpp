#include "utilities.h"
#include "Card.h"
#include <string>

Card::Card(std::string name):m_name(name){
    int count = 0;
    for(char c : name){
        if(count>15){
            throw InvalidName();
        }
        if(!isalpha(c)){
            throw InvalidName();
        }
        count++;
    }
};

std::ostream& operator << (std::ostream& out, const Card& card){
    printCardDetails(out, card.m_name);
    printEndOfCardDetails(out);
};