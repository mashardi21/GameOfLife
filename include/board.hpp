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
    int getAlive(int x, int y);
    void nextBoardState();
};

#endif