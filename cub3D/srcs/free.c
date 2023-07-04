/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:36:22 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 18:38:55 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_array(char	**array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_and_exit(t_parser	*parser, t_cub	*cub)
{
	int	i;

	free(parser->map);
	i = -1;
	while (parser->textures[++i])
		free_array(parser->textures[i]);
	free(cub->e_texture);
	free(cub->w_texture);
	free(cub->s_texture);
	free(cub->n_texture);
	free_array(cub->map_file);
	if (cub->map)
		free_array(cub->map);
	free(parser);
	free(cub);
	printf("Error\nBad map format\n");
	exit(EXIT_SUCCESS);
}

void	free_parser_memory(t_parser	*parser)
{
	int	i;

	free_array(parser->map);
	i = -1;
	while (parser->textures[++i])
		free_array(parser->textures[i]);
	free(parser->textures);
	free(parser);
}

void	free_cube(t_cub	*cub)
{
	free_array(cub->map);
	free(cub->e_texture);
	free(cub->w_texture);
	free(cub->s_texture);
	free(cub->n_texture);
	mlx_destroy_image(cub->mlx, cub->mlximg);
}
