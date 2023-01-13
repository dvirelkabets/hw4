#include <iostream>
#include "Exception.h"
#include "Mtmchkin.h"

void foo(){
  throw DeckFileFormatError(2);
}

int main() {
  try{
    Mtmchkin goodGame("cards.txt");
  }
  catch(const std::exception& e){
    std::cout <<"somthing happend"<< std::endl;
  }

    return 0;
}