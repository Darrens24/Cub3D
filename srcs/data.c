/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:47:06 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 19:57:47 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:47:04 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/07/03 18:47:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	get_file_size(int fd, char *av1)
{
	char	*buffer;
	int		file_size;

	fd = open(av1, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCouldn't open file %s\n", av1), FALSE);
	buffer = ft_calloc(1, 1);
	file_size = 0;
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer)
			file_size++;
	}
	close(fd);
	return (file_size);
}

int	download_map(t_cub *cub, char *av1)
{
	int				fd;
	unsigned int	i;

	fd = 0;
	cub->nb_of_file_lines = get_file_size(fd, av1);
	if (!cub->nb_of_file_lines)
		return (FALSE);
	cub->map_file = malloc(sizeof(char *) * (cub->nb_of_file_lines + 1));
	if (!cub->map_file)
		return (printf("Error\nMalloc error\n"), FALSE);
	fd = open(av1, O_RDONLY);
	if (fd < 0)
		return (printf("Error\nCouldn't open file %s\n", av1), FALSE);
	i = -1;
	while (++i < cub->nb_of_file_lines)
		cub->map_file[i] = get_next_line(fd);
	cub->map_file[i] = NULL;
	return (TRUE);
}

int	is_closing_map(char **map, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'W' || map[i][j] == 'N'
					|| map[i][j] == 'S')
			{
				cub->p.x = i;
				cub->p.y = j;
				map[i][j] = '0';
			}
			if (map[i][j] == '0')
				if (!wall_in_the_way(map, i, j))
					return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
