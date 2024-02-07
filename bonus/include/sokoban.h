/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_
    #define SOKOBAN_

int is_valid_map(char *path);
void print_help(void);
char **generate_map(char *path, int *lines, int *columns);
void replace_map(char **map, int lines, int columns);
void replace_map_o(char **map, int lines, int columns);
void input_player(int key, char **map, int *lines, int *columns);
void print_map(char **map, char **map_o, int lines, int columns);
int player_x(char **map, int lines, int columns);
int player_y(char **map, int lines, int columns);
int check_win(char **map, char **map_o, int lines, int columns);
int check_lose(char **map, char **map_o, int vals[2], char *path);
int down_map(char **map, int value[2], int vals[2]);
int up_map(char **map, int value[2], int vals[2]);
int left_map(char **map, int value[2], int vals[2]);
int right_map(char **map, int value[2], int vals[2]);
void input_player_two(int key, char **map, int *lines, int *columns);
int player_y_two(char **map, int lines, int columns);
int player_x_two(char **map, int lines, int columns);

int first_player(int argc, char **argv, int socket_client);
int player_two(int socket_client);
int get_y_tp(char **map, int lines, int columns);
int get_x_tp(char **map, int lines, int columns);
int get_y_tp_two(char **map, int lines, int columns);
int get_x_tp_two(char **map, int lines, int columns);
int get_y_tp_l(char **map, int lines, int columns);
int get_x_tp_l(char **map, int lines, int columns);
int get_y_tp_two_l(char **map, int lines, int columns);
int get_x_tp_two_l(char **map, int lines, int columns);
void check_tp(char **map, char **map_o, int lines, int columns);
void check_tp_two(char **map, char **map_o, int lines, int columns);
void check_tp_box(char **map, char **map_o, int lines, int columns);

#endif /* !SOKOBAN_ */
