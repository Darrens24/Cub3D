/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:31:58 by pfaria-d          #+#    #+#             */
/*   Updated: 2023/06/28 17:03:57 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	xpm_to_img(t_cub *cub)
{
	cub->e_img = mlx_xpm_file_to_image(cub->mlx, cub->e_texture, 0, 0);
	cub->w_img = mlx_xpm_file_to_image(cub->mlx, cub->w_texture, 0, 0);
	cub->s_img = mlx_xpm_file_to_image(cub->mlx, cub->s_texture, 0, 0);
	cub->n_img = mlx_xpm_file_to_image(cub->mlx, cub->n_texture, 0, 0);
}
