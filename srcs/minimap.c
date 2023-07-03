/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:33:02 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/03 19:45:05 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	mini_walldraw(t_cub *cub, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(cub->minimap, *x, *y, create_trgb(0, 0, 0, 0));
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(cub->minimap, *x, *y,
				create_trgb(90, 225, 198, 153));
			*x += 1;
			j++;
		}
		*x -= 10;
		*y += 1;
		i++;
	}
}

void	put_player_minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	y = cub->p.x * 10;
	x = cub->p.y * 10;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(cub->minimap, x, y,
				create_trgb(90, 255, 0, 0));
			x++;
			j++;
		}
		x -= 5;
		y++;
		i++;
	}
}

void	draw_minimap(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(cub->map[i]))
		{
			if (cub->map[i][j] == '0')
				mini_floordraw(cub, &x, &y);
			else
				mini_walldraw(cub, &x, &y);
			y -= 10;
			x += 10;
			j++;
		}
		y += 10;
		x = 0;
		i++;
	}
}

void	put_minimap(t_cub *cub)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	cub->minimap->img = mlx_new_image(cub->mlx, cub->max_wid * 10,
			cub->max_hei * 10);
	cub->minimap->addr = mlx_get_data_addr(cub->minimap->img,
			&cub->minimap->bits_per_pixel, &cub->minimap->line_length,
			&cub->minimap->endian);
	draw_minimap(cub, x, y);
	put_player_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->minimap->img, 0, 0);
}
