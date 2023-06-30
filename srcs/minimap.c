#include "../headers/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	mini_walldraw(t_cub *cub, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			/* printf("mini %p\n x %d\n y%d\ncolor%d\n", cub->minimap, *x, *y, create_trgb(50, 88, 41, 0)); */
<<<<<<< HEAD
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(0, 88, 41, 0));
=======
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(90, 88, 41, 0));
>>>>>>> main
			*x += 1;
			j++;
		}
		*x -= 10;
		*y += 1;
		i++;
	}
}

void	mini_floordraw(t_cub *cub, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			/* printf("mini %p\n x %d\n y%d\ncolor%d\n", cub->minimap, *x, *y, create_trgb(50, 88, 41, 0)); */
<<<<<<< HEAD
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(0, 225, 198, 153));
=======
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(90, 225, 198, 153));
>>>>>>> main
			*x += 1;
			j++;
		}
		*x -= 10;
		*y += 1;
		i++;
	}
}

void	mini_voiddraw(t_cub *cub, int *x, int *y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			/* printf("mini %p\n x %d\n y%d\ncolor%d\n", cub->minimap, *x, *y, create_trgb(50, 88, 41, 0)); */
<<<<<<< HEAD
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(0, 0, 0, 0));
=======
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(90, 0, 0, 0));
>>>>>>> main
			*x += 1;
			j++;
		}
		*x -= 10;
		*y += 1;
		i++;
	}
}

/* void	mini_floordraw(t_cub *cub, int *x, int *y) */
/* { */
/* 	(void) cub, x, y; */

/* 	return; */
/* } */

void	put_player_minimap(t_cub *cub)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	y = cub->p.x * 10 + 1;
	x = cub->p.y * 10 + 1;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			/* printf("mini %p\n x %d\n y%d\ncolor%d\n", cub->minimap, *x, *y, create_trgb(50, 88, 41, 0)); */
<<<<<<< HEAD
			my_mlx_pixel_put(cub->minimap, x, y, create_trgb(0, 255, 0, 0));
=======
			my_mlx_pixel_put(cub->minimap, x, y, create_trgb(90, 255, 0, 0));
>>>>>>> main
			x++;
			j++;
		}
		x -= 5;
		y++;
		i++;
	}
}

void	put_minimap(t_cub *cub)
{
	int	i;
	int	j;
	int x;
	int y;

	cub->minimap = malloc(sizeof(t_data));
	cub->minimap->img = mlx_new_image(cub->mlx, cub->max_wid * 10, cub->max_hei * 10);
	cub->minimap->addr = mlx_get_data_addr(cub->minimap->img, &cub->minimap->bits_per_pixel, &cub->minimap->line_length, &cub->minimap->endian);
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				mini_walldraw(cub, &x, &y);
			else if (cub->map[i][j] == '0')
				mini_floordraw(cub, &x, &y);
			else
				mini_voiddraw(cub, &x, &y);

			y -= 10;
			x += 10;
			/* printf("x after draw is %d\ny after draw is %d\n", x, y); */
			j++;
		}
		y += 10;
		x = 0;
		i++;
	}
	put_player_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->minimap->img, 0, 0);
}
