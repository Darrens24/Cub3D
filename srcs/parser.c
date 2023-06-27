#include "../headers/cub3d.h"

void initialize_parser(t_parser *parser, t_cub *cub) {

  int i;

  parser->textures = malloc(sizeof(char *) * (NB_TEXTURES + 1));
  if (!parser->textures)
    return;
  i = -1;
  while (++i < (NB_TEXTURES + 1))
    parser->textures[i] = NULL;
  i = -1;
  while (++i < 3)
    parser->colors[i] = 0;
  parser->map = NULL;
  parser->allowed_ids[0] = "NO";
  parser->allowed_ids[1] = "SO";
  parser->allowed_ids[2] = "WE";
  parser->allowed_ids[3] = "EA";
  parser->allowed_ids[4] = "F";
  parser->allowed_ids[5] = "C";
}

int valid_paths_and_color_format(t_parser *parser) {
  int i;

  i = -1;
  while (parser->textures[++i]) {
    if (ft_strncmp("F", parser->textures[i][0], 2) == 0 ||
        ft_strncmp("C", parser->textures[i][0], 2) == 0) {
      if (!check_store_color_format(parser->colors, parser->textures[i]))
        return (FALSE);
    } else {
      if (!check_store_path_format(parser->tex_paths, parser->textures[i]))
        return (FALSE);
    }
  }
  return (TRUE);
}

void store_parser_data(t_parser *parser, t_cub *cub) {

  int i;
  int j;

  i = 0;
  while (cub->map_file[i] && i < NB_TEXTURES) {
    if (ft_strncmp(cub->map_file[i], "\n", 1) != 0) {
      parser->textures[i] = ft_split(cub->map_file[i], ' ');
      if (!good_texture_format(parser->allowed_ids, parser->textures[i]))
        free_and_exit(parser, cub);
      i++;
    }
  }
  if (!check_if_all_textures(parser) || !valid_paths_and_color_format(parser))
    free_and_exit(parser, cub);
  while (cub->map_file[i] && ft_strncmp(cub->map_file[i], "\n", 1) == 0) {
    i++;
  }
  j = 0;
  if (cub->map_file[i])
    while (cub->map_file[i])
      parser->map[j++] = cub->map_file[i++];
}
