/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:31:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/29 10:06:55 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		get_pixel_color(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*pixel;

	x %= data->x;
	y %= data->y;
	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	xpm_to_img(t_cub *cub)
{
	cub->e_data = malloc(sizeof(t_data));
	cub->e_data->img = mlx_xpm_file_to_image(cub->mlx, cub->e_texture, &cub->e_data->x, &cub->e_data->y);
	cub->e_data->addr = mlx_get_data_addr(cub->e_data->img, &cub->e_data->bits_per_pixel, &cub->e_data->line_length, &cub->e_data->endian);
	/* cub->w_img = mlx_xpm_file_to_image(cub->mlx, cub->w_texture, 0, 0); */
	/* cub->s_img = mlx_xpm_file_to_image(cub->mlx, cub->s_texture, 0, 0); */
	/* cub->n_img = mlx_xpm_file_to_image(cub->mlx, cub->n_texture, 0, 0); */
}
