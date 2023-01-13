#include <iostream>
#include "Exception.h"
#include "Cards/Dragon.h"
#include "Cards/Card.h"

void foo(){
  throw DeckFileFormatError(2);
}

int main() {
  try{
    foo();
    // Mtmchkin goodGame("cards.txt");
  }
  catch(const std::exception& e){
    std::cout << e.what() << std::endl;
    // std::cout <<"somthing happend"<< std::endl;
  }

  std::cout<< *(Dragon::getCard()) <<std::endl;
    return 0;
}