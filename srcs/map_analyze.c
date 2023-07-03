/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyze.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:55:28 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/03 19:58:25 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	wall_in_the_way(char **map, int i, int j)
{
	int	tmp;

	tmp = j;
	while (map[i][j] && map[i][j] != '1')
		j--;
	if (map[i][j] != '1')
		return (FALSE);
	j = tmp;
	while (map[i][j] && map[i][j] != '1')
		j++;
	if (map[i][j] != '1')
		return (FALSE);
	j = tmp;
	tmp = i;
	while (i >= 0 && map[i][j] != '1')
		i--;
	if (i < 0 || map[i][j] != '1')
		return (FALSE);
	i = tmp;
	while (map[i] && map[i][j] != '1')
		i++;
	if (!map[i] || map[i][j] != '1')
		return (FALSE);
	return (TRUE);
}

int	map_line_conformity(char *map_line)
{
	int	j;

	j = -1;
	while (map_line[++j])
	{
		if (map_line[j] != '0' && map_line[j] != '1' && map_line[j] != 'E'
			&& map_line[j] != 'W' && map_line[j] != 'S' && map_line[j] != 'N'
			&& map_line[j] != ' ' && map_line[j] != 'D')
			return (FALSE);
	}
	return (TRUE);
}

int	duplicate_player(char *map_line, t_parser *parser)
{
	int	j;

	j = -1;
	while (map_line[++j])
	{
		if (map_line[j] == 'E' || map_line[j] == 'W' || map_line[j] == 'S'
			|| map_line[j] == 'N')
		{
			parser->orient = map_line[j];
			parser->tmp_p++;
		}
	}
	if (parser->tmp_p > 1)
		return (FALSE);
	return (TRUE);
}

int	door_conformity(char **map, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				if (!map[i][j + 1] || !map[i][j - 1] || !map[i + 1][j]
					|| !map[i - 1][j])
					return (FALSE);
				cub->door_pos.x = j;
				cub->door_pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	map_analyze(t_parser *parser, t_cub *cub)
{
	int	i;

	i = -1;
	while (parser->map[++i])
	{
		if (ft_strncmp(parser->map[i], "\n", 2) == 0)
			return (FALSE);
		parser->map[i] = ft_strtrim(parser->map[i], "\n");
		if (!map_line_conformity(parser->map[i])
			|| !duplicate_player(parser->map[i], parser))
			return (FALSE);
	}
	if (parser->tmp_p != 1 || !door_conformity(parser->map, cub)
		|| !is_closing_map(parser->map, cub))
		return (FALSE);
	cub->p_orient = parser->orient;
	return (TRUE);
}
