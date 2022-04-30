/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:14 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/30 13:10:10 by tarchimb         ###   ########.fr       */
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

void	draw_grid(t_prg *prg)
{
	t_point start;
	t_point end;

	for (int x = 0; x <= prg->parser.width && x <= prg->map.max_cell_width; x++)
	{
		start.x = prg->map.cell_size * x;
		start.y = 0;

		end.x = start.x;
		if (prg->map.big_map_height == false)
			end.y = prg->map.cell_size * prg->parser.height;
		else
			end.y = prg->map.cell_size * prg->map.max_cell_height;
		if (!((x == prg->map.max_cell_width && prg->map.end_point.x == prg->parser.width) 
			|| (x == 0 && prg->map.end_point.x == prg->map.max_cell_width)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
	}

	for (int y = 0; y <= prg->parser.height && y <= prg->map.max_cell_height; y++)
	{
		start.x = 0;
		start.y = y * prg->map.cell_size;
		
		end.y = start.y;
		if (prg->map.big_map_width == false)
			end.x = prg->map.cell_size * prg->parser.width;
		else
			end.x = prg->map.cell_size * prg->map.max_cell_width;
		if (!((y == prg->map.max_cell_height && prg->map.end_point.y == prg->parser.height)
			|| (y == 0 && prg->map.end_point.y == prg->map.max_cell_height)))
			draw_line(&prg->img, start, end, WHITE);
		else
			draw_line(&prg->img, start, end, RED);
	}
}

int	update(t_prg *prg, int keycode)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		set_grid_cell(prg, prg->edition.mouse_position.x,
			prg->edition.mouse_position.y);
	draw_new_map(prg, keycode);
	draw_grid(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img,
		prg->map.center.x, prg->map.center.y);
	return (0);
}

int	mouse_pressed(int keycode, int x, int y, t_prg *prg)
{
	(void)keycode;
	if (prg->edition_mode == 1)
	{
		prg->edition.mouse_pressed = 1;
		prg->edition.mouse_position.x = x;
		prg->edition.mouse_position.y = y;
		prg->edition.mouse_keycode = keycode;
		update(prg, keycode);
	}
	return (0);
}

int	mouse_released(int keycode, int x, int y, t_prg *prg)
{
	(void)keycode;
	(void)x;
	(void)y;
	if (prg->edition_mode == 1)
		prg->edition.mouse_pressed = 0;
	return (0);
}

bool	new_cell_pos(t_prg *prg, int x, int y)
{
	t_point	old_pos;
	t_point	new_pos;

	old_pos.x = prg->edition.mouse_position.x / prg->map.cell_size;
	old_pos.y = prg->edition.mouse_position.y / prg->map.cell_size;
	new_pos.x = x / prg->map.cell_size;
	new_pos.y = y / prg->map.cell_size;

	prg->edition.mouse_position.x = x;
	prg->edition.mouse_position.y = y;
	if (old_pos.x == new_pos.x && old_pos.y == new_pos.y)
		return (false);
	return (true);
}

int	updated_mouse_pos(int x, int y, t_prg *prg)
{
	if (prg->edition_mode == 1)
		if (prg->edition.mouse_pressed == 1)
			if (new_cell_pos(prg, x, y) == true)
				update(prg, 0);
	return (0);
}
