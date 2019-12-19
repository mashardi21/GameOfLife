#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

class board {
private:
    std::vector<std::vector<int>> boardState;
public:
    board();
    board(int width, int height);
    std::vector<std::vector<int>> deadBoard(int width, int height);
};

#endif