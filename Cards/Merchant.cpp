#include "Merchant.h"
#include <string> 
#include <iostream>
int Merchant::getValidIntValue(const std::string& str) const{
    for (char c : str) {
    if (!isdigit(c)) {
      throw InvalidInput();
    }
  }

  int num = std::stoi(str);
  return num;
}; 

void Merchant::applyEncounter(Player& palyer) const{
    printMerchantInitialMessageForInteractiveEncounter(); 
    
}