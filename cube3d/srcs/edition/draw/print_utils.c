/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:26:47 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 15:01:53 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	// if (x < 0 || x >= prg->win_width || y < 0 || y >= prg->win_height)
	// 	return ;
	cell_pos.x = x / prg->edition.cell_width;
	cell_pos.y = y / prg->edition.cell_height;
	if (prg->edition.mouse_keycode == 1)
		prg->world_map[cell_pos.y][cell_pos.x] = 1;
	else if (prg->edition.mouse_keycode == 2)
		prg->world_map[cell_pos.y][cell_pos.x] = 0;
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
			point1.x = x * prg->edition.cell_width;
			point1.y = y * prg->edition.cell_height;
			point2.x = point1.x + prg->edition.cell_width;
			point2.y = point1.y + prg->edition.cell_height;
			if (prg->world_map[y][x] == 0)
				draw_square_cell(prg, point1, point2, DARK_GRAY);
			else
				draw_square_cell(prg, point1, point2, PINK);
			x++;
		}
		y++;
		x = 0;
	}
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x >= prg->win_width || y >= data->win_height || x < 0 || y < 0)
// 		return ;
// 	dst = data->addr + (y * data->line_length + x
// 			* (data->bits_per_pixels / 8));
// 	*(unsigned int *)dst = color;
// }

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
