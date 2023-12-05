/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:33:12 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/04 10:38:32 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	update_frame_open(t_cub *cub)
{
	static int	frame;

	frame++;
	if (frame < 12)
		cub->current_door = cub->door1;
	else if (frame < 24)
		cub->current_door = cub->door2;
	else if (frame < 36)
	{
		cub->current_door = cub->door3;
		cub->map[(int)cub->door_pos.y][(int)cub->door_pos.x] = '0';
		cub->current_door = cub->door3;
		refresh_images(cub);
		frame = 0;
		cub->done = 1;
	}
	refresh_images(cub);
	return (0);
}

int	update_frame_close(t_cub *cub)
{
	static int	frame;

	frame++;
	if (frame < 12 && cub->done == 0)
		cub->current_door = cub->door3;
	else if (frame < 24 && cub->done == 0)
		cub->current_door = cub->door2;
	else if (frame < 36 && cub->done == 0)
	{
		cub->current_door = cub->door1;
		refresh_images(cub);
		cub->current_door = cub->door0;
		cub->map[(int)cub->door_pos.y][(int)cub->door_pos.x] = 'D';
	}
	else
	{
		frame = 0;
		cub->done = 1;
	}
	refresh_images(cub);
	return (0);
}

void	clozdoor(t_cub *cub)
{
	if (absolute(cub->door_pos.x - cub->p.y) > 3
		|| absolute(cub->door_pos.y - cub->p.x) > 2)
		return ;
	cub->done = 0;
	if (cub->done == 0
		&& cub->map[(int)cub->door_pos.y][(int)cub->door_pos.x] == '0')
	{
		mlx_loop_hook(cub->mlx, *update_frame_close, cub);
	}
}

void	hodoor(t_cub *cub)
{
	if (absolute(cub->door_pos.x - cub->p.y) > 3
		|| absolute(cub->door_pos.y - cub->p.x) > 2)
		return ;
	cub->done = 0;
	if (cub->done == 0
		&& cub->map[(int)cub->door_pos.y][(int)cub->door_pos.x] == 'D')
	{
		mlx_loop_hook(cub->mlx, *update_frame_open, cub);
	}
}
