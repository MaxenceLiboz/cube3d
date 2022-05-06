/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 07:58:44 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 15:50:20 by tarchimb         ###   ########.fr       */
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
# include <alias.h>
# include "draw.h"
# include "hooks.h"
# include "init.h"
# include "maps.h"
# include "parsing.h"
# include "raycasting.h"
# include "utils.h"
# include "structure.h"
# include "help.h"



// /***************** PARSING ***********************/
// bool	window_init(t_win *window);
// bool	img_init(t_win window, t_data *img);
// bool	init_texture(t_win window, t_texture *texture, char *filename);
// bool	initialization(t_prg *prg);

// bool	parsing(t_prg *prg, char **argv, int argc);
// bool	parse_file(char *argv, t_prg *prg);

// bool	init_map(t_prg *prg);
// bool	is_valid_map(t_prg *prg, int player_check);

// /***************** PARSING UTILS ***********************/
// int		position_player(char position, int x, int y, t_prg *prg);
// int		is_valid_position(t_prg *prg, int x, int y);
// void	free_world_map(int **world_map, int size);

// bool	window_init(t_win *window);
// bool	img_init(t_win window, t_data *img);
// bool	is_color_num(char **str);
// bool	check_texture_and_color_init(t_texture *texture, t_draw draw);
// bool	is_texture(char *line);
// bool	is_background(char *line);
// bool	init_texture(t_win window, t_texture *texture, char *filename);
// void	init_edition_map_var(t_prg *prg);
// void	init_edition_map_var2(t_prg *prg);
// void	init_hooks(t_prg *prg);

// /***************** EDITION ***********************/
// bool	run_window(t_prg *prg);
// int		update(t_prg *prg, int keycode);
// void	set_grid_cell(t_prg *prg, int x, int y);

// // void	print_grid(t_prg *prg);
// void	clear_window(t_prg *prg);
// void	draw_square_cell(t_prg *prg, t_point *point1, t_point *point2,  int color);
// int		mouse_hook(int keycode, int x, int y, t_prg *prg);
// void	is_valid_new_map(t_prg *prg);
// void	draw_grid(t_prg *prg);
// void	create_edition_map(t_prg *prg);
// void	draw_new_mini_map(t_prg *prg);
// void	draw_vertical_line_grid(t_prg *prg);
// void	draw_horizontal_line_grid(t_prg *prg);
// void	draw_circle(t_data *data, t_point center);
// void	get_map_pos_init(t_prg *prg);
// // void	cell_up(t_prg *prg, t_map *map, int x_map, int y_map);
// void	cell_up(t_prg *prg, t_point *pt1, t_point *pt2, t_point *index);
// void	position_point(t_prg *prg, t_point *index);
// void	clear_window(t_prg *prg);
// void	indications_strings(t_prg *prg);
// void	draw_info(t_prg *prg);

// /***************** ERROR ***********************/
// int		ft_error(int return_value, int size, char *str, ...);
// int		ft_free(int return_value, int size, ...);

// /***************** DDA ***********************/
// void	init_dda(t_player *player, t_win window, t_dda *dda, int x);
// void	perform_dda(t_prg *prg, t_dda *dda, int **world_map);

// /***************** DRAW ***********************/
// void	init_draw(t_prg *prg, t_draw *draw);
// void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
// void	draw_background(int x, t_prg *prg);

// /***************** RAYCASTING ***********************/
// void	create_main_map(t_prg *prg, int **world_map);

// /***************** HOOKS ***********************/
// void	mlx_hooks_management(t_prg *prg);

// int		keys_pressed(int keycode, t_prg *prg);
// int		keys_released(int keycode, t_prg *prg);
// void	keys_mouvements(t_prg *prg);

// int		mouse_pressed(int keycode, int x, int y, t_prg *prg);
// int		mouse_released(int keycode, int x, int y, t_prg *prg);
// void	mouse_mouvements(t_prg *prg);
// int		updated_mouse_pos(int x, int y, t_prg *prg);

// int		exit_cube(t_prg *prg);
// int		refresh_map(t_prg *prg);
// int		refresh_edition(t_prg *prg, int keycode);

// /***************** DRAW ***********************/
// void	draw_wall(t_prg *prg, int x);

// /***************** UTILS ***********************/
// void	free_2d_tab(char **tab);
// int		time_diff(struct timeval start);
// void	rotation_matrix(t_prg *prg, double rotation);

// void	draw_cross(t_prg *prg);
// void	create_mini_map(t_prg *prg);
// void	init_mini_map(t_prg *prg);
// bool	fill_texture(char *line, t_prg *prg);
// int		fill_background(char *line, t_prg *prg);
// bool	cub_extension(char *file_path);
#endif