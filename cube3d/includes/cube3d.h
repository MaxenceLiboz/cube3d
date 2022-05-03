/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:58:44 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/03 14:00:12 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <sys/time.h>

# define WHITE 0x00FFFFFF
# define DARK_GRAY 0xFF222222
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x00566573
# define BLUE 0x000000FF
# define PURPLE 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define PINK 0x00DD88BB
# define LIGHT_BLUE 0x00AAAAFF
# define TERM_END "\x1b[0m"
# define TERM_RED "\x1b[31m"
# define TERM_GREEN "\x1b[32m"
# define TERM_BLUE "\x1b[34m"
# define TERM_ERASE "\033[2K\r"
# define TERM_BCKG_END "\x1b[0m"
# define TERM_BCKG_RED "\x1b[41m"
# define TERM_BCKG_GREEN "\x1b[42m"
# define TERM_BCKG_YELLOW "\x1b[43m"
# define TERM_BCKG_BLUE "\x1b[44m"
# define TERM_BCKG_MAGENTA "\x1b[45m"
# define TERM_BCKG_CYAN "\x1b[46m"
# define TERM_BCKG_WHITE "\x1b[47m"

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}	t_win;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_texture {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		width;
	int		height;
}	t_texture;

typedef union u_color
{
	unsigned char	ustr_color[4];
	unsigned int	uint_color;
}	t_color;

/*
	1/2: x/y player postion
	3/4: x/y player direction
	5/6: x/y camera plane  
*/
typedef struct s_player
{
	double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
	double	move_speed;
	double	rotation_speed;
}	t_player;

/*
	1: x-coordinate of the camera plane
	2/3: x/y ray's direction
	4/5: x/y position on the map parsed
*/
typedef struct s_dda
{
	double	x_camera;
	double	x_ray_direction;
	double	y_ray_direction;
	int		x_map_pos;
	int		y_map_pos;
	int		x_step;
	int		y_step;
	int		side;
	double	x_side_ray_dist;
	double	y_side_ray_dist;
	double	x_side_delta_ray_dist;
	double	y_side_delta_ray_dist;
	double	wall_dist;
}	t_dda;

typedef struct s_draw
{
	int				line_height;
	int				draw_start_pixel;
	int				draw_end_pixel;
	int				texture_index;
	double			texture_step;
	double			texture_start_pos;
	int				texture_x_pos;
	int				texture_y_pos;
	double			wall_hit_pos;
	union u_color	color;
	int				sky_color;
	int				floor_color;
}	t_draw;

typedef struct s_parse
{
	int		height;
	int		width;
	int		pos_player;
	int		start; // Where the map is starting in the file
}	t_parse;

typedef struct s_edition
{
	int			mouse_pressed;
	int			mouse_button;
    t_point		mouse_position;
    int			mouse_keycode;
	double		offset_in;
	double		offset_out;
	int			cell_size;
	t_point		center;
}	t_edition;

typedef struct s_map
{
	t_point	end_point;
	int		cell_size;
	int		max_cell_width;
	int		max_cell_height;
	t_point	center;
	bool	big_map_height;
	bool	big_map_width;
}	t_map;

typedef struct s_prg
{
	struct s_win		win;
	struct s_point		point;
	struct s_data		img;
	struct s_texture	texture[4];
	struct s_player		player;
	struct s_dda		dda;
	struct s_draw		draw;
	t_parse				parser;
	t_list				*lst;
	int					**world_map;
	int					edition_mode;
	t_edition			edition;
	t_map				map;
	t_map				mini_map;
}	t_prg;

/***************** PARSING ***********************/
bool	window_init(t_win *window);
bool	img_init(t_win window, t_data *img);
bool	init_texture(t_win window, t_texture *texture, char *filename);
bool	initialization(t_prg *prg);

bool	parsing(t_prg *prg, char **argv, int argc);
bool	parse_file(char *argv, t_prg *prg);

bool	init_map(t_prg *prg);
bool	is_valid_map(t_prg *prg, int player_check);

/***************** PARSING UTILS ***********************/
int		position_player(char position, int x, int y, t_prg *prg);
int		is_valid_position(t_prg *prg, int x, int y);
void	fill_with_2(t_prg *prg, int y, int x);
void	free_world_map(int **world_map, int size);

bool	window_init(t_win *window);
bool	img_init(t_win window, t_data *img);
bool	is_color_num(char **str);
bool	check_texture_and_color_init(t_texture *texture, t_draw draw);
bool	is_texture(char *line);
bool	is_fc(char *line);
bool	init_texture(t_win window, t_texture *texture, char *filename);
void	init_map_variable(t_prg *prg);
void	init_map_variable2(t_prg *prg);

/***************** EDITION ***********************/
bool	run_window(t_prg *prg);
int		update(t_prg *prg, int keycode);
int		mouse_pressed(int keycode, int x, int y, t_prg *prg);
int		mouse_released(int keycode, int x, int y, t_prg *prg);
int		updated_mouse_pos(int x, int y, t_prg *prg);
void	set_grid_cell(t_prg *prg, int x, int y);
// void	print_grid(t_prg *prg);
void	clear_window(t_prg *prg);
void	draw_square_cell(t_prg *prg, t_point point1, t_point point2,  int color);
void 	draw_line(t_data *data, t_point p1, t_point p2, int color);
int		mouse_hook(int keycode, int x, int y, t_prg *prg);
void	is_valid_new_map(t_prg *prg);
void	draw_grid(t_prg *prg);
void	draw_new_map(t_prg *prg, int keycode);
void	draw_new_mini_map(t_prg *prg);

/***************** ERROR ***********************/
int		ft_error(char *str, int return_value);

/***************** DDA ***********************/
void	init_dda(t_player *player, t_win window, t_dda *dda, int x);
void	perform_dda(t_prg *prg, t_dda *dda, int **world_map);

/***************** DRAW ***********************/
void	init_draw(t_prg *prg, t_draw *draw);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	draw_background(int x, t_prg *prg);

/***************** RAYCASTING ***********************/
void	write_map(t_prg *prg, int **world_map);

/***************** HOOKS ***********************/
int		key_pressed(int keycode, t_prg *prg);
int		exit_cube(t_prg *prg);
void	up(t_prg *prg);
void	down(t_prg *prg);
void	left(t_prg *prg);
void	right(t_prg *prg);
void	left_rot(t_prg *prg);
void	right_rot(t_prg *prg);

int		refresh(t_prg *prg);

/***************** DRAW ***********************/
void	draw_img(t_prg *prg, int x);

/***************** UTILS ***********************/
void	free_2d_tab(char **tab);


#endif