/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:31:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/04 11:05:25 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	get_pixel_color(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*pixel;

	x %= data->x;
	y %= data->y;
	pixel = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	door_to_img(t_cub *cub)
{
	cub->door0 = malloc(sizeof(t_data));
	cub->door1 = malloc(sizeof(t_data));
	cub->door2 = malloc(sizeof(t_data));
	cub->door3 = malloc(sizeof(t_data));
	cub->door0->img = mlx_xpm_file_to_image(cub->mlx,
			"./textures/Closedoor.xpm", &cub->door0->x, &cub->door0->y);
	cub->door0->addr = mlx_get_data_addr(cub->door0->img,
			&cub->door0->bits_per_pixel, &cub->door0->line_length,
			&cub->door0->endian);
	cub->door1->img = mlx_xpm_file_to_image(cub->mlx,
			"./textures/Semiopen1.xpm", &cub->door1->x, &cub->door1->y);
	cub->door1->addr = mlx_get_data_addr(cub->door1->img,
			&cub->door1->bits_per_pixel, &cub->door1->line_length,
			&cub->door1->endian);
	cub->door2->img = mlx_xpm_file_to_image(cub->mlx,
			"./textures/Semiopen2.xpm", &cub->door2->x, &cub->door2->y);
	cub->door2->addr = mlx_get_data_addr(cub->door2->img,
			&cub->door2->bits_per_pixel, &cub->door2->line_length,
			&cub->door2->endian);
	cub->door3->img = mlx_xpm_file_to_image(cub->mlx,
			"./textures/Opendoor.xpm", &cub->door3->x, &cub->door3->y);
	cub->door3->addr = mlx_get_data_addr(cub->door3->img,
			&cub->door3->bits_per_pixel, &cub->door3->line_length,
			&cub->door3->endian);
	cub->current_door = cub->door0;
}

static void	norm_xpm(t_cub *cub)
{
	cub->n_data->addr = mlx_get_data_addr(cub->n_data->img,
			&cub->n_data->bits_per_pixel, &cub->n_data->line_length,
			&cub->n_data->endian);
	cub->w_data->img = mlx_xpm_file_to_image(cub->mlx, cub->w_texture,
			&cub->w_data->x, &cub->w_data->y);
	if (cub->w_data->img == 0)
	{
		free_cube(cub);
		exit(printf("Error\nTexture error\n"));
	}
	cub->w_data->addr = mlx_get_data_addr(cub->w_data->img,
			&cub->w_data->bits_per_pixel, &cub->w_data->line_length,
			&cub->w_data->endian);
	cub->s_data->img = mlx_xpm_file_to_image(cub->mlx, cub->s_texture,
			&cub->s_data->x, &cub->s_data->y);
	if (cub->s_data->img == 0)
	{
		free_cube(cub);
		exit(printf("Error\nTexture error\n"));
	}
	cub->s_data->addr = mlx_get_data_addr(cub->s_data->img,
			&cub->s_data->bits_per_pixel, &cub->s_data->line_length,
			&cub->s_data->endian);
}

void	xpm_to_img(t_cub *cub)
{
	cub->e_data = malloc(sizeof(t_data));
	cub->w_data = malloc(sizeof(t_data));
	cub->s_data = malloc(sizeof(t_data));
	cub->n_data = malloc(sizeof(t_data));
	cub->e_data->img = mlx_xpm_file_to_image(cub->mlx, cub->e_texture,
			&cub->e_data->x, &cub->e_data->y);
	door_to_img(cub);
	if (cub->e_data->img == 0)
	{
		free_cube(cub);
		exit(printf("Error\nTexture error\n"));
	}
	cub->e_data->addr = mlx_get_data_addr(cub->e_data->img,
			&cub->e_data->bits_per_pixel, &cub->e_data->line_length,
			&cub->e_data->endian);
	cub->n_data->img = mlx_xpm_file_to_image(cub->mlx, cub->n_texture,
			&cub->n_data->x, &cub->n_data->y);
	if (cub->n_data->img == 0)
	{
		free_cube(cub);
		exit(printf("Error\nTexture error\n"));
	}
	norm_xpm(cub);
}

int	good_texture_format(char *allowed[6], char **splitted_texture)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (splitted_texture[1] == NULL || splitted_texture[2] != NULL)
		{
			return (FALSE);
		}
		if (ft_strncmp(splitted_texture[0], allowed[i],
				ft_strlen(splitted_texture[0])) == 0)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}
