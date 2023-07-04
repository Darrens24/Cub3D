/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:14:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 19:44:35 by eleleux          ###   ########.fr       */
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
	if (cub->side == 0)
		cub->wallx = cub->p.y + cub->perpwalldist * cub->raydir.y;
	else
		cub->wallx = cub->p.x + cub->perpwalldist * cub->raydir.x;
	cub->wallx -= floor((cub->wallx));
	cub->tex.x = (int)(cub->wallx * (float)64);
	if (cub->side == 0 && cub->raydir.x > 0)
		cub->tex.x = 64 - cub->tex.x - 1;
	if (cub->side == 1 && cub->raydir.y < 0)
		cub->tex.x = 64 - cub->tex.x - 1;
	cub->texstep = 1.0 * 64 / cub->lineheight;
	cub->texpos = (cub->drawstart - cub->map_height / 2 \
			+ cub->lineheight / 2) * cub->texstep;
}

int	getrgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	playerdir(int x, int y, t_cub *cub)
{
	cub->pdir.x = x;
	cub->pdir.y = y;
}
