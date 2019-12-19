#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <vector>
#include <random>

class board {
private:
    std::vector<std::vector<int>> boardState;
public:
    board();
    void deadBoard(int width, int height);
    void randBoard(int width, int height);
    void render();
    void nextBoardState();
    void clearScreen();
};

#endif