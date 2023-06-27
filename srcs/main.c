#include "../headers/cub3d.h"

// int map_content_ok(char **map) { return (TRUE); }

int main(int ac, char **av) {
  t_cub *cub;

  if (ac != 2 || !correct_file_extension(av[1])) {
    return (printf("Error\nFormat expected [./cub3d] [file.cub]\n"));
  }
  cub = malloc(sizeof(t_cub));
  printf("Bonjour, avant de download\n");
  if (!download_map(cub, av[1]) || !parse_map_format(cub))
    return (free(cub), -1);
  printf("Bonjour, apres le download\n");
  return (0);
}
