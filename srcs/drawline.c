/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:22:07 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 14:58:57 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	drawline(int i, t_cub *cub)
{
	int	y;

	getcolor(cub);
	y = cub->drawstart;
	while (y < cub->drawend)
		my_mlx_pixel_put(&cub->mlximg, i, y++, cub->color);
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
