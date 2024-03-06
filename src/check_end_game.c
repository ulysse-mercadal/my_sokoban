/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** check if all boxes are in corners
*/
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

int is_a_corner(char **map, int x, int y)
{
    if ((map[x][y] == 'x') || (map[x][y] == '0'))
        if (((map[x - 1][y] == '#') || (x == 1) || (map[x - 1][y] == '0')) &&
        ((map[x][y + 1] == '#') || (map[x][y + 1] == '0')))
            return 1;
    if ((map[x][y] == 'x') || (map[x][y] == '0'))
        if (((map[x + 1][y] == '#') || (x == 1) || (map[x + 1][y] == '0')) &&
        ((map[x][y + 1] == '#') || (map[x][y + 1] == '0')))
            return 1;
    if ((map[x][y] == 'x') || (map[x][y] == '0'))
        if (((map[x + 1][y] == '#') || (x == 1) || (map[x + 1][y] == '0')) &&
        ((map[x][y - 1] == '#') || (map[x][y - 1] == '0')))
            return 1;
    if ((map[x][y] == 'x') || (map[x][y] == '0'))
        if (((map[x - 1][y] == '#') || (x == 1) || (map[x - 1][y] == '#')) &&
        ((map[x][y - 1] == '#') || (map[x][y - 1] == '0')))
            return 1;
    return 0;
}

void print_end(void)
{
    usleep(200000);
    endwin();
    clear();
    write(1, "\n\n\n\t\t\t\t YOU LOSE...\n\n\n\n", 24);
    exit(0);
}

int check_is_a_corner(char **map, int nbr_line)
{
    int y = 0;
    int status = 0;
    int nbr_boxes = 0;
    int x = 1;

    while (x != nbr_line) {
        if (map[x][y] == '\n') {
            y = 0;
            x ++;
        }
        if ((map[x][y] == 'x') || (map[x][y] == '0'))
            nbr_boxes ++;
        status += is_a_corner(map, x, y);
        y ++;
    }
    if (status == nbr_boxes) {
        print_end();
    }
    return 0;
}
