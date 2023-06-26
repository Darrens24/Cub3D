#include "../headers/cub3d.h"
#include <fcntl.h>

int correct_map_extension(char *name) {
  if (ft_strlen(name) < 5)
    return (FALSE);
  if (ft_strncmp(".cub", (name + ft_strlen(name) - 4), 5) != 0)
    return (FALSE);
  return (TRUE);
}

// int map_content_ok(char **map) { return (TRUE); }

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
    printf("%s", map[i]);
    i++;
  }
}

int download_map(t_cub *cub, char *av1) {
  int fd;
  int i;
  int file_size;

  fd = 0;
  file_size = get_file_size(fd, av1);
  if (!file_size)
    return (FALSE);
  cub->map = malloc(sizeof(char *) * (file_size + 1));
  if (!cub->map)
    return (printf("Error\nMalloc error\n"), FALSE);
  fd = open(av1, O_RDONLY);
  if (fd < 0)
    return (printf("Error\nCouldn't open file %s\n", av1), FALSE);
  i = -1;
  while (++i < file_size)
    cub->map[i] = get_next_line(fd);
  cub->map[i] = NULL;
  print_map(cub->map);
  return (TRUE);
}

int main(int ac, char **av) {
  t_cub *cub;

  if (ac != 2 || !correct_map_extension(av[1])) {
    return (printf("Error\nFormat expected [./cub3d] [file.cub]\n"));
  }
  cub = malloc(sizeof(t_cub));
  if (!download_map(cub, av[1]))
    return (free(cub), -1);

  return (0);
}
