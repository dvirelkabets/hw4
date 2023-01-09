#include <iostream>
#include <cstring>
#include <string>
#include "Exception.h"
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Warrior.h"
#include "Players/Ninja.h"

void foo(){
    throw DeckFileFormatError(2);
}

int main (){
    std::string str = "dvir3t";
    for (char c : str){
        if (!isalpha(c)){
            std::cout << "not alpha"<< std::endl;
        }
        else{
            
            std::cout << c <<std::endl;
        }
        
    }
    try{
        foo();
    }
    catch(std::exception& e){
       std::cout<< e.what() << std::endl;
    }
Healer player("dvir");
player.damage(20);
player.heal(5);
std::cout << player << std::endl;
    return 0;
}