/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:47 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/29 13:23:21 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	cell_pos.x = x / prg->edition.cell_size;
	cell_pos.y = y / prg->edition.cell_size;
	if (cell_pos.x >= prg->parser.width || cell_pos.y >= prg->parser.height
			|| cell_pos.x < 0 || cell_pos.y < 0)
		return ;
	if (prg->edition.mouse_keycode == 2 && ((int)prg->player.x_pos != cell_pos.x
		|| (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 0;
	else if (prg->edition.mouse_keycode == 1 && ((int)prg->player.x_pos
		!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 1;
	else if (prg->edition.mouse_keycode == 3 && ((int)prg->player.x_pos
		!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 2;
}

void draw_circle(t_data *data, t_point center)
{
	t_point pos;
	int radius = 5;

	for (int y = center.y - radius; y < center.y + radius; y++)
	{
			for (int x = center.x - radius; x < center.x + radius; x++)
			{
					pos.y = (center.y - y) * (center.y - y);
					pos.x = (center.x - x) * (center.x - x);
					if ((float)(pos.x + pos.y) - (radius * radius) < 0.1f)
							my_mlx_pixel_put(data, x, y, YELLOW);
			}
	}
}

void	print_grid(t_prg *prg)
{
	t_point	point1;
	t_point	point2;
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (y < prg->parser.height)
	{
		while (x < prg->parser.width)
		{
			point1.x = x * prg->edition.cell_size;
			point1.y = y * prg->edition.cell_size;
			point2.x = point1.x + prg->edition.cell_size;
			point2.y = point1.y + prg->edition.cell_size;
			if (prg->world_map[y][x] == 0)
			{
				if (is_valid_position(prg, x, y) == true)
					draw_square_cell(prg, point1, point2, BLACK);
				else
					draw_square_cell(prg, point1, point2, RED);
			}
			else if (prg->world_map[y][x] == 1)
				draw_square_cell(prg, point1, point2, BLUE);
			else 
				draw_square_cell(prg, point1, point2, GREEN);
			x++;
		}
		y++;
		x = 0;
	}
	point1.x = prg->player.x_pos * prg->edition.cell_size;
	point1.y = prg->player.y_pos * prg->edition.cell_size;
	point2.x = point1.x + prg->edition.cell_size;
	point2.y = point1.y + prg->edition.cell_size;
	draw_circle(&prg->img, point1);
}

void	clear_window(t_prg *prg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < prg->win.height)
	{
		while (x < prg->win.width)
		{
			my_mlx_pixel_put(&prg->img, x, y, DARK_GRAY);
			x++;
		}
		y++;
		x = 0;
	}
}

void	draw_square_cell(t_prg *prg, t_point point1, t_point point2,
		int color)
{
	int	x;
	int	y;

	x = point1.x;
	y = point1.y;
	while (y < point2.y)
	{
		while (x < point2.x)
		{
			my_mlx_pixel_put(&prg->img, x, y, color);
			x++;
		}
		y++;
		x = point1.x;
	}
}
