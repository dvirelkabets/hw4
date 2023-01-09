#include "Merchant.h"
#include <string> 
#include <iostream>
#include "../utilities.h"

Merchant::Merchant(): Card("Merchant"){}

int Merchant::getValidIntValue(const std::string& str) const{
    for (char c : str) {
    if (!isdigit(c)) {
      throw InvalidInput();
    }
  }

  int num = std::stoi(str);
  return num;
}

int Merchant::getValidInput() const{
    int PlayerChoice; 
    std::string input;
    while(true){
      getline(std::cin, input);
      try{
        PlayerChoice = getValidIntValue(input);
      }
      catch(InvalidInput e){
        printInvalidInput();
        continue;
      }

      switch (PlayerChoice)
      {
      case INPUT_TO_DO_NOTHING:
        return PlayerChoice;

      case INPUT_TO_BUY_LIFE:
        return PlayerChoice;

      case INPUT_TO_BUY_FORCE:
        return PlayerChoice;

      default:
        printInvalidInput();
        break;
      }
    }
}

void Merchant::applyEncounter(Player& player) const{
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    int PlayerInput = getValidInput();
    switch (PlayerInput)
    {
    case INPUT_TO_DO_NOTHING:
      break;
    
    case INPUT_TO_BUY_LIFE:
      {
        if(player.pay(PRICE_FOR__LIFE)){
          player.heal(AMOUNT_OF_LIFE_PLAYER_GETS);
          printMerchantSummary(std::cout, player.getName(), INPUT_TO_BUY_LIFE, PRICE_FOR__LIFE);
        }
        else{
          printMerchantInsufficientCoins(std::cout);
        }
      }
      break;

    case INPUT_TO_BUY_FORCE:
    {
      if(player.pay(PRICE_FOR_FORCE)){
        player.heal(AMOUNT_OF_FORCE_PLAYER_GETS);
        printMerchantSummary(std::cout, player.getName(), INPUT_TO_BUY_FORCE, PRICE_FOR_FORCE);
      }
      else{
        printMerchantInsufficientCoins(std::cout);
      }
    }
    break;
  }
}

std::shared_ptr<Merchant> Merchant::getCard(){
    return std::shared_ptr<Merchant>(new Merchant());
}
