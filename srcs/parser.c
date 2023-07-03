/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:40:44 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/03 19:10:21 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	initialize_parser(t_parser *parser)
{
	int	i;

	parser->textures = malloc(sizeof(char *) * (NB_TEXTURES + 1));
	if (!parser->textures)
		return ;
	i = -1;
	while (++i < (NB_TEXTURES + 1))
		parser->textures[i] = NULL;
	i = -1;
	while (++i < 3)
		parser->colors[i] = 0;
	parser->map = NULL;
	parser->allowed_ids[0] = "NO";
	parser->allowed_ids[1] = "SO";
	parser->allowed_ids[2] = "WE";
	parser->allowed_ids[3] = "EA";
	parser->allowed_ids[4] = "F";
	parser->allowed_ids[5] = "C";
	parser->map = NULL;
	parser->tmp_p = 0;
}

int	valid_paths_and_color_format(t_parser *parser, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (parser->textures[++i])
	{
		if (ft_strncmp("F", parser->textures[i][0], 2) == 0)
		{
			if (!cscf('f', cub, parser->colors, parser->textures[i]))
				return (FALSE);
		}
		else if (ft_strncmp("C", parser->textures[i][0], 2) == 0)
		{
			if (!cscf('c', cub, parser->colors, parser->textures[i]))
				return (FALSE);
		}
		else
		{
			if (!cspf(cub, j, parser->tex_paths, parser->textures[i]))
				return (FALSE);
		}
		j++;
	}
	return (TRUE);
}

int	get_map_size(t_cub *cub, int i)
{
	int	j;

	j = 0;
	cub->max_wid = 0;
	while (cub->map_file[i])
	{
		if ((int)ft_strlen(cub->map_file[i]) > cub->max_wid)
			cub->max_wid = (int)ft_strlen(cub->map_file[i]);
		i++;
		j++;
	}
	cub->map_height = j;
	cub->max_hei = j;
	return (j);
}

static void	norm_parser(t_parser *parser, t_cub *cub, int i)
{
	int	j;

	j = 0;
	if (cub->map_file[i])
	{
		get_map_size(cub, i);
		parser->map = malloc(sizeof(char *) * (cub->map_height + 1));
		if (!parser->map)
			free_and_exit(parser, cub);
		while (cub->map_file[i])
			parser->map[j++] = cub->map_file[i++];
		parser->map[j] = NULL;
	}
}

void	store_parser_data(t_parser *parser, t_cub *cub)
{
	int	i;
	int	filled;

	i = 0;
	filled = 0;
	while (cub->map_file[i] && filled < NB_TEXTURES)
	{
		if (ft_strncmp(cub->map_file[i], "\n", 1) != 0)
		{
			parser->textures[filled] = ft_split(cub->map_file[i], ' ');
			if (!good_texture_format(parser->allowed_ids,
					parser->textures[filled]))
				free_and_exit(parser, cub);
			filled++;
		}
		i++;
	}
	if (!check_if_all_textures(parser)
		|| !valid_paths_and_color_format(parser, cub))
		free_and_exit(parser, cub);
	while (cub->map_file[i] && ft_strncmp(cub->map_file[i], "\n", 1) == 0)
		i++;
	norm_parser(parser, cub, i);
}
