#include "../headers/cub3d.h"

void initialize_cube(t_cub *cub) {
  cub->map_file = NULL;
  cub->map = NULL;
  cub->e_texture = NULL;
  cub->w_texture = NULL;
  cub->s_texture = NULL;
  cub->n_texture = NULL;
	cub->movespeed = 0.2;
	cub->rotspeed = 0.05;
}

void	squarejumper(t_cub *cub)
{
	if (cub->sidedist.x < cub->sidedist.y)
	{
		cub->sidedist.x += cub->deltadist.x;
		cub->mapc.x += cub->step.x;
		cub->side = 0;
	}
	else
	{
		cub->sidedist.y += cub->deltadist.y;
		cub->mapc.y += cub->step.y;
		cub->side = 1;
	}
	if (cub->map[cub->mapc.x][cub->mapc.y] > '0')
		cub->wall = 1;
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
	cub->map_width = 640;
	cub->map_height = 480;
	xpm_to_img(cub);
	mlxsetup(cub);
	cub->p.x += 0.1;
	cub->p.y += 0.1;
	getplayerdir(cub);
	putpixel(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->mlximg.img, 0, 0);
	mlx_loop_hook(cub->mlx, NULL, NULL);
	mlx_loop_hook(cub->mlx, *mouse_input, cub);
	mlx_hook(cub->mlxwin, 17, 1L<<17, destroy, cub); 
	mlx_hook(cub->mlxwin, 2, 1L<<0, inputs, cub); 
	mlx_loop(cub->mlx);
  free_cube(cub);
  return (0);
}
