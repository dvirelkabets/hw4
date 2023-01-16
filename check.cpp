#include <iostream>
#include "Exception.h"
#include "Mtmchkin.h"

void foo(){
  throw DeckFileFormatError(2);
}

int main() {
  try{
    Mtmchkin goodGame("cards.txt");
    while (!(goodGame.isGameOver())){
        goodGame.playRound();
        goodGame.printLeaderBoard();
    }
  }
  catch(const std::exception& e){
    std::cout <<e.what()<< std::endl;
  }

    return 0;
}