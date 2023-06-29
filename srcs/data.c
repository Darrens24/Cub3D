#include "../headers/cub3d.h"

int get_file_size(int fd, char *av1) {

  char *buffer;
  int file_size;

  fd = open(av1, O_RDONLY);
  if (fd < 0)
    return (printf("Error\nCouldn't open file %s\n", av1), FALSE);
  buffer = ft_calloc(1, 1);
  file_size = 0;
  while (buffer) {
    free(buffer);
    buffer = get_next_line(fd);
    if (buffer)
      file_size++;
  }
  close(fd);
  return (file_size);
}

void print_map(char **map) {

  int i = 0;
  while (map[i]) {
    printf("%s\n", map[i]);
    i++;
  }
}

int download_map(t_cub *cub, char *av1) {

  int fd;
  unsigned int i;

  fd = 0;
  cub->nb_of_file_lines = get_file_size(fd, av1);
  if (!cub->nb_of_file_lines)
    return (FALSE);
  cub->map_file = malloc(sizeof(char *) * (cub->nb_of_file_lines + 1));
  if (!cub->map_file)
    return (printf("Error\nMalloc error\n"), FALSE);
  fd = open(av1, O_RDONLY);
  if (fd < 0)
    return (printf("Error\nCouldn't open file %s\n", av1), FALSE);
  i = -1;
  while (++i < cub->nb_of_file_lines)
    cub->map_file[i] = get_next_line(fd);
  cub->map_file[i] = NULL;
  return (TRUE);
}
