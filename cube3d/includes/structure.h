/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:17:10 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 16:20:00 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <libft.h>

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
	int		keyboard[6];
	double	delta;
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
	double	ray_table[1920];
	double	ray_dir_table[1920][2];
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
	int		start;
}	t_parse;

typedef struct s_mouse
{
	int		mouse_pressed;
	int		mouse_button;
	t_point	mouse_position;
	int		mouse_keycode;
}	t_mouse;

typedef struct s_edition_map
{
	t_point	end_point;
	int		cell_size;
	int		max_cell_width;
	int		max_cell_height;
	t_point	center;
	t_point	pt1;
	t_point	pt2;
	int		x_map;
	int		y_map;
}	t_edition_map;

typedef struct s_mini_map
{
	t_point	center;
	t_point	pt1;
	t_point	pt2;
	int		x_map;
	int		y_map;
}	t_mini_map;

typedef struct s_help_map
{
	int		max_size;
	bool	is_printable;
	bool	help_mode;
}	t_help_map;

typedef struct s_prg
{
	struct s_win		win;
	struct s_point		point;
	struct s_data		img;
	struct s_texture	texture[4];
	struct s_texture	help_keys[13];
	struct s_texture	background;
	struct s_player		player;
	struct s_dda		dda;
	struct s_draw		draw;
	t_parse				parser;
	t_list				*lst;
	int					**world_map;
	bool				edition_mode;
	t_mouse				mouse;
	t_edition_map		e_map;
	t_mini_map			m_map;
	t_help_map			h_map;
}	t_prg;

#endif