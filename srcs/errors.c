/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:04:37 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/04 10:27:38 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	correct_file_extension(char *name)
{
	if (ft_strlen(name) < 5)
		return (FALSE);
	if (ft_strncmp(".cub", (name + ft_strlen(name) - 4), 5) != 0)
		return (FALSE);
	return (TRUE);
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

int	cscf(char mode, t_cub *cub, int colors[3], char **texture)
{
	int		i;
	int		j;
	char	**coma_splitted_color;
	char	*temp;
	int		coma;

	i = -1;
	temp = ft_strtrim(texture[1], "\n");
	coma = 0;
	while (temp[++i])
	{
		if (temp[i] == ',')
			coma++;
		if ((!ft_isdigit(temp[i]) && temp[i] != ',') || coma > 2)
			return (FALSE);
	}
	coma_splitted_color = ft_split(temp, ',');
	free(temp);
	if (!coma_splitted_color[1] || !coma_splitted_color[2]
		|| coma_splitted_color[3])
		return (free_array(coma_splitted_color), FALSE);
	j = -1;
	while (coma_splitted_color[++j])
	{
		if (ft_strlen(coma_splitted_color[j]) > 3)
			return (free_array(coma_splitted_color), FALSE);
		colors[j] = ft_atoi(coma_splitted_color[j]);
		if (colors[j] < 0 || colors[j] > 255)
			return (free_array(coma_splitted_color), FALSE);
		if (mode == 'c')
			cub->c_color[j] = colors[j];
		else if (mode == 'f')
			cub->f_color[j] = colors[j];
	}
	return (free_array(coma_splitted_color), TRUE);
}

int	checker(t_texchek check)
{
	if (check.ceil != 1 || check.floor != 1 || check.west != 1
		|| check.east != 1 || check.north != 1 || check.south != 1)
	{
		printf("Error\nMap needs [EAST][WEST][SOUTH][NORTH][FLOOR][CEIL]\n");
		return (TRUE);
	}
	return (FALSE);
}

int	check_if_all_textures(t_parser *parser)
{
	int			i;
	t_texchek	check;

	i = -1;
	while (parser->textures[++i])
	{
		if (ft_strncmp(parser->textures[i][0], "EA", 3) == 0)
			check.east = 1;
		else if (ft_strncmp(parser->textures[i][0], "NO", 3) == 0)
			check.north = 1;
		else if (ft_strncmp(parser->textures[i][0], "SO", 3) == 0)
			check.south = 1;
		else if (ft_strncmp(parser->textures[i][0], "WE", 3) == 0)
			check.west = 1;
		else if (ft_strncmp(parser->textures[i][0], "F", 1) == 0)
			check.floor = 1;
		else if (ft_strncmp(parser->textures[i][0], "C", 1) == 0)
			check.ceil = 1;
	}
	if (checker(check))
		return (FALSE);
	return (TRUE);
}
