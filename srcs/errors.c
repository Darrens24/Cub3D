#include "../headers/cub3d.h"

int correct_file_extension(char *name) {

  if (ft_strlen(name) < 5)
    return (FALSE);
  if (ft_strncmp(".cub", (name + ft_strlen(name) - 4), 5) != 0)
    return (FALSE);
  return (TRUE);
}

int good_texture_format(char *allowed[6], char **splitted_texture) {
  int i;

  i = -1;
  while (++i < 6) {
    if (!splitted_texture[1] || splitted_texture[2])
      return (FALSE);
    if (ft_strncmp(splitted_texture[0], allowed[i],
                   ft_strlen(splitted_texture[0])) == 0)
      return (i);
  }
  return (FALSE);
}

int check_store_path_format(char *paths[4], char **texture) {

  int i;
  int fd;

  i = -1;
  while (++i < 4) {
    paths[i] = ft_strdup(texture[1]);
    fd = open(paths[i], O_RDONLY);
    if (fd < 0)
      return (perror("open"), FALSE);
  }
  return (TRUE);
}

int check_store_color_format(int colors[3], char **texture) {
  int i;
  int j;
  char **coma_splitted_color;

  i = -1;
  while (texture[1][++i])
    if (!ft_isdigit(texture[1][i]) && texture[1][i] != ',')
      return (FALSE);
  coma_splitted_color = ft_split(texture[1], ',');
  if (!coma_splitted_color[1] || !coma_splitted_color[2] ||
      coma_splitted_color[3])
    return (free_array(coma_splitted_color), FALSE);
  j = -1;
  while (coma_splitted_color[++j]) {
    if (ft_strlen(coma_splitted_color[j]) > 3)
      return (free_array(coma_splitted_color), FALSE);
    colors[j] = ft_atoi(coma_splitted_color[j]);
    if (colors[j] < 0 || colors[j] > 255)
      return (free_array(coma_splitted_color), FALSE);
  }
  return (TRUE);
}

int check_if_all_textures(t_parser *parser) {
  int i;
  t_texchek check;

  i = -1;
  while (parser->textures[++i]) {
    if (ft_strncmp(parser->textures[i][0], "EA", 3) == 0)
      check.east = 1;
    else if (ft_strncmp(parser->textures[i][0], "NO", 3) == 0)
      check.north = 1;
    else if (ft_strncmp(parser->textures[i][0], "SO", 3) == 0)
      check.south = 1;
    else if (ft_strncmp(parser->textures[i][0], "WE", 3) == 0)
      check.west = 1;
    else if (ft_strncmp(parser->textures[i][0], "F", 1) == 0)
      check.floor = 1;
    else if (ft_strncmp(parser->textures[i][0], "C", 1) == 0)
      check.ceil = 1;
  }
  if (check.ceil != 1 || check.floor != 1 || check.west != 1 ||
      check.east != 1 || check.north != 1 || check.south != 1) {
    printf("Error\nMap needs [EAST][WEST][SOUTH][NORTH][FLOOR][CEIL]\n");
    return (FALSE);
  }
  return (TRUE);
}

int wrong_map_format(t_cub *cub) {
  t_parser *parser;

  parser = malloc(sizeof(t_parser));
  initialize_parser(parser, cub);
  store_parser_data(parser, cub);
  // if (allowed_data)

  return (FALSE);
}
