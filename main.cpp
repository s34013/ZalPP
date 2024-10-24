#include "game.hpp"


std::string currentWorld;
int level = 0;
std::string playerName;
int score = 0;

int main() {
    int choice = 1;

    while (true) {
        menu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                clear();
                startGame();
                break;
            case 2:
                clear();
                chooseLevel();
                break;
            case 3:
                clear();
                showScores();
                break;
            case 4:
                clear();
                std::cout << "Zamykanie gry..." << std::endl;
                exit(0);
            default:
                clear();
                std::cout << "Nieznana opcja. Sprobuj ponownie." << std::endl;
                break;
        }
    }

    return 0;
}

void startGame() {
    currentWorld = getRandomWord();
    if (level == 0) {
        chooseLevel();
    }
    Game game(currentWorld, level);
    if (game.round()) {
        main();
    }
}

std::string getRandomWord() {
    std::ifstream file("words.txt");
    std::vector<std::string> words;

    if (!file.is_open()) {
        std::cout << "Nie mozna otworzyc pliku words.txt" << std::endl;
        return "";
    }

    std::string word;
    while (std::getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }

    file.close();

    std::srand(static_cast<unsigned int>(std::time(0)));
    int randomIndex = std::rand() % words.size();

    return words[randomIndex];
}

void chooseLevel() {
    int levelInput;

    while (true) {
        std::cout << "Wybierz poziom trudnosci (1 = latwy, 2 = trudny): ";
        std::cin >> levelInput;

        if (levelInput == 1 || levelInput == 2) {
            level = levelInput;
            break;
        } else {
            std::cout << "Blad: Prosze podac 1 lub 2." << std::endl;
        }
    }
}
