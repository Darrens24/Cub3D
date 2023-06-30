#include "../headers/cub3d.h"

void initialize_parser(t_parser *parser) {

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
  parser->map = NULL;
  parser->tmp_p = 0;
}

int valid_paths_and_color_format(t_parser *parser, t_cub *cub) {
  int i;
  int j;

  i = -1;
  j = 0;
  while (parser->textures[++i]) {
    if (ft_strncmp("F", parser->textures[i][0], 2) == 0) {
      if (!check_store_color_format('f', cub, parser->colors,
                                    parser->textures[i])) {
        return (FALSE);
      }
    } else if (ft_strncmp("C", parser->textures[i][0], 2) == 0) {
      if (!check_store_color_format('c', cub, parser->colors,
                                    parser->textures[i]))
	  {
        return (FALSE);
	  }
    } else {
      // printf("coucou texture ^^\n");
      if (!check_store_path_format(cub, j, parser->tex_paths,
                                   parser->textures[i]))
	  {
        return (FALSE);
	  }
      j++;
    }
  }
  return (TRUE);
}

int get_map_size(t_cub *cub, int i) {
  int j;

  j = 0;
  cub->max_wid = 0;
  while (cub->map_file[i]) {
	  if ((int)ft_strlen(cub->map_file[i]) > cub->max_wid)
		  cub->max_wid = (int)ft_strlen(cub->map_file[i]);
    i++;
    j++;
  }
  cub->map_height = j;
  cub->max_hei = j;
  return (j);
}

void store_parser_data(t_parser *parser, t_cub *cub) {

  int i;
  int j;
  int filled;

  i = 0;
  filled = 0;
  while (cub->map_file[i] && filled < NB_TEXTURES) {
    // printf("map file is : %s\n", cub->map_file[i]);
    if (ft_strncmp(cub->map_file[i], "\n", 1) != 0) {
      // printf("we fill block %d\n", filled);
      parser->textures[filled] = ft_split(cub->map_file[i], ' ');
      if (!good_texture_format(parser->allowed_ids, parser->textures[filled])) {
        free_and_exit(parser, cub);
      }
      filled++;
    }
    i++;
  }
  if (!check_if_all_textures(parser) ||
      !valid_paths_and_color_format(parser, cub))
    free_and_exit(parser, cub);
  // printf("all paths and colors are good WOW\n");
  while (cub->map_file[i] && ft_strncmp(cub->map_file[i], "\n", 1) == 0) {
    i++;
  }
  // printf("coucou, actual line is %s\n", cub->map_file[i]);
  j = 0;
  if (cub->map_file[i]) {
    get_map_size(cub, i);
    parser->map = malloc(sizeof(char *) * (cub->map_height + 1));
    if (!parser->map)
      free_and_exit(parser, cub);
    while (cub->map_file[i])
      parser->map[j++] = cub->map_file[i++];
    parser->map[j] = NULL;
  }
  // printf("Tout est dl\n");
}
