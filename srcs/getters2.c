/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:14:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/29 12:00:58 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
