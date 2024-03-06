/*
** EPITECH PROJECT, 2023
** my_popup
** File description:
** print hello world on the center of the screen
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

void write_map(int nbr_line, char **map, int *x, int *y)
{
    check_map(map);
    for (int i = 0; i < nbr_line; i++)
        mvprintw(LINES / 2 - nbr_line + i, COLS / 2, "%s", map[i]);
    for (int i = 0; map[*y][i] != 'p'; i++) {
        if (map[*y][i] == '\0') {
            (*y) ++;
            i = 0;
        }
        *x = i;
    }
    move(*y + (LINES / 2) - nbr_line, *x + (COLS / 2) + 1);
}

void game(char **map, int nbr_line, int x)
{
    int key = 0;
    int y = 1;

    keypad(initscr(), TRUE);
    write_map(nbr_line, map, &x, &y);
    while (check_is_a_corner(map, nbr_line) == 0) {
        key = getch();
        if (key == ' ')
            game(map, nbr_line, x);
        if (key == KEY_UP)
            y = move_up(x, y, nbr_line, map);
        if (key == KEY_DOWN)
            y = move_down(x, y, nbr_line, map);
        if (key == KEY_LEFT)
            x = move_left(x, y, nbr_line, map);
        if (key == KEY_RIGHT)
            x = move_right(x, y, nbr_line, map);
        refresh();
        check_end_game(map, nbr_line);
    }
}

void my_str_to_world_array(int file_size, int nbr_line, int line_len, int fd)
{
    int y = 0;
    char *buffer;
    int x = 0;
    char **result;
    int x2 = 0;

    buffer = malloc(sizeof(char) * file_size + 1);
    result = malloc(sizeof(char *) * nbr_line);
    result[0] = malloc(sizeof(char *) * line_len);
    while (read(fd, buffer, (intmax_t)file_size > 0)) {
        result[y][x] = *buffer;
        x++;
        if (*buffer == '\n') {
            result[y][x] = '\0';
            y++;
            x = 0;
            result[y] = malloc(sizeof(int *) * line_len);
        }
    }
    game(result, nbr_line, x2);
}

void get_map(int fd, char *file_name)
{
    char *buffer;
    int line = 0;
    int nbr_char;
    struct stat file_info;
    int file_size;

    fstat(fd, &file_info);
    file_size = file_info.st_size;
    buffer = malloc(sizeof(char) * file_size + 1);
    while (read(fd, buffer, (intmax_t)file_size > 0)) {
        if (*buffer == '\n')
            line++;
        nbr_char++;
    }
    close(fd);
    fd = open(file_name, O_RDWR);
    my_str_to_world_array(file_size, line, nbr_char, fd);
}

int main(int argc, char **argv)
{
    int fd;

    if (argc == 2) {
        if ((argv[1][0] == '-') || (argv[1][1] == 'h')) {
            printh();
            return (0);
        }
        fd = open(argv[1], O_RDWR);
        if (fd == -1) {
            write(2, "sokoban: No such file or is a directory\n", 41);
            return (84);
        }
        get_map(fd, argv[1]);
    } else {
        write(2, "sokoban: wrong usage, use -h for more informations\n", 52);
        return 84;
    }
    return 0;
}
