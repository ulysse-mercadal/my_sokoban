/*
** EPITECH PROJECT, 2023
** sokokban
** File description:
** .h
*/

#ifndef SOKOBAN_H
    #define SOKOBAN_H

int check_end_game(char **map, int nbr_line);
int move_up(int x, int y, int nbr_line, char **map);
void move_up_part2(int x, int y, int nbr_line, char **map);
int move_down(int x, int y, int nbr_line, char **map);
void move_down_part2(int x, int y, int nbr_line, char **map);
int move_left(int x, int y, int nbr_line, char **map);
void move_left_part2(int x, int y, int nbr_line, char **map);
int move_right(int x, int y, int nbr_line, char **map);
void move_right_part2(int x, int y, int nbr_line, char **map);
void printh(void);
int check_map(char **map);
int check_is_a_corner(char **map, int nbr_line);
#endif
