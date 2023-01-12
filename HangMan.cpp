#include "HangMan.hpp"

HangMan::HangMan(){
    this->lives = 0;
    this->difficulty = 0;
    words[0] = "study";
    words[1] = "stack";
    words[2] = "hashmap";
    words[3] = "home";
    word = words[rand() % words.size()];
    this->guessed = "";
}

void HangMan::askDiff(){
    std::string temp = "";
    while(temp != "1" || temp!= "2" || temp != "3"){
        std::cout << "Please enter a difficulty 1-3, higher is easier: " << std::endl;
        std::cin >> temp;
        std::cin.clear();
    }
    this->difficulty = (int)temp[0] - 48;
    this->lives = 4 * this->difficulty;
};

void HangMan::play(){
    while(this->lives > 0){
        std::cout << "Remaining guesses: " << this->lives << std::endl;
        std::cout << "Guessed letters: " << this->guessed << std::endl;
        for(auto itr:board){
            std::cout << itr << std::endl;
        }
        std::string temp = "";
        while(temp.size() != 1 && (temp[0] < 65 || temp[0] > 90)){
            std::cin.clear();
            std::cout << "Please enter a single lower case letter guess: " << std::endl;
            std::cin >> temp;
        }

    }
};

char HangMan::askNewGame(){
    std::cin.clear();

};