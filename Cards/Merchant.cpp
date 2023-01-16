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
    int playerChoice;
    std::string input;
    while(true){
      getline(std::cin, input);
      try{
        playerChoice = getValidIntValue(input);
      }
      catch(...){
        printInvalidInput();
        continue;
      }
      switch (playerChoice)
      {
      case INPUT_TO_DO_NOTHING:
        return playerChoice;
      case INPUT_TO_BUY_LIFE:
        return playerChoice;
      case INPUT_TO_BUY_FORCE:
        return playerChoice;
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
          printMerchantSummary(std::cout, player.getName(), INPUT_TO_BUY_LIFE, 0);
        }
      }
      break;
    case INPUT_TO_BUY_FORCE:
    {
      if(player.pay(PRICE_FOR_FORCE)){
        player.changeForce(AMOUNT_OF_FORCE_PLAYER_GETS);
        printMerchantSummary(std::cout, player.getName(), INPUT_TO_BUY_FORCE, PRICE_FOR_FORCE);
      }
      else{
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(), INPUT_TO_BUY_FORCE, 0);
      }
    }
    break;
  }
}

std::shared_ptr<Card> Merchant::getCard(){
    return MERCHENT_CARD;
}
