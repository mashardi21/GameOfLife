#include <iostream>
#include <vector>
#include "../include/board.hpp"

int main() {
    board testBoard;

    testBoard.randBoard(3, 3);

    testBoard.render();

    std::cout << std::endl << std::endl;

    testBoard.nextBoardState();

    testBoard.render();
}