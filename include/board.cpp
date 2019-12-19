#include "board.hpp"

board::board() {
    deadBoard(5, 5);
}

board::board(int width, int height, int state) {
    switch (state) {
    case 0:
        deadBoard(width, height);
    case 1:
        randBoard(width, height);
    default:
        deadBoard(width, height);
    }
}

void board::deadBoard(int width, int height) {
    boardState.clear();

    std::vector<int> temp;

    for (int y = 0; y < height; y++) {
        temp.clear();
        for (int x = 0; x < width; x++) {
            temp.push_back(0);
        }
        boardState.push_back(temp);
    }
}

void board::randBoard(int width, int height) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    deadBoard(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            boardState[y][x] = dist(mt);
        }
    }
}

void board::render() {
    int dispWidth = boardState[0].size() + 2;
    int dispHeight = boardState.size();

    clearScreen();

    for (int i = 0; i < dispWidth - 1; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;

    for (int y = 0; y < dispHeight; y++) {
        for (int x = 0; x < dispWidth; x++) {
            if (x == 0 || x == dispWidth - 1) {
                std::cout << "|";
            } else if (boardState[y][x] == 0) {
                std::cout << " ";
            } else if (boardState[y][x] == 1) {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < dispWidth - 1; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;
}

// I'm not using ncurses because I plan to switch to a graphical implementation in the future
// This implementation of clearScreen is temporary
void board::clearScreen() {
    std::cout << std::string(100, '\n');
}