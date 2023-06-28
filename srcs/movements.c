/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:17:49 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 14:56:25 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	moveup(t_cub *cub)
{
	if (cub->map[(int)(cub->p.x + cub->pdir.x * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x += cub->pdir.x * cub->movespeed; 
	if (cub->map[(int)cub->p.x][(int)(cub->p.y + cub->pdir.y * (cub->movespeed + 0.1))] == '0')
		cub->p.y += cub->pdir.y * cub->movespeed; 
}

void	movedown(t_cub *cub)
{
	if (cub->map[(int)(cub->p.x - cub->pdir.x * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x -= cub->pdir.x * cub->movespeed; 
	if (cub->map[(int)cub->p.x][(int)(cub->p.y - cub->pdir.y * (cub->movespeed + 0.1))] == '0')
		cub->p.y -= cub->pdir.y * cub->movespeed; 
}

void	moveleft(t_cub *cub)
{
	if (cub->map[(int)cub->p.x][(int)(cub->p.y + cub->pdir.x * (cub->movespeed + 0.1))] == '0')
		cub->p.y += cub->pdir.x * cub->movespeed; 
	if (cub->map[(int)(cub->p.x - cub->pdir.y * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x -= cub->pdir.y * cub->movespeed; 
}

void	moveright(t_cub *cub)
{
	if (cub->map[(int)cub->p.x][(int)(cub->p.y - cub->pdir.x * (cub->movespeed + 0.1))] == '0')
		cub->p.y -= cub->pdir.x * cub->movespeed; 
	if (cub->map[(int)(cub->p.x + cub->pdir.y * (cub->movespeed + 0.1))][(int)cub->p.y] == '0')
		cub->p.x += cub->pdir.y * cub->movespeed; 
}

void	mlxsetup(t_cub *cub)
{
	cub->mlx = mlx_init();
	printf("%d %d\n", cub->map_width, cub->map_height);
	cub->mlxwin = mlx_new_window(cub->mlx, cub->map_width, cub->map_height, "CUB3D");
	cub->mlximg.img = mlx_new_image(cub->mlx, cub->map_width, cub->map_height);
	cub->mlximg.addr = mlx_get_data_addr(cub->mlximg.img, &cub->mlximg.bits_per_pixel, &cub->mlximg.line_length, &cub->mlximg.endian);
}
