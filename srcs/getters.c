/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:11:56 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 14:13:12 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	getplayerdir(t_cub *cub)
{
	if (cub->p_orient == 'S')
	{
		playerdir(1, 0, cub);
		cub->plane.x = 0;
		cub->plane.y = -0.66;
	}
	if (cub->p_orient == 'N')
	{
		playerdir(-1, 0, cub);
		cub->plane.x = 0;
		cub->plane.y = 0.66;
	}
	if (cub->p_orient == 'E')
	{
		playerdir(0, 1, cub);
		cub->plane.x = 0.66;
		cub->plane.y = 0;
	}
	if (cub->p_orient == 'W')
	{
		playerdir(0, -1, cub);
		cub->plane.x = -0.66;
		cub->plane.y = 0;
	}
}

void	getmapc(t_cub *cub)
{
	cub->mapc.x = (int)cub->p.x;
	cub->mapc.y = (int)cub->p.y;
}

void	getdeltadist(t_cub *cub)
{
	if (cub->raydir.x == 0)
		cub->deltadist.x = 1e30;
	else
		cub->deltadist.x = fabs(1 / cub->raydir.x);
	if (cub->raydir.y == 0)
		cub->deltadist.y = 1e30;
	else
		cub->deltadist.y = fabs(1 / cub->raydir.y);
}

void	getstepdist(t_cub *cub)
{
	if (cub->raydir.x < 0)
	{
		cub->step.x = -1;
		cub->sidedist.x = (cub->p.x - cub->mapc.x) * cub->deltadist.x;
	}
	else
	{
		cub->step.x = 1;
		cub->sidedist.x = (cub->mapc.x + 1.0 - cub->p.x) * cub->deltadist.x;
	}
	if (cub->raydir.y < 0)
	{
		cub->step.y = -1;
		cub->sidedist.y = (cub->p.y - cub->mapc.y) * cub->deltadist.y;
	}
	else
	{
		cub->step.y = 1;
		cub->sidedist.y = (cub->mapc.y + 1.0 - cub->p.y) * cub->deltadist.y;
	}
}

void	getcamerax(t_cub *cub, int i)
{
	cub->camerax = 2 * i / (float)cub->map_width - 1;
	cub->raydir.x = cub->pdir.x + cub->plane.x * cub->camerax;
	cub->raydir.y = cub->pdir.y + cub->plane.y * cub->camerax;
}
