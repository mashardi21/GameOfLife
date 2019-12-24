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

#include <iostream>
#include <time.h>
#include <vector>
#include "ncurses.h"
#include "../include/board.hpp"

void __init__() {
    initscr();
    cbreak();
    curs_set(0);
    nodelay(stdscr, true);
    keypad(stdscr, true);
}

WINDOW* createWindow(int width, int height, int startX, int startY) {
    WINDOW *localWindow = newwin(height, width, startY, startX);
    box(localWindow, 0, 0);

    return localWindow;
}

int main() {

    int width, height, startX, startY, ch, currentCell;
    char quitButton = 'q';
    board gameBoard;

    __init__();

    width = COLS - 6;
    height = LINES - 4;
    startX = (COLS - width) / 2;
    startY = (LINES - height) / 2;

    WINDOW *myWin = createWindow(width, height, startX, startY);
    gameBoard.randBoard(width - 2, height - 2);

    mvprintw(height + 2, 3, "Exit: q");
    refresh();

    while ((ch = getch()) != (int)quitButton) {
        for(int y = 1; y < height - 1; y++) {
            for (int x = 1; x < width - 1; x++) {
                currentCell = gameBoard.getAlive(x - 1, y - 1);
                
                if(currentCell == 1) {
                    mvwprintw(myWin, y, x, "*");
                } else {
                    mvwprintw(myWin, y, x, " ");
                }
            }
        }
        wrefresh(myWin);
        refresh();
        gameBoard.nextBoardState();
        nanosleep((const struct timespec[]){0, (1000000000L / 60)}, NULL);
    }

    endwin();
}
