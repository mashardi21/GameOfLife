#include "board.hpp"

board::board() {
    deadBoard(5, 5);
}

std::vector<std::vector<int>> board::deadBoard(int width, int height) {
    boardState.clear();

    std::vector<int> temp;

    for (int i = 0; i < height; i++) {
        temp.clear();
        for (int i = 0; i < width; i++) {
            temp.push_back(0);
        }
        boardState.push_back(temp);
    }

    return boardState;
}