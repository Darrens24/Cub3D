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
    if (splitted_texture[1] == NULL || splitted_texture[2] != NULL) {
      return (FALSE);
    }
    // printf("coucou2\n");
    if (ft_strncmp(splitted_texture[0], allowed[i],
                   ft_strlen(splitted_texture[0])) == 0) {
      // printf("found %s\n", allowed[i]);
      return (TRUE);
    }
  }
  // printf("didnt find it\n");
  return (FALSE);
}

int check_store_path_format(t_cub *cub, int j, char *paths[4], char **texture) {

  int fd;
  (void)cub;

  // printf("path[%d] is %s\n", j, texture[1]);
  // printf("texturetype is %s\n", texture[0]);
  paths[j] = ft_strtrim(texture[1], "\n");
  fd = open(paths[j], O_RDONLY);
  if (fd < 0) {
    free(paths[j]);
    return (perror("open"), FALSE);
  }
  if (ft_strncmp(texture[0], "EA", 3) == 0)
    cub->e_texture = ft_strdup(paths[j]);
  else if (ft_strncmp(texture[0], "WE", 3) == 0)
    cub->w_texture = ft_strdup(paths[j]);
  else if (ft_strncmp(texture[0], "NO", 3) == 0)
    cub->n_texture = ft_strdup(paths[j]);
  else if (ft_strncmp(texture[0], "SO", 3) == 0)
    cub->s_texture = ft_strdup(paths[j]);
  free(paths[j]);
  close(fd);
  return (TRUE);
}

int check_store_color_format(char mode, t_cub *cub, int colors[3],
                             char **texture) {
  int i;
  int j;
  char **coma_splitted_color;
  char *temp;

  i = -1;
  // printf("our color is %s\n", texture[1]);
  temp = ft_strtrim(texture[1], "\n");
  while (temp[++i]) {
    if (!ft_isdigit(temp[i]) && temp[i] != ',')
      return (FALSE);
  }
  free(temp);
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
    if (mode == 'c')
      cub->c_color[j] = colors[j];
    else if (mode == 'f')
      cub->f_color[j] = colors[j];
  }
  return (free_array(coma_splitted_color), TRUE);
}

int check_if_all_textures(t_parser *parser) {
  int i;
  t_texchek check;

  i = -1;
  while (parser->textures[++i]) {
    // printf("we evaluate %s\n", parser->textures[i][0]);
    if (ft_strncmp(parser->textures[i][0], "EA", 3) == 0) {
      printf("east ok\n");
      check.east = 1;
    } else if (ft_strncmp(parser->textures[i][0], "NO", 3) == 0) {
      printf("north ok\n");
      check.north = 1;
    } else if (ft_strncmp(parser->textures[i][0], "SO", 3) == 0) {
      printf("south ok\n");
      check.south = 1;
    } else if (ft_strncmp(parser->textures[i][0], "WE", 3) == 0) {
      printf("west ok\n");
      check.west = 1;
    } else if (ft_strncmp(parser->textures[i][0], "F", 1) == 0) {
      printf("floor ok\n");
      check.floor = 1;
    } else if (ft_strncmp(parser->textures[i][0], "C", 1) == 0) {
      printf("ceil ok\n");
      check.ceil = 1;
    }
  }
  if (check.ceil != 1 || check.floor != 1 || check.west != 1 ||
      check.east != 1 || check.north != 1 || check.south != 1) {
    printf("Error\nMap needs [EAST][WEST][SOUTH][NORTH][FLOOR][CEIL]\n");
    return (FALSE);
  }
  printf("everything is good mate\n");
  return (TRUE);
}

int is_closing_map(char **map) {
  (void)map;
  return (TRUE);
}

int map_line_conformity(char *map_line) {
  int j;

  j = -1;
  while (map_line[++j]) {
    if (map_line[j] != '0' && map_line[j] != '1' && map_line[j] != 'E' &&
        map_line[j] != 'W' && map_line[j] != 'S' && map_line[j] != 'N') {
      printf("Error\nCharacter not allowed\n");
      return (FALSE);
    }
  }
  return (TRUE);
}

int duplicate_player(char *map_line, t_parser *parser) {
  int j;

  j = -1;
  while (map_line[++j]) {
    if (map_line[j] == 'E' || map_line[j] == 'W' || map_line[j] == 'S' ||
        map_line[j] == 'N') {
      parser->tmp_p++;
    }
  }
  if (parser->tmp_p > 1)
    return (FALSE);
  return (TRUE);
}

int map_analyze(t_parser *parser) {
  int i;

  i = -1;
  while (parser->map[++i]) {
    if (ft_strncmp(parser->map[i], "\n", 2) == 0)
      return (FALSE);
    parser->map[i] = ft_strtrim(parser->map[i], "\n");
    if (!map_line_conformity(parser->map[i]) ||
        !duplicate_player(parser->map[i], parser))
      return (FALSE);
  }
  if (parser->tmp_p != 1 || !is_closing_map(parser->map)) {
    return (FALSE);
  }
  return (TRUE);
}

int parse_map_format(t_cub *cub) {
  t_parser *parser;

  parser = malloc(sizeof(t_parser));
  initialize_parser(parser);
  store_parser_data(parser, cub);
  if (map_analyze(parser) == FALSE) {
    printf("Error\nBad map format\n");
    // free_parser_memory(parser);
    return (FALSE);
  }
  // definitive_program_data(parser, cub);
  // free_parser_memory(parser);

  return (TRUE);
}
