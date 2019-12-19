#include "board.hpp"

board::board() {
    deadBoard(5, 5);
}

std::vector<std::vector<int>> board::deadBoard(int width, int height) {
    boardState.clear();

    std::vector<int> temp;

    for (int y = 0; y < height; y++) {
        temp.clear();
        for (int x = 0; x < width; x++) {
            temp.push_back(0);
        }
        boardState.push_back(temp);
    }

    return boardState;
}

std::vector<std::vector<int>> board::randBoard(int width, int height) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);

    boardState = deadBoard(width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            boardState[y][x] = dist(mt);
        }
    }

    return boardState;
}