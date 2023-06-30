/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:20:29 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/30 10:22:19 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	destroy(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlxwin);
	mlx_destroy_window(cub->mlx, cub->mlxwin);
	exit(0);
}

int	inputs(int key, t_cub *cub)
{
	if (key == 13)
		moveup(cub);
	else if (key == 0)
		moveleft(cub);
	else if (key == 1)
		movedown(cub);
	else if (key == 2)
		moveright(cub);
	else if (key == 123)
		rotateleft(cub);
	else if (key == 124)
		rotateright(cub);
	else if (key == 53)
		destroy(cub);
	else if (key == 53)
		destroy(cub);
	mlx_destroy_image(cub->mlx, cub->mlximg.img);
	mlx_destroy_image(cub->mlx, cub->minimap->img);
	cub->mlximg.img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg.addr = mlx_get_data_addr(cub->mlximg.img, &cub->mlximg.bits_per_pixel, &cub->mlximg.line_length, &cub->mlximg.endian);
	putpixel(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->mlximg.img, 0, 0);
	put_minimap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->minimap->img, 0, 0);
	return (0);
}
