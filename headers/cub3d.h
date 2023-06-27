#ifndef CUB3D_H
#define CUB3D_H

#define TRUE 1
#define FALSE 0
#define NB_TEXTURES 6

#include "../Libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/***\ structures \***/

typedef struct s_point {
  int x;
  int y;
} t_point;

typedef struct s_parser {
  char ***textures;
  int colors[3];
  char *tex_paths[4];
  char **map;
  char *allowed_ids[6];
  int tmp_p;
  char orient;
} t_parser;

typedef struct s_textures_check {
  int east;
  int west;
  int north;
  int south;
  int floor;
  int ceil;
} t_texchek;

typedef struct s_cub {
  char **map_file;
  char **map;
  char *e_texture;
  char *w_texture;
  char *s_texture;
  char *n_texture;
  int c_color[3];
  int f_color[3];
  uint nb_of_file_lines;
  uint map_height;
  char p_orient;
  struct s_point p;
} t_cub;

/***\ errors \***/

int correct_file_extension(char *name);
int good_texture_format(char *allowed[6], char **splitted_texture);
int valid_paths_and_color_format(t_parser *parser, t_cub *cub);
int check_if_all_textures(t_parser *parser);

/***\ data \***/

int get_file_size(int fd, char *av1);
void print_map(char **map);
int download_map(t_cub *cub, char *av1);
void free_and_exit(t_parser *parser, t_cub *cub);
void free_array(char **array);
void free_parser_memory(t_parser *parser);
void free_cube(t_cub *cub);

/***\ parser \***/

int parse_map_format(t_cub *cub);
void initialize_parser(t_parser *parser);
void store_parser_data(t_parser *parser, t_cub *cub);
int check_store_color_format(char mode, t_cub *cub, int colors[3],
                             char **texture);
int check_store_path_format(t_cub *cub, int j, char *paths[4], char **texture);

/***\ map analyze \***/

int map_analyze(t_parser *parser, t_cub *cub);

#endif

/*
 * parcours du fichier telecharge dans map_file

 */
