#include "board.hpp"

board::board() {
    deadBoard(5, 5);
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
    int dispWidth = boardState[0].size();
    int dispHeight = boardState.size();

    //clearScreen();

    for (int i = 0; i < dispWidth - 1; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;

    for (int y = 0; y < dispHeight; y++) {
        std::cout << "|";

        for (int x = 0; x < dispWidth; x++) {
            if (boardState[y][x] == 0) {
                std::cout << " ";
            } else if (boardState[y][x] == 1) {
                std::cout << "#";
            }
        }
        std::cout << "|" << std::endl;
    }

    for (int i = 0; i < dispWidth - 1; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;
}

void board::nextBoardState() {
    // Rules:
    // 1. If a live cell has 0 or 1 live neighbors, it dies
    // 2. If a live cell has more than 3 live neighbors, it dies
    // 3. If a live cell has 2 or 3 live neighbors, it stays alive
    // 4. If a dead cell has exactly 3 live neighbors, it becomes alive

    int numLiveNeighbors = 0;
    std::vector<std::vector<int>> temp = boardState;

    for (int y = 0; y < boardState.size(); y++) {
        for (int x = 0; x < boardState[0].size(); x++) {
            numLiveNeighbors = 0;

            if (x == 0) {
                if(y == 0) {
                    if (temp[y + 1][x] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y][x + 1]) numLiveNeighbors++;
                } else if (y == boardState.size() - 1) {
                    if (temp[y][x + 1]) numLiveNeighbors++;

                    if (temp[y - 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x]) numLiveNeighbors++;
                } else {
                    if (temp[y + 1][x] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y][x + 1]) numLiveNeighbors++;

                    if (temp[y - 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x]) numLiveNeighbors++;
                }
            } else if (x == boardState[0].size() - 1) {
                if(y == 0) {
                    if (temp[y + 1][x] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y][x - 1]) numLiveNeighbors++;
                } else if (y == boardState.size() - 1) {
                    if (temp[y][x - 1]) numLiveNeighbors++;

                    if (temp[y - 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x]) numLiveNeighbors++;
                } else {
                    if (temp[y + 1][x] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y][x - 1]) numLiveNeighbors++;

                    if (temp[y - 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x]) numLiveNeighbors++;
                }
            } else {
                if(y == 0) {
                    if (temp[y][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x]) numLiveNeighbors++;

                    if (temp[y + 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y][x + 1]) numLiveNeighbors++;
                } else if (y == boardState.size() - 1) {
                    if (temp[y][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x]) numLiveNeighbors++;

                    if (temp[y - 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y][x + 1]) numLiveNeighbors++;
                } else {
                    if (temp[y][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x - 1] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x] == 1) numLiveNeighbors++;

                    if (temp[y - 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x + 1] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x] == 1) numLiveNeighbors++;

                    if (temp[y + 1][x - 1] == 1) numLiveNeighbors++;
                }
            }

            if (boardState[y][x] == 0) {
                if (numLiveNeighbors == 3) {
                    boardState[y][x] = 1;
                } else {
                    boardState[y][x] = 0;
                }
            } else {
                if (numLiveNeighbors < 2 || numLiveNeighbors > 3) {
                    boardState[y][x] = 0;
                } else {
                    boardState[y][x] = 1;
                }
            }
        }
    }
}

// I'm not using ncurses because I plan to switch to a graphical implementation in the future
// This implementation of clearScreen is temporary
void board::clearScreen() {
    std::cout << std::string(100, '\n');
}