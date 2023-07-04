/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleleux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:39:55 by eleleux           #+#    #+#             */
/*   Updated: 2023/07/04 10:52:18 by eleleux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define TRUE 1
# define FALSE 0
# define NB_TEXTURES 6

# include "../Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdint.h>

/***\ structures \***/

typedef struct s_point {
	float				x;
	float				y;
}	t_point;

typedef struct s_parser {
	char				***textures;
	int					colors[3];
	char				*tex_paths[4];
	char				**map;
	char				*allowed_ids[6];
	int					tmp_p;
	char				orient;
}	t_parser;

typedef struct s_textures_check {
	int					east;
	int					west;
	int					north;
	int					south;
	int					floor;
	int					ceil;
}	t_texchek;

typedef struct s_pointi {
	int					x;
	int					y;
}	t_pointi;

typedef struct s_data {
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					x;
	int					y;
}				t_data;

typedef struct s_cub {
	char				**map_file;
	char				**map;
	char				*e_texture;
	char				*w_texture;
	char				*s_texture;
	char				*n_texture;
	t_data				*e_data;
	t_data				*w_data;
	t_data				*s_data;
	t_data				*n_data;
	int					c_color[3];
	int					f_color[3];
	unsigned int		nb_of_file_lines;
	char				p_orient;
	struct s_point		p;
	int					map_width;
	int					map_height;
	struct s_point		pdir;
	struct s_point		plane;
	struct s_point		raydir;
	float				camerax;
	struct s_pointi		mapc;
	struct s_point		deltadist;
	float				perpwalldist;
	struct s_point		sidedist;
	struct s_point		step;
	int					wall;
	char				side;
	void				*mlx;
	void				*mlxwin;
	t_data				*mlximg;
	int					lineheight;
	int					drawstart;
	int					drawend;
	float				movespeed;
	float				rotspeed;
	struct s_pointi		tex;
	float				texpos;
	float				texstep;
	float				wallx;
	int					x;
	int					y;
	t_data				*minimap;
	int					max_wid;
	int					max_hei;
	t_data				*current_door;
	t_data				*door0;
	t_data				*door1;
	t_data				*door2;
	t_data				*door3;
	int					door;
	struct s_point		door_pos;
	int					done;
	int					valid;
}	t_cub;

/***\ errors \***/

int		correct_file_extension(char *name);
int		good_texture_format(char *allowed[6], char **splitted_texture);
int		valid_paths_and_color_format(t_parser *parser, t_cub *cub);
int		check_if_all_textures(t_parser *parser);

/***\ data \***/

int		get_file_size(int fd, char *av1);
void	print_map(char **map);
int		download_map(t_cub *cub, char *av1);

/***\ free \***/

void	free_array(char **array);
void	free_and_exit(t_parser *parser, t_cub *cub);
void	free_parser_memory(t_parser *parser);
void	free_cube(t_cub *cub);

/***\ parser \***/

int		parse_map_format(t_cub *cub);
void	initialize_parser(t_parser *parser);
void	store_parser_data(t_parser *parser, t_cub *cub);
int		cscf(char mode, t_cub *cub, int colors[3], char **texture);
int		cspf(t_cub *cub, int j, char *paths[4], char **texture);

/***\ map analyze \***/

int		map_analyze(t_parser *parser, t_cub *cub);
int		wall_in_the_way(char **map, int i, int j);
int		is_closing_map(char **map, t_cub *cub);
int		map_line_conformity(char *map_line);
int		duplicate_player(char *map_line, t_parser *parser);

/***\ getters \***/

void	getcamerax(t_cub *cub, int i);
void	getstepdist(t_cub *cub);
void	getdeltadist(t_cub *cub);
void	getmapc(t_cub *cub);
void	getplayerdir(t_cub *cub);

/***\ getters2 \***/

void	getcolor(t_cub *cub);
void	getperpwalldist(t_cub *cub);
void	getdraw(t_cub *cub);
int		getrgb(int r, int g, int b);
void	playerdir(int x, int y, t_cub *cub);

/***\ movements \***/

void	mlxsetup(t_cub *cub);
void	moveright(t_cub *cub);
void	moveleft(t_cub *cub);
void	movedown(t_cub *cub);
void	moveup(t_cub *cub);

/***\ rotate mouse \***/

void	rotateright(t_cub *cub);
void	rotateleft(t_cub *cub);
int		mouse_input(t_cub *cub);

/***\ inputs \***/

int		inputs(int key, t_cub *cub);
int		destroy(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/***\ drawline \***/

void	drawline(int i, t_cub *cub);
void	putpixel(t_cub *cub);

/***\ texture \***/

void	xpm_to_img(t_cub *cub);
int		get_pixel_color(t_data *data, int x, int y);
int		create_trgb(int t, int r, int g, int b);

/***\ utils \***/

void	squarejumper(t_cub *cub);
void	put_minimap(t_cub *cub);
float	absolute(float diff);
void	refresh_images(t_cub *cub);

/***\ door \***/

int		update_frame_open(t_cub *cub);
int		update_frame_close(t_cub *cub);
void	clozdoor(t_cub *cub);
void	hodoor(t_cub *cub);

#endif
