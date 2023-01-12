#include <iostream>
#include "Mtmchkin.h"

int main() {
  try{
    Mtmchkin goodGame("cards.txt");
  }
  catch(...){
    std::cout <<"somthing happend"<< std::endl;
  }
    return 0;
}