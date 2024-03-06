/*
** EPITECH PROJECT, 2023
** sokokban
** File description:
** printf the -h flag
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>

int check_map(char **map)
{
    int y = 0;

    for (int i = 0; map[i][y] != '\0'; y ++) {
        if ((map[i][y] != ' ') && (map[i][y] != 'x') && (map[i][y] != 'p') &&
        (map[i][y] != 'o') && (map[i][y] != '#') && (map[i][y] != '\n') &&
        (map[i][y] != '\0') && (map[i][y] != '0')) {
            endwin();
            clear();
            write(2, "\nwrong map format !\n\n", 22);
            exit(84);
        }
        if (map[i][y] == '\n') {
            y = 0;
            i ++;
        }
    }
    return (1);
}

void printh(void)
{
    write(1, "USAGE\n", 7);
    write(1, "     ./my_sokoban map\n", 23);
    write(1, "DESCRIPTION\n", 13);
    write(1, "     map  file representing the warehouse map, ", 48);
    write(1, "containing '#' for walls,\n", 27);
    write(1, "          'P' for the player, 'X' for boxes and", 48);
    write(1, " 'O' for storage locations.\n", 29);
}
