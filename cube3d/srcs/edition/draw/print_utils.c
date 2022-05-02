/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:47 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/02 17:06:20 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	x -= prg->map.center.x;
	y -= prg->map.center.y;
	cell_pos.x = x / prg->map.cell_size + (prg->map.end_point.x - prg->map.max_cell_width);
	cell_pos.y = y / prg->map.cell_size + (prg->map.end_point.y - prg->map.max_cell_height);
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

// void	print_grid(t_prg *prg)
// {
// 	t_point	point1;
// 	t_point	point2;
// 	int			x;
// 	int			y;

// 	x = 0;
// 	y = 0;
// 	while (y < prg->parser.height && y < prg->map.max_cell_height)
// 	{
// 		while (x < prg->parser.width && x < prg->map.max_cell_width)
// 		{
// 			point1.x = x * prg->map.cell_size;
// 			point1.y = y * prg->map.cell_size;
// 			point2.x = point1.x + prg->map.cell_size;
// 			point2.y = point1.y + prg->map.cell_size;
// 			if (prg->world_map[y][x] == 0)
// 			{
// 				if (is_valid_position(prg, x, y) == true)
// 					draw_square_cell(prg, point1, point2, BLACK);
// 				else
// 					draw_square_cell(prg, point1, point2, RED);
// 			}
// 			else if (prg->world_map[y][x] == 1)
// 				draw_square_cell(prg, point1, point2, BLUE);
// 			else 
// 				draw_square_cell(prg, point1, point2, GREEN);
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	point1.x = prg->player.x_pos * prg->map.cell_size;
// 	point1.y = prg->player.y_pos * prg->map.cell_size;
// 	if (point1.x / prg->parser.width <= prg->map.max_cell_width && point1.y / prg->parser.height <= prg->map.max_cell_height)
// 		draw_circle(&prg->img, point1);
// }

void	draw_new_map(t_prg *prg, int keycode)
{
	t_point	point1;
	t_point	point2;
	int			x;
	int			x_map;
	int			y;
	int			y_map;

	if (keycode == 123 && prg->map.end_point.x - prg->map.max_cell_width > 0)
		prg->map.end_point.x -= 1;
	if (keycode == 124 && prg->map.end_point.x < prg->parser.width)
		prg->map.end_point.x += 1;
	if (keycode == 125 && prg->map.end_point.y < prg->parser.height)
		prg->map.end_point.y += 1;
	if (keycode == 126 && prg->map.end_point.y - prg->map.max_cell_height > 0)
		prg->map.end_point.y -= 1;
	x = 0;
	y = 0;
	y_map = prg->map.end_point.y - prg->map.max_cell_height;
	while (y < prg->parser.height && y < prg->map.max_cell_height && y_map < prg->parser.height)
	{
		x_map = prg->map.end_point.x - prg->map.max_cell_width;
		while (x < prg->parser.width && x < prg->map.max_cell_width && x_map < prg->parser.width)
		{
			point1.x = x * prg->map.cell_size + prg->map.center.x;
			point1.y = y * prg->map.cell_size + prg->map.center.y;
			point2.x = point1.x + prg->map.cell_size;
			point2.y = point1.y + prg->map.cell_size;
			if (prg->world_map[y_map][x_map] == 0)
			{
				if (is_valid_position(prg, x_map, y_map) == true)
				{
					draw_square_cell(prg, point1, point2, BLACK);
					if ((int)prg->player.x_pos == x_map && (int)prg->player.y_pos == y_map)
					{
						point1.x = (prg->player.x_pos * prg->map.cell_size + prg->map.center.x) - ((prg->map.end_point.x - prg->map.max_cell_width) * prg->map.cell_size);
						point1.y = prg->player.y_pos * prg->map.cell_size + prg->map.center.y - ((prg->map.end_point.y - prg->map.max_cell_height) * prg->map.cell_size);
						draw_circle(&prg->img, point1);
					}
				}
				else
					draw_square_cell(prg, point1, point2, RED);
			}
			else if (prg->world_map[y_map][x_map] == 1)
				draw_square_cell(prg, point1, point2, BLUE);
			else 
				draw_square_cell(prg, point1, point2, GREEN);
			x++;
			x_map++;
		}
		y++;
		y_map++;
		x = 0;
	}
	// point1.x = prg->player.x_pos * prg->map.cell_size * 0.4f;
	// point1.y = prg->player.y_pos * prg->map.cell_size * 0.4f;
	// if (keycode != 0)
	// dprintf(2, "x: %f, y: %f\n", prg->player.x_pos, prg->player.y_pos);
	// if (point1.x < prg->win.width)
	// draw_circle(&prg->img, point1);
}

void	draw_new_mini_map(t_prg *prg)
{
	t_point	point1;
	t_point	point2;
	int			x;
	int			x_map;
	int			y;
	int			y_map;

	x = 0;
	y = 0;
	y_map = prg->player.y_pos - (prg->map.max_cell_height / 2);
	if (y_map < 0)
		y_map = 0;
	if (y_map + prg->map.max_cell_height > prg->parser.height)
			y_map = prg->parser.height - prg->map.max_cell_height;
	while (y < prg->parser.height && y < prg->map.max_cell_height && y_map < prg->parser.height)
	{
		x_map = prg->player.x_pos - (prg->map.max_cell_width / 2);
		if (x_map < 0)
			x_map = 0;
		if (x_map + prg->map.max_cell_width > prg->parser.width)
			x_map = prg->parser.width - prg->map.max_cell_width;
		while (x < prg->parser.width && x < prg->map.max_cell_width && x_map < prg->parser.width)
		{
			point1.x = x * prg->map.cell_size;
			point1.y = y * prg->map.cell_size;
			point2.x = point1.x + prg->map.cell_size;
			point2.y = point1.y + prg->map.cell_size;
			if (prg->world_map[y_map][x_map] == 0)
			{
				if (is_valid_position(prg, x_map, y_map) == true)
				{
					draw_square_cell(prg, point1, point2, BLACK);
					//CREER DEUX PUTIN DE MAP DIFFERENTE !!!
					point1.x = prg->player.x_pos * prg->map.cell_size - ((prg->map.end_point.x - prg->map.max_cell_width) * prg->map.cell_size);
					point1.y = prg->player.y_pos * prg->map.cell_size - ((prg->map.end_point.y - prg->map.max_cell_height) * prg->map.cell_size);
					dprintf(2, "%d\n", prg->map.end_point.x);
					dprintf(2, "%d\n", prg->map.end_point.y);
					draw_circle(&prg->img, point1);
				}
				else
					draw_square_cell(prg, point1, point2, RED);
			}
			else if (prg->world_map[y_map][x_map] == 1)
				draw_square_cell(prg, point1, point2, BLUE);
			else 
				draw_square_cell(prg, point1, point2, GREEN);
			x++;
			x_map++;
		}
		y++;
		y_map++;
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
