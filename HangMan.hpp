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
        //store the actual word
        std::string word;
        //store the output for most recent guess
        std::string outWord;
        //storing location of each char in word
        int remain;
        std::unordered_map<int, std::string> words;
        int lives;
        int difficulty;
    public:
        HangMan();
        void askDiff();
        void play();
        std::string askNewGame();
        ~HangMan();
};

#endif