/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:04 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:18:36 by mliboz           ###   ########.fr       */
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

#endif