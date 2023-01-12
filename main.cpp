#include <iostream>
#include "HangMan.hpp"

void gameHangMan(){

}

int main(){
    std::cin.clear();
    std::cout << "Welcome to HangMan C++, please enter 1 to play HangMan!" << std::endl;
    char temp = 0;
    std::cin >> temp;
    while(temp == '1'){
        temp = '0';
        HangMan currGame;
        currGame.askDiff();
        currGame.play();
        temp = currGame.askNewGame();
    }
    return 0;
}