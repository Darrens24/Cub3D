#ifndef CUB3D_H
#define CUB3D_H

#define TRUE 1
#define FALSE 0

#include "../Libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_point {
  int x;
  int y;
} t_point;

typedef struct s_cub {
  char **map;
  uint map_width;
  uint map_height;
  char p_orient;
  struct s_point p;
} t_cub;

#endif

/*
 * len .ber = 4

 */
