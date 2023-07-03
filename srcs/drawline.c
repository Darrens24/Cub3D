/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:22:07 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 19:50:39 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	printer(t_cub *cub, int i, int y, t_data *data)
{
	while (++y < cub->drawend)
	{
		cub->tex.y = (int)cub->texpos & (64 - 1);
		cub->texpos += cub->texstep;
		if (cub->door == 1)
			my_mlx_pixel_put(cub->mlximg, i, y,
				get_pixel_color(cub->current_door, cub->tex.x, cub->tex.y));
		else
			my_mlx_pixel_put(cub->mlximg, i, y,
				get_pixel_color(data, cub->tex.x, cub->tex.y));
	}
	return (y);
}

void	drawline(int i, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < cub->drawstart)
		my_mlx_pixel_put(cub->mlximg, i, y++,
			getrgb(cub->c_color[0], cub->c_color[1], cub->c_color[2]));
	y = cub->drawstart - 1;
	if (cub->side == 1 && cub->p.y < cub->mapc.y)
		y = printer(cub, i, y, cub->e_data);
	else if (cub->side == 1 && cub->p.y > cub->mapc.y)
		y = printer(cub, i, y, cub->w_data);
	else if (cub->side == 0 && cub->p.x < cub->mapc.x)
		y = printer(cub, i, y, cub->s_data);
	else 
		y = printer(cub, i, y, cub->n_data);
	while (y < cub->map_height)
		my_mlx_pixel_put(cub->mlximg, i, y++, getrgb(cub->f_color[0],
				cub->f_color[1], cub->f_color[2]));
}

void	putpixel(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map_width)
	{
		getcamerax(cub, i);
		getmapc(cub);
		getdeltadist(cub);
		cub->wall = 0;
		cub->door = 0;
		getstepdist(cub);
		while (cub->wall == 0)
			squarejumper(cub);
		getperpwalldist(cub);
		cub->lineheight = (int)(cub->map_height / cub->perpwalldist);
		getdraw(cub);
		drawline(i, cub);
		i++;
	}
}
