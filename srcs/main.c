#include "../headers/cub3d.h"

void initialize_cube(t_cub *cub) {
  cub->map_file = NULL;
  cub->map = NULL;
  cub->e_texture = NULL;
  cub->w_texture = NULL;
  cub->s_texture = NULL;
  cub->n_texture = NULL;
}

int main(int ac, char **av) {
  t_cub *cub;

  if (ac != 2 || !correct_file_extension(av[1])) {
    return (printf("Error\nFormat expected [./cub3d] [file.cub]\n"));
  }
  cub = malloc(sizeof(t_cub));
  initialize_cube(cub);
  if (!download_map(cub, av[1]) || !parse_map_format(cub))
    return (free(cub), -1);
  free_cube(cub);
  return (0);
}
