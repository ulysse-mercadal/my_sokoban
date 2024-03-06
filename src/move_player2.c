/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** next part of move player file
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include "../include/sokoban.h"

void move_up_part2(int x, int y, int nbr_line, char **map)
{
    if (map[y - 1][x + 1] == '0' && (map[y - 2][x + 1] != '#') &&
    (map[y - 2][x + 1] != 'x')) {
        map[y - 1][x + 1] = 'o';
        map[y - 2][x + 1] = 'x';
        mvprintw(y + (LINES / 2) - nbr_line - 2, x + (COLS / 2) + 1, "x");
    }
    if ((map[y - 1][x + 1] == 'x') && (map[y - 2][x + 1] == 'o')) {
        map[y - 2][x + 1] = '0';
        map[y - 1][x + 1] = ' ';
        mvprintw(y + (LINES / 2) - nbr_line - 2, x + (COLS / 2) + 1, "x");
    }
    if ((map[y - 1][x + 1] == 'x') && (map[y - 2][x + 1] != '0') &&
    (map[y - 2][x + 1] != 'o') && (map[y - 2][x + 1] != '#')) {
        mvprintw(y + (LINES / 2) - nbr_line - 2, x + (COLS / 2) + 1, "x");
        map[y - 1][x + 1] = ' ';
        map[y - 2][x + 1] = 'x';
    }
}

void move_down_part2(int x, int y, int nbr_line, char **map)
{
    if (map[y + 1][x + 1] == '0' && (map[y + 2][x + 1] != '#') &&
    (map[y + 2][x + 1] != 'x')) {
        map[y + 1][x + 1] = 'o';
        map[y + 2][x + 1] = 'x';
        mvprintw(y + (LINES / 2) - nbr_line + 2, x + (COLS / 2) + 1, "x");
    }
    if ((map[y + 1][x + 1] == 'x') && (map[y + 2][x + 1] == 'o')) {
        map[y + 2][x + 1] = '0';
        map[y + 1][x + 1] = ' ';
        mvprintw(y + (LINES / 2) - nbr_line + 2, x + (COLS / 2) + 1, "x");
    }
    if ((map[y + 1][x + 1] == 'x') && (map[y + 2][x + 1] != '0') &&
    (map[y + 2][x + 1] != 'o') && (map[y + 2][x + 1] != '#')) {
        mvprintw(y + (LINES / 2) - nbr_line + 2, x + (COLS / 2) + 1, "x");
        map[y + 1][x + 1] = ' ';
        map[y + 2][x + 1] = 'x';
    }
}

void move_left_part2(int x, int y, int nbr_line, char **map)
{
    if (map[y][x] == '0' && (map[y][x - 1] != '#') &&
    (map[y][x - 1] != 'x')) {
        map[y][x] = 'o';
        map[y][x - 1] = 'x';
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) - 1, "x");
    }
    if ((map[y][x] == 'x') && (map[y][x - 1] == 'o')) {
        map[y][x - 1] = '0';
        map[y][x] = ' ';
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) - 1, "x");
    }
    if ((map[y][x] == 'x') && (map[y][x - 1] != '0') &&
    (map[y][x - 1] != 'o') && (map[y][x - 1] != '#')) {
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) - 1, "x");
        map[y][x] = ' ';
        map[y][x - 1] = 'x';
    }
}

void move_right_part2(int x, int y, int nbr_line, char **map)
{
    if (map[y][x + 2] == '0' && (map[y][x + 3] != '#') &&
    (map[y][x + 3] != 'x')) {
        map[y][x + 2] = 'o';
        map[y][x + 3] = 'x';
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 3, "x");
    }
    if ((map[y][x + 2] == 'x') && (map[y][x + 3] == 'o')) {
        map[y][x + 3] = '0';
        map[y][x + 2] = ' ';
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 3, "x");
    }
    if ((map[y][x + 2] == 'x') && (map[y][x + 3] != '0') &&
    (map[y][x + 3] != 'o') && (map[y][x + 3] != '#')) {
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 3, "x");
        map[y][x + 2] = ' ';
        map[y][x + 3] = 'x';
    }
}
