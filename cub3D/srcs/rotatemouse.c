/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotatemouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:18:46 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 18:40:17 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	rotateright(t_cub *cub)
{
	float	olddirx;
	float	oldplanex;

	olddirx = cub->pdir.x;
	oldplanex = cub->plane.x;
	cub->pdir.x = cub->pdir.x * cos(-cub->rotspeed)
		- cub->pdir.y * sin(-cub->rotspeed);
	cub->pdir.y = olddirx * sin(-cub->rotspeed)
		+ cub->pdir.y * cos(-cub->rotspeed);
	cub->plane.x = cub->plane.x * cos(-cub->rotspeed) - cub->plane.y
		* sin(-cub->rotspeed);
	cub->plane.y = oldplanex * sin(-cub->rotspeed) + cub->plane.y
		* cos(-cub->rotspeed);
}

void	rotateleft(t_cub *cub)
{
	float	olddirx;
	float	oldplanex;

	olddirx = cub->pdir.x;
	oldplanex = cub->plane.x;
	cub->pdir.x = cub->pdir.x * cos(cub->rotspeed) - cub->pdir.y
		* sin(cub->rotspeed);
	cub->pdir.y = olddirx * sin(cub->rotspeed) + cub->pdir.y
		* cos(cub->rotspeed);
	cub->plane.x = cub->plane.x * cos(cub->rotspeed) - cub->plane.y
		* sin(cub->rotspeed);
	cub->plane.y = oldplanex * sin(cub->rotspeed) + cub->plane.y
		* cos(cub->rotspeed);
}

int	mouse_input(t_cub *cub)
{
	int	x;
	int	y;

	mlx_mouse_hide();
	mlx_mouse_get_pos(cub->mlxwin, &x, &y);
	if (x > cub->map_height / 2)
		rotateright(cub);
	else if (x < cub->map_height / 2)
		rotateleft(cub);
	mlx_mouse_move(cub->mlxwin, cub->map_height / 2, cub->map_width / 2);
	mlx_destroy_image(cub->mlx, cub->mlximg->img);
	cub->mlximg->img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg->addr = mlx_get_data_addr(cub->mlximg->img,
			&cub->mlximg->bits_per_pixel, &cub->mlximg->line_length,
			&cub->mlximg->endian);
	putpixel(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->mlximg->img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->minimap->img);
	put_minimap(cub);
	return (0);
}
