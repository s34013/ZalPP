#ifndef LUDEK_HPP
#define LUDEK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

// Deklaracje funkcji
void displayWord();
void clear();
void startGame();
void menu();
std::string getRandomWord();
void setPlayerName(const std::string& name);
void chooseLevel();
void showScores();

// Deklaracje zmiennych globalnych
extern std::string playerName;
extern std::string currentWorld;
extern int level;

class Game {
public:
    Game(const std::string& world, const int& level);
    ~Game();
    void play();
    void gameOver();
    void win();
    bool round();

    static int score;

private:
    bool checkLetter(char letter);
    int remainingAttempts;
    int currentLevel;
    char* unknownWord;
    size_t wordLength;
};

#endif
