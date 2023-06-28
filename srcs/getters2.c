/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:14:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 14:30:09 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	getcolor(t_cub *cub)
{
	//changer rgb et mettre rgb donnees
	if (cub->map[cub->mapc.x][cub->mapc.y] == '1')
		cub->color = getrgb(255, 0, 0);
	else if (cub->map[cub->mapc.x][cub->mapc.y] == '2')
		cub->color = getrgb(0, 255, 0);
	else if (cub->map[cub->mapc.x][cub->mapc.y] == '3')
		cub->color = getrgb(0, 0, 255);
	else if (cub->map[cub->mapc.x][cub->mapc.y] == '4')
		cub->color = getrgb(255, 255, 255);
	else
		cub->color = getrgb(100, 100, 100);
	if (cub->side == 1)
		cub->color = cub->color / 2;
}

void	getperpwalldist(t_cub *cub)
{
	if (cub->side == 0)
		cub->perpwalldist = cub->sidedist.x - cub->deltadist.x;
	else
		cub->perpwalldist = cub->sidedist.y - cub->deltadist.y;
}

void	getdraw(t_cub *cub)
{
	cub->drawstart = -cub->lineheight / 2 + cub->map_height / 2;
	if (cub->drawstart < 0)
		cub->drawstart = 0;
	cub->drawend = cub->lineheight / 2 + cub->map_height / 2;
	if (cub->drawend >= cub->map_height)
		cub->drawend = cub->map_height - 1;
}

int	getrgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	playerdir(int x, int y, t_cub *cub)
{
	cub->pdir.x = x;
	cub->pdir.y = y;
}
