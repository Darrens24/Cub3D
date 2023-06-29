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
	*x += 10;
	while (i < 10)
	{
		j = 0;
		*x -= 10;
		while (j < 10)
		{
			printf("mini %p\n x %d\n y%d\ncolor%d\n", cub->minimap, *x, *y, create_trgb(50, 88, 41, 0));
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(50, 88, 41, 0));
			*x += 1;
			j++;
		}
		*y += 1;
		i++;
	}
}

/* void	mini_floordraw(t_cub *cub, int *x, int *y) */
/* { */
/* 	(void) cub, x, y; */

/* 	return; */
/* } */

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
	x = 0;
	y = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				mini_walldraw(cub, &x, &y);
			/* else */
			/* 	mini_floordraw(cub, &y); */
			j++;
		}
		i++;
	}
	printf("COUCOU\n");
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->minimap->img, 0, 0);
}
