/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:22:07 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 16:03:27 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	drawline(int i, t_cub *cub)
{
	int	y;

	y = 0;
	while (y < cub->drawstart)
		my_mlx_pixel_put(cub->mlximg, i, y++, getrgb(cub->c_color[0], cub->c_color[1], cub->c_color[2]));
	y = cub->drawstart - 1;
	if (cub->side == 1 && cub->p.y < cub->mapc.y)
		while (++y < cub->drawend)
		{
			cub->tex.y = (int)cub->texpos & (64 - 1);
			cub->texpos += cub->texstep;
			if (cub->door == 1)
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->current_door, cub->tex.x, cub->tex.y));
			else
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->e_data, cub->tex.x, cub->tex.y));
		}
	else if (cub->side == 1 && cub->p.y > cub->mapc.y)
		while (++y < cub->drawend)
		{
			cub->tex.y = (int)cub->texpos & (64 - 1);
			cub->texpos += cub->texstep;
			if (cub->door == 1)
			{
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->current_door, cub->tex.x, cub->tex.y));
			}
			else
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->w_data, cub->tex.x, cub->tex.y));
		}
	else if (cub->side == 0 && cub->p.x < cub->mapc.x)
		while (++y < cub->drawend)
		{
			cub->tex.y = (int)cub->texpos & (64 - 1);
			cub->texpos += cub->texstep;
			if (cub->door == 1)
			{
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->current_door, cub->tex.x, cub->tex.y));
			}
			else
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->s_data, cub->tex.x, cub->tex.y));
		}
	else 
		while (++y < cub->drawend)
		{
			cub->tex.y = (int)cub->texpos & (64 - 1);
			cub->texpos += cub->texstep;
			if (cub->door == 1)
			{
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->current_door, cub->tex.x, cub->tex.y));
			}
			else
				my_mlx_pixel_put(cub->mlximg, i, y, get_pixel_color(cub->n_data, cub->tex.x, cub->tex.y));
		}
	while (y < cub->map_height)
		my_mlx_pixel_put(cub->mlximg, i, y++, getrgb(cub->f_color[0], cub->f_color[1], cub->f_color[2]));
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
	/* put_minimap(cub); */
}

/* void	putanimation(t_cub *cub) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	while (i < cub->map_width) */
/* 	{ */
/* 		getcamerax(cub, i); */
/* 		getmapc(cub); */
/* 		getdeltadist(cub); */
/* 		cub->wall = 0; */
/* 		cub->door = 0; */
/* 		getstepdist(cub); */
/* 		while (cub->wall == 0) */
/* 			squarejumper(cub); */
/* 		getperpwalldist(cub); */
/* 		cub->lineheight = (int)(cub->map_height / cub->perpwalldist); */
/* 		getdraw(cub); */
/* 		drawline(i, cub); */
/* 		i++; */
/* 	} */
/* } */
/* int	update_frame(void *param) */
/* { */
/* 	t_image		*map; */
/* 	static int	frame; */

/* 	map = (t_image *)param; */
/* 	frame++; */
/* 	if (frame < ANIM_FRAME) */
/* 		map->spr_pos.y += 1; */
/* 	if (frame == ANIM_FRAME) */
/* 	{ */
/* 		map->spr_pos.y = 0; */
/* 		frame = 0; */
/* 	} */
/* 	put_game(map); */
/* 	return (0); */
/* } */


