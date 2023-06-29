/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:22:07 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/29 10:06:31 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	drawline(int i, t_cub *cub)
{
	int	y;

	getcolor(cub);
	y = 0;
	while (y < cub->drawstart)
		my_mlx_pixel_put(&cub->mlximg, i, y++, getrgb(cub->c_color[0], cub->c_color[1], cub->c_color[2]));
	y = cub->drawstart;
	while (y < cub->drawend)
	{
		my_mlx_pixel_put(&cub->mlximg, i, y, get_pixel_color(cub->e_data, i, y));
		y++;
	}
	while (y < cub->map_height)
		my_mlx_pixel_put(&cub->mlximg, i, y++, getrgb(cub->f_color[0], cub->f_color[1], cub->f_color[2]));
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
