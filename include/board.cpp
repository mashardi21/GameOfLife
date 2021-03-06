/*
    GameOfLife - My implementation of Conway's Game of Life
    Copyright (C) 2019  Mason Hardin

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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

int board::getAlive(int x, int y) {
    return boardState[y][x];
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