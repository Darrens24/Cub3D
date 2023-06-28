/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:42:52 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 13:43:50 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include <mlx.h>

char	map[24][24] = {{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','2','2','2','2','2','0','0','0','0','3','0','3','0','3','0','0','0','1'},
		{'1','0','0','0','0','0','2','0','0','0','2','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','2','0','0','0','2','0','0','0','0','3','0','0','0','3','0','0','0','1'},
		{'1','0','0','0','0','0','2','0','0','0','2','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','2','2','0','2','2','0','0','0','0','3','0','3','0','3','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','4','4','4','4','4','4','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','0','4','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','0','0','0','0','5','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','0','4','0','0','0','0','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','0','4','4','4','4','4','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','4','4','4','4','4','4','4','4','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
		{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};

void	playerdir(int x, int y, t_cub *cub)
{
	cub->pdir.x = x;
	cub->pdir.y = y;
}

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

void	squarejumper(t_cub *cub)
{
	if (cub->sidedist.x < cub->sidedist.y)
	{
		cub->sidedist.x += cub->deltadist.x;
		cub->mapc.x += cub->step.x;
		cub->side = 0;
	}
	else
	{
		cub->sidedist.y += cub->deltadist.y;
		cub->mapc.y += cub->step.y;
		cub->side = 1;
	}
	//changer map par cub->map
	if (map[cub->mapc.x][cub->mapc.y] > '0')
		cub->wall = 1;
}

void	getcamerax(t_cub *cub, int i)
{
	cub->camerax = 2 * i / (float)cub->map_width - 1;
	cub->raydir.x = cub->pdir.x + cub->plane.x * cub->camerax;
	cub->raydir.y = cub->pdir.y + cub->plane.y * cub->camerax;
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	getcolor(t_cub *cub)
{
	//changer map et mettre cub->map
	//changer rgb et mettre rgb donnees
	if (map[cub->mapc.x][cub->mapc.y] == '1')
		cub->color = getrgb(255, 0, 0);
	else if (map[cub->mapc.x][cub->mapc.y] == '2')
		cub->color = getrgb(0, 255, 0);
	else if (map[cub->mapc.x][cub->mapc.y] == '3')
		cub->color = getrgb(0, 0, 255);
	else if (map[cub->mapc.x][cub->mapc.y] == '4')
		cub->color = getrgb(255, 255, 255);
	else
		cub->color = getrgb(100, 100, 100);
	if (cub->side == 1)
		cub->color = cub->color / 2;
}

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
		while (!cub->wall)
			squarejumper(cub);
		getperpwalldist(cub);
		cub->lineheight = (int)(cub->map_height / cub->perpwalldist);
		getdraw(cub);
		drawline(i, cub);
		i++;
	}
}

void	mlxsetup(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlxwin = mlx_new_window(cub->mlx, cub->map_width, cub->map_height, "CUB3D");
	cub->mlximg.img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg.addr = mlx_get_data_addr(cub->mlximg.img, &cub->mlximg.bits_per_pixel, &cub->mlximg.line_length, &cub->mlximg.endian);
}

void	moveup(t_cub *cub)
{
	//changer map par cub->map
	if (map[(int)(cub->p.x + cub->pdir.x * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x += cub->pdir.x * cub->movespeed; 
	if (map[(int)cub->p.x][(int)(cub->p.y + cub->pdir.y * (cub->movespeed + 0.1))] == '0')
		cub->p.y += cub->pdir.y * cub->movespeed; 
}

void	movedown(t_cub *cub)
{
	//changer map par cub->map
	if (map[(int)(cub->p.x - cub->pdir.x * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x -= cub->pdir.x * cub->movespeed; 
	if (map[(int)cub->p.x][(int)(cub->p.y - cub->pdir.y * (cub->movespeed + 0.1))] == '0')
		cub->p.y -= cub->pdir.y * cub->movespeed; 
}

void	moveleft(t_cub *cub)
{
	//changer map par cub->map
	if (map[(int)cub->p.x][(int)(cub->p.y + cub->pdir.x * (cub->movespeed + 0.1))] == '0')
		cub->p.y += cub->pdir.x * cub->movespeed; 
	if (map[(int)(cub->p.x - cub->pdir.y * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x -= cub->pdir.y * cub->movespeed; 
}

void	moveright(t_cub *cub)
{
	//changer map par cub->map
	if (map[(int)cub->p.x][(int)(cub->p.y - cub->pdir.x * (cub->movespeed + 0.1))] == '0')
		cub->p.y -= cub->pdir.x * cub->movespeed; 
	if (map[(int)(cub->p.x + cub->pdir.y * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x += cub->pdir.y * cub->movespeed; 
}

void	rotateright(t_cub *cub)
{
	float	olddirx;
	float	oldplanex;

	olddirx = cub->pdir.x;
	oldplanex = cub->plane.x;
	cub->pdir.x = cub->pdir.x * cos(-cub->rotspeed) - cub->pdir.y * sin(-cub->rotspeed);
	cub->pdir.y = olddirx * sin(-cub->rotspeed) + cub->pdir.y * cos(-cub->rotspeed);
	cub->plane.x = cub->plane.x * cos(-cub->rotspeed) - cub->plane.y * sin(-cub->rotspeed);
	cub->plane.y = oldplanex * sin(-cub->rotspeed) + cub->plane.y * cos(-cub->rotspeed);
}

void	rotateleft(t_cub *cub)
{
	float	olddirx;
	float	oldplanex;

	olddirx = cub->pdir.x;
	oldplanex = cub->plane.x;
	cub->pdir.x = cub->pdir.x * cos(cub->rotspeed) - cub->pdir.y * sin(cub->rotspeed);
	cub->pdir.y = olddirx * sin(cub->rotspeed) + cub->pdir.y * cos(cub->rotspeed);
	cub->plane.x = cub->plane.x * cos(cub->rotspeed) - cub->plane.y * sin(cub->rotspeed);
	cub->plane.y = oldplanex * sin(cub->rotspeed) + cub->plane.y * cos(cub->rotspeed);
}

int	destroy(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlxwin);
	mlx_destroy_window(cub->mlx, cub->mlxwin);
	exit(0);
}

int	inputs(int key, t_cub *cub)
{
	if (key == 13)
		moveup(cub);
	else if (key == 0)
		moveleft(cub);
	else if (key == 1)
		movedown(cub);
	else if (key == 2)
		moveright(cub);
	else if (key == 123)
		rotateleft(cub);
	else if (key == 124)
		rotateright(cub);
	else if (key == 53)
		destroy(cub);
	else if (key == 53)
		destroy(cub);
	mlx_destroy_image(cub->mlx, cub->mlximg.img);
	cub->mlximg.img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg.addr = mlx_get_data_addr(cub->mlximg.img, &cub->mlximg.bits_per_pixel, &cub->mlximg.line_length, &cub->mlximg.endian);
	putpixel(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->mlximg.img, 0, 0);
	return (0);
}

int	tmp(t_cub *cub)
{
	(void)cub;
	return (0);
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
	mlx_mouse_move(cub->mlxwin, cub->map_height / 2, cub->map_width /2);
	mlx_destroy_image(cub->mlx, cub->mlximg.img);
	cub->mlximg.img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg.addr = mlx_get_data_addr(cub->mlximg.img, &cub->mlximg.bits_per_pixel, &cub->mlximg.line_length, &cub->mlximg.endian);
	putpixel(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlxwin, cub->mlximg.img, 0, 0);
	return (0);
}

int	main(void)
{
	t_cub cub;
	double time = 0;
	double oldTile = 0;

	cub.p.x = 22.1;
	cub.p.y = 12.1;
	cub.map_width = 640;
	cub.map_height = 480;
	cub.movespeed = 0.2;
	cub.rotspeed = 0.05;
	cub.p_orient = 'N';
	mlxsetup(&cub);
	getplayerdir(&cub);
	putpixel(&cub);
	mlx_put_image_to_window(cub.mlx, cub.mlxwin, cub.mlximg.img, 0, 0);
	mlx_loop_hook(cub.mlx, *tmp, &cub);
	mlx_loop_hook(cub.mlx, *mouse_input, &cub);
	mlx_hook(cub.mlxwin, 17, 1L<<17, destroy, &cub); 
	mlx_hook(cub.mlxwin, 2, 1L<<0, inputs, &cub); 
	mlx_loop(cub.mlx);
}
