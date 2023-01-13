#include "HangMan.hpp"

HangMan::HangMan(){
    //default initilize all values
    this->lives = 0;
    this->difficulty = 0;
    this->words[0] = "study";
    this->words[1] = "stack";
    this->words[2] = "hashmap";
    this->words[3] = "home";
    this->word = words[rand() % words.size()];
    this->remain = this->word.size();
    this->outWord = "";
    for(int i = 0; i < word.size(); i++){
        this->outWord += '_';
    }

    this->guessed = "";
    this->board.emplace_back("*----------*");
    this->board.emplace_back("|          |");
    this->board.emplace_back("|          |");
    this->board.emplace_back("|         _o_");
    this->board.emplace_back("|        / 0 \\");
    this->board.emplace_back("|         / \\");
    this->board.emplace_back("|");
    this->board.emplace_back("|");
    this->board.emplace_back("|");
    this->board.emplace_back("|");
    this->board.emplace_back("|");
    this->board.emplace_back("|");
    this->board.emplace_back("*------------------");
}

void HangMan::askDiff(){
    std::string temp = "";
    while(temp != "1" && temp != "2" && temp != "3"){
        std::cout << "Please enter a difficulty 1-3, higher is easier: " << std::endl;
        std::cin >> temp;
        std::cin.clear();
    }
    this->difficulty = (int)temp[0] - 48;
    this->lives = 4 * this->difficulty;
};

void HangMan::play(){
    while(this->lives > 0 && this->remain > 0){
        //display current game state
        std::cout << "Remaining guesses: " << this->lives << std::endl;
        std::cout << "Guessed letters: " << this->guessed << std::endl;
        std::cout << "Correct guesses: " << this->outWord << std::endl;
        for(int i = this->lives; i < this->board.size(); i++){
            std::cout << this->board[i] << std::endl;
        }

        //get next valid input from player
        std::string temp = "";
        while(temp.size() != 1 && (temp[0] < 65 || temp[0] > 90)){
            std::cin.clear();
            std::cout << "Please enter a single lower case letter guess: " << std::endl;
            std::cin >> temp;
        }

        //if current letter is present in the selected word then update the output string and append to guesses list
        guessed += temp;
        bool inWord = false;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == temp[0]){
                inWord = true;
                break;
            }
        }

        if(inWord == true){
            for(int i = 0; i < word.size(); i++){
                if(word[i] == temp[0]){
                    outWord[i] = temp[0];
                    this->remain -= 1;
                }
            }
        }
        else{
            lives -= 1;
        }
    }

    //determine and output correct message if player won or lost
    if(this->lives == 0){
        std::cout << "All lives consumed, GAME OVER." << std::endl;
        for(int i = 0; i < board.size(); i++){
            std::cout << board[i] << std::endl;
        }
    }
    else{
        std::cout << "CONGRATS, you WON!!!" << std::endl;
        std::cout << "Lives remaining: " << lives << std::endl;
    }
};

std::string HangMan::askNewGame(){
    std::cin.clear();
    std::cout << "Please enter 1 if you wish to play again: " << std::endl;
    std::string temp = "0";
    std::cin >> temp;
    return temp;
};

HangMan::~HangMan(){};