/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** movetheplayer
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

int check_end_game(char **map, int nbr_line)
{
    int y = 1;
    int i = 0;

    while (y < nbr_line) {
        if ((map[y][i] == 'o')) {
            return (0);
        }
        if (map[y][i] == '\0') {
            y ++;
            i = 0;
        }
        i++;
    }
    endwin();
    clear();
    write(1, "\n\n\n\t\t\t\t YOU WON !!\n\n\n\n", 23);
    exit(0);
}

int move_up(int x, int y, int nbr_line, char **map)
{
    if (y == 0)
        return y;
    if (map[y - 1][x + 1] == '#')
        return y;
    if (((map[y - 1][x + 1] == 'x') || (map[y - 1][x + 1] == '0')) &&
    (map[y - 2][x + 1] == '#'))
        return y;
    if ((map[y - 1][x + 1] == 'x') && ((map[y - 2][x + 1] == 'x') ||
    (map[y - 2][x + 1] == '0')))
        return y;
    move_up_part2(x, y, nbr_line, map);
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, " ");
    if ((map[y][x + 1] == 'o') || (map[y][x + 1] == '0'))
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, "o");
    mvprintw(y + (LINES / 2) - nbr_line - 1, x + (COLS / 2) + 1, "p");
    move(y + (LINES / 2) - nbr_line - 1, x + (COLS / 2) + 1);
    return (y - 1);
}

int move_down(int x, int y, int nbr_line, char **map)
{
    if (map[y + 1][x + 1] == '#')
        return y;
    if (((map[y + 1][x + 1] == 'x') || (map[y + 1][x + 1] == '0')) &&
    (map[y + 2][x + 1] == '#'))
        return y;
    if ((map[y + 1][x + 1] == 'x') && ((map[y + 2][x + 1] == 'x') ||
    (map[y + 2][x + 1] == '0')))
        return y;
    move_down_part2(x, y, nbr_line, map);
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, " ");
    if ((map[y][x + 1] == 'o') || (map[y][x + 1] == '0'))
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, "o");
    mvprintw(y + (LINES / 2) - nbr_line + 1, x + (COLS / 2) + 1, "p");
    move(y + (LINES / 2) - nbr_line + 1, x + (COLS / 2) + 1);
    return (y + 1);
}

int move_left(int x, int y, int nbr_line, char **map)
{
    if (map[y][x] == '#')
        return x;
    if (((map[y][x] == 'x') || (map[y][x] == '0')) &&
    (map[y][x - 1] == '#'))
        return x;
    if ((map[y][x] == 'x') && ((map[y][x - 1] == 'x') ||
    (map[y][x - 1] == '0')))
        return x;
    move_left_part2(x, y, nbr_line, map);
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, " ");
    if ((map[y][x + 1] == 'o') || (map[y][x + 1] == '0'))
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, "o");
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2), "p");
    move(y + (LINES / 2) - nbr_line, x + (COLS / 2));
    return (x - 1);
}

int move_right(int x, int y, int nbr_line, char **map)
{
    if (map[y][x + 2] == '#')
        return x;
    if (((map[y][x + 2] == 'x') || (map[y][x + 2] == '0')) &&
    (map[y][x + 3] == '#'))
        return x;
    if ((map[y][x + 2] == 'x') && ((map[y][x + 3] == 'x') ||
    (map[y][x + 3] == '0')))
        return x;
    move_right_part2(x, y, nbr_line, map);
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, " ");
    if ((map[y][x + 1] == 'o') || (map[y][x + 1] == '0'))
        mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 1, "o");
    mvprintw(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 2, "p");
    move(y + (LINES / 2) - nbr_line, x + (COLS / 2) + 2);
    return (x + 1);
}
