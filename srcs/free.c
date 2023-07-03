#include "../headers/cub3d.h"

void free_array(char **array) {
  int i;

  if (!array)
	  return;
  i = 0;
  while (array[i])
    free(array[i++]);
  free(array);
}

void free_and_exit(t_parser *parser, t_cub *cub) {
  int i;

  free(parser->map);
  i = -1;
  while (parser->textures[++i])
    free_array(parser->textures[i]);
  free(cub->e_texture);
  free(cub->w_texture);
  free(cub->s_texture);
  free(cub->n_texture);
  free_array(cub->map_file);
  if (cub->map)
	  free_array(cub->map);
  free(parser);
  free(cub);
  printf("Error\nBad map format\n");
  exit(EXIT_SUCCESS);
}

void free_parser_memory(t_parser *parser) {
  int i;

  free_array(parser->map);
  i = -1;
  while (parser->textures[++i])
    free_array(parser->textures[i]);
  free(parser->textures);
  free(parser);
}

void free_cube(t_cub *cub) {
  free_array(cub->map);
  free(cub->e_texture);
  free(cub->w_texture);
  free(cub->s_texture);
  free(cub->n_texture);
  free(cub->e_data->img);
  free(cub->e_data->addr);
  free(cub->e_data);
  free(cub->w_data->img);
  free(cub->w_data->addr);
  free(cub->w_data);
  free(cub->n_data->img);
  free(cub->n_data->addr);
  free(cub->n_data);
  free(cub->s_data->img);
  free(cub->s_data->addr);
  free(cub->s_data);
  free(cub->mlximg->img);
  free(cub->mlximg->addr);
  free(cub->mlximg);
  free(cub->minimap->img);
  free(cub->minimap->addr);
  free(cub->minimap);
  free(cub->door0->img);
  free(cub->door0->addr);
  free(cub->door0);
  free(cub->door1->img);
  free(cub->door1->addr);
  free(cub->door1);
  free(cub->door2->img);
  free(cub->door2->addr);
  free(cub->door2);
  free(cub->door3->img);
  free(cub->door3->addr);
  free(cub->door3);
  free(cub);
  system("leaks cub3D");
}
