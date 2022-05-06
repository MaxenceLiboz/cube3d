/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:16:35 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 19:55:08 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	draw_line(t_data *data, t_point p1, t_point p2, int color)
{
	float	i;
	int		x;
	int		y;

	i = 0.0f;
	while (i < 1.0f)
	{
		x = p1.x + (p2.x - p1.x) * i;
		y = p1.y + (p2.y - p1.y) * i;
		if (!(x < 0 || x >= 1920 || y < 0 || y >= 1080))
			my_mlx_pixel_put(data, x, y, color);
		i += .0005f;
	}
}

void	draw_vertical_line_grid(t_prg *prg)
{
	t_point	start;
	t_point	end;
	int		x;

	x = 0;
	while (x <= prg->parser.width && x <= prg->e_map.max_cell_width)
	{
		start.x = prg->e_map.cell_size * x + prg->e_map.center.x;
		start.y = prg->e_map.center.y;
		end.x = start.x;
		if (prg->parser.height <= prg->e_map.max_cell_height)
			end.y = prg->e_map.cell_size * prg->parser.height
				+ prg->e_map.center.y;
		else
			end.y = prg->e_map.cell_size * prg->e_map.max_cell_height
				+ prg->e_map.center.y;
		if (!((x == prg->e_map.max_cell_width && prg->e_map.end_point.x
					== prg->parser.width) || (x == 0 && prg->e_map.end_point.x
					== prg->e_map.max_cell_width)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
		x++;
	}
}

void	draw_horizontal_line_grid(t_prg *prg)
{
	t_point	start;
	t_point	end;
	int		y;

	y = 0;
	while (y <= prg->parser.height && y <= prg->e_map.max_cell_height)
	{
		start.x = prg->e_map.center.x;
		start.y = y * prg->e_map.cell_size + prg->e_map.center.y;
		end.y = start.y;
		if (prg->parser.width <= prg->e_map.max_cell_width)
			end.x = prg->e_map.cell_size * prg->parser.width
				+ prg->e_map.center.x;
		else
			end.x = prg->e_map.cell_size * prg->e_map.max_cell_width
				+ prg->e_map.center.x;
		if (!((y == prg->e_map.max_cell_height && prg->e_map.end_point.y
					== prg->parser.height) || (y == 0 && prg->e_map.end_point.y
					== prg->e_map.max_cell_height)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
		y++;
	}
}

void	grid_for_unit_cell(t_prg *prg, t_point pt1)
{
	t_point	pt2;
	
	pt2.x = pt1.x + prg->e_map.cell_size;
	pt2.y = pt1.y;
	draw_line(&prg->img, pt1, pt2, WHITE);
	pt2.x = pt1.x;
	pt2.y = pt1.y + prg->e_map.cell_size;
	draw_line(&prg->img, pt1, pt2, WHITE);
	pt1.x += prg->e_map.cell_size;
	pt2.x += prg->e_map.cell_size;
	draw_line(&prg->img, pt1, pt2, WHITE);
	pt1.x -= prg->e_map.cell_size;
	pt1.y += prg->e_map.cell_size;
	draw_line(&prg->img, pt1, pt2, WHITE);
}