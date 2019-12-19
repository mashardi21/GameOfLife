#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <random>

class board {
private:
    std::vector<std::vector<int>> boardState;
public:
    board();
    board(int width, int height);
    std::vector<std::vector<int>> deadBoard(int width, int height);
    std::vector<std::vector<int>> randBoard(int width, int height);
};

#endif