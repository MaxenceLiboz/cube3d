/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:24:28 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/05 22:39:28 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_circle(t_data *data, t_point center)
{
	t_point	pos;
	int		radius;
	int		x;
	int		y;

	radius = 5;
	x = center.x - radius;
	y = center.y - radius;
	while (y < center.y + radius)
	{
		while (x < center.x + radius)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			if ((float)(pos.x + pos.y) - (radius * radius) < 0.1f)
				my_mlx_pixel_put(data, x, y, YELLOW);
			x++;
		}
		x = center.x - radius;
		y++;
	}
}

void	draw_square_cell(t_prg *prg, t_point *point1, t_point *point2, int color)
{
	int	x;
	int	y;

	x = point1->x;
	y = point1->y;
	while (y < point2->y)
	{
		while (x < point2->x)
		{
			my_mlx_pixel_put(&prg->img, x, y, color);
			x++;
		}
		y++;
		x = point1->x;
	}
}

// dprintf(2,"%f %d %f %d\n", prg->player.x_pos, cell_pos.x, prg->player.y_pos, cell_pos.y);
void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	x -= prg->map.center.x;
	y -= prg->map.center.y;
	cell_pos.x = x / prg->map.cell_size
		+ (prg->map.end_point.x - prg->map.max_cell_width);
	cell_pos.y = y / prg->map.cell_size
		+ (prg->map.end_point.y - prg->map.max_cell_height);
	if (cell_pos.x >= prg->parser.width || cell_pos.y >= prg->parser.height
		|| cell_pos.x < 0 || cell_pos.y < 0)
		return ;
	if (prg->mouse.mouse_keycode == 2 && ((int)prg->player.x_pos != cell_pos.x
			|| (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 0;
	else if (prg->mouse.mouse_keycode == 1 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 1;
	else if (prg->mouse.mouse_keycode == 3 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 2;
}

void	clear_window(t_prg *prg)
{
	t_point	point;

	point.y = 0;
	while (point.y < prg->win.height)
	{
		point.x = 0;
		while (point.x < prg->win.width)
		{
			my_mlx_pixel_put(&prg->img, point.x, point.y, DARK_GRAY);
			point.x++;
		}
		point.y++;
	}
}