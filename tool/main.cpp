#include <iostream>
#include "../Exception.h"
#include "../Mtmchkin.h"

int main() {
  const int MAX_NUMBER_OF_ROUNDS = 100;
  try{
    Mtmchkin goodGame("deck.txt");
    while (!goodGame.isGameOver() && goodGame.getNumberOfRounds()<MAX_NUMBER_OF_ROUNDS){
        goodGame.playRound();
    }
    goodGame.printLeaderBoard();
  }
  catch(const std::exception& e){
    std::cout <<e.what()<< std::endl;
  }
    return 0;
}