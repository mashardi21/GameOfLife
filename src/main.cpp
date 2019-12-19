#include <iostream>
#include <vector>
#include "../include/board.hpp"

int main() {
    board testBoard;

    std::vector<std::vector<int>> dead = testBoard.deadBoard(5, 6);

    for (int y = 0; y < dead.size(); y++) {
        for (int x = 0; x < dead[y].size(); x++) {
            std::cout << dead[y][x];
        }
        std::cout << std::endl;
    }
}