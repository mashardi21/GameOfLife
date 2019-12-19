#include <iostream>
#include <vector>
#include "../include/board.hpp"

int main() {
    board testBoard;

    testBoard.randBoard(6, 5);

    testBoard.render();
}