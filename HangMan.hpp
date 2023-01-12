#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

#ifndef HANGMAN
#define HANGMAN

class HangMan{
    private:
        std::string guessed;
        std::vector<std::string> board;
        std::string word;
        std::unordered_map<int, std::string> words;
        int lives;
        int difficulty;
    public:
        HangMan();
        void askDiff();
        void play();
        char askNewGame();
        ~HangMan();
};

#endif