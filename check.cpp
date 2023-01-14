#include <iostream>
#include "Exception.h"
#include "Mtmchkin.h"

void foo(){
  throw DeckFileFormatError(2);
}

int main() {
  try{
    Mtmchkin goodGame("C:\\Users\\alkdv\\CLionProjects\\untitled\\hw4\\badCards.txt");
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