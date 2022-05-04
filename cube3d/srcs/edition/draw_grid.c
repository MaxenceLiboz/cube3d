/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:16:35 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/03 10:21:50 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_line(t_data *data, t_point p1, t_point p2, int color)
{
	for (float i = 0.0f; i < 1.0f; i += .0005f)
	{
		int	x = p1.x + (p2.x - p1.x) * i;
		int y = p1.y + (p2.y - p1.y) * i;
		if (!(x < 0 || x >= 1920 || y < 0 || y >= 1080))
			my_mlx_pixel_put(data, x, y, color);
	}
}

void	draw_vertical_line_grid(t_prg *prg)
{
	t_point start;
	t_point end;
	int		x;

	x = 0;

	while (x <= prg->parser.width && x <= prg->map.max_cell_width)
	{
		start.x = prg->map.cell_size * x + prg->map.center.x;
		start.y = prg->map.center.y;

		end.x = start.x;
		if (prg->map.big_map_height == false)
			end.y = prg->map.cell_size * prg->parser.height + prg->map.center.y;
		else
			end.y = prg->map.cell_size * prg->map.max_cell_height + prg->map.center.y;
		if (!((x == prg->map.max_cell_width && prg->map.end_point.x == prg->parser.width) 
			|| (x == 0 && prg->map.end_point.x == prg->map.max_cell_width)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
		x++;
	}
}

void	draw_horizontal_line_grid(t_prg *prg)
{
	t_point start;
	t_point end;
	int		y;

	y = 0;
	while (y <= prg->parser.height && y <= prg->map.max_cell_height)
	{
		start.x = prg->map.center.x;
		start.y = y * prg->map.cell_size + prg->map.center.y;
		
		end.y = start.y;
		if (prg->map.big_map_width == false)
			end.x = prg->map.cell_size * prg->parser.width + prg->map.center.x;
		else
			end.x = prg->map.cell_size * prg->map.max_cell_width + prg->map.center.x;
		if (!((y == prg->map.max_cell_height && prg->map.end_point.y == prg->parser.height)
			|| (y == 0 && prg->map.end_point.y == prg->map.max_cell_height)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
		y++;
	}
}