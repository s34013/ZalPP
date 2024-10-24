#include "game.hpp"



void menu() {
    int choice;
    std::string menu = R"(  Menu
    1. Rozpocznij gre
    2. Poziom trudnosci
    3. Pokaz ranking
    4. Wyjdz
    Wybieram: )";
    clear();
    std::cout << menu;
}

void displayWord() {
    std::cout << "Slowo to: " + currentWorld << std::endl;
}

void setPlayerName(const std::string& name) {
    playerName = name;
}

void clear() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

Game::Game(const std::string& world, const int& level) {
    currentWorld = world;
    wordLength = world.length();
    unknownWord = new char[wordLength + 1];

    switch (level) {
    case 1:
        remainingAttempts = 10;
        break;
    case 2:
        remainingAttempts = 5;
        break;
    default:
        remainingAttempts = 10;
        break;
    }

    for (size_t i = 0; i < wordLength; i++) {
        unknownWord[i] = '_';
    }
    unknownWord[wordLength] = '\0';
}

Game::~Game() {
    delete[] unknownWord;
}

bool Game::checkLetter(char letter) {

    bool found = false;
    size_t pos = currentWorld.find(letter);

    while (pos != std::string::npos) {
        unknownWord[pos] = currentWorld[pos];
        score++;
        found = true;
        pos = currentWorld.find(letter, pos + 1);
    }

    if (!found) {
        remainingAttempts--;
        return false;
    }

    return true;
}

bool Game::round() {
    char letter;

    std::cout << "Aktualne slowo: " << unknownWord << std::endl;
    while (true) {
        std::cout << "Podaj litere: ";
        std::cin >> letter;

        
        if (std::cin.fail() || !isalpha(letter)) { 
            clear();
            std::cin.clear();  
            std::cout << "To nie jest poprawna litera. Sprobuj ponownie.\n";
           
        } else {
            letter = tolower(letter);  
            clear();
            break;
        }
    }

    if (checkLetter(letter)) {
        if (strcmp(unknownWord, currentWorld.c_str()) == 0) {  
            win();
            return true;
        }
        return round();  
    } else {
        if (remainingAttempts <= 0) {
            gameOver();  
            return false;
        } else {
            std::cout << "Pozostala liczba zyc: " << remainingAttempts << std::endl;
            return round();  
        }
    }
}


void Game::gameOver() {
    std::cout << "Gra zakonczona!" << std::endl;
    displayWord();
    score = 0;
}

void Game::win() {
    std::cout << "Wygrales!" << std::endl;
    displayWord();

    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open()) {
        std::cout << "Podaj swoje imie: ";
        std::cin >> playerName;
        file << playerName << " " << score << std::endl;
        file.close();
    }
    score = 0;
}

void showScores() {
    std::ifstream file("scores.txt");
    std::vector<std::pair<std::string, int>> scores;

    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            scores.push_back({ name, score });
        }
        file.close();

        std::sort(scores.begin(), scores.end(), [](const auto& a, const auto& b) {
            return b.second < a.second;
        });

        clear();
        std::cout << "Ranking:\n";
        for (const auto& entry : scores) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    } else {
        std::cout << "Brak wynikow.\n";
    }

    std::cout << "\nWcisnij dowolny klawisz, aby wrocic do menu...";
    std::cin.ignore();
    std::cin.get();  
}
