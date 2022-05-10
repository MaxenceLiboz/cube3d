/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:04 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 16:23:48 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structure.h"

void	draw_vertical_line_grid(t_prg *prg);
void	draw_horizontal_line_grid(t_prg *prg);
void	draw_circle(t_data *data, t_point center);
void	draw_square_cell(t_prg *prg, t_point *point1, t_point *point2,
			int color);
void	clear_window(t_prg *prg);
void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
void	grid_for_unit_cell(t_prg *prg, t_point pt1);
void	draw_line(t_data *data, t_point p1, t_point p2, int color);
void	get_circle_position(t_prg *prg, t_edition_map *map, int x_map);
int		color_lerp(int color1, int color2, float timestamp);
float	ft_inv_lerp_d(int min, int max, int curr);
void	draw_rayline(t_data *data, t_point p0, t_point p1, int color);
#endif