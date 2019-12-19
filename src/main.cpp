#include <iostream>
#include <vector>
#include "../include/board.hpp"

int main() {
    board testBoard;

    std::vector<std::vector<int>> test = testBoard.randBoard(5, 6);

    for (int y = 0; y < test.size(); y++) {
        for (int x = 0; x < test[y].size(); x++) {
            std::cout << test[y][x];
        }
        std::cout << std::endl;
    }
}