/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:14 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/29 13:23:10 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_line(t_data *data, t_point p1, t_point p2)
{
	for (float i = 0.0f; i < 1.0f; i += .0005f)
	{
		int	x = p1.x + (p2.x - p1.x) * i;
		int y = p1.y + (p2.y - p1.y) * i;
		if (!(x < 0 || x >= 1920 || y < 0 || y >= 1080))
			my_mlx_pixel_put(data, x, y, WHITE);
	}
}

void	draw_grid(t_prg *prg)
{
	t_point start;
	t_point end;

	for (int x = 0; x <= prg->parser.width; x++)
	{
		start.x = prg->edition.cell_size * x;
		start.y = 0;

		end.x = start.x;
		end.y = prg->edition.cell_size * prg->parser.height;
		draw_line(&prg->img, start, end);
	}

	for (int y = 0; y <= prg->parser.height; y++)
	{
		start.x = 0;
		end.x = prg->edition.cell_size * prg->parser.width;
		start.y = y * prg->edition.cell_size;
		end.y = start.y;
		draw_line(&prg->img, start, end);
	}
}

int	update(t_prg *prg)
{
	set_grid_cell(prg, prg->edition.mouse_position.x,
			prg->edition.mouse_position.y);
	print_grid(prg);
	draw_grid(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
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
		update(prg);
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
	int		new_width;
	int		new_height;
	t_point	old_pos;
	t_point	new_pos;

	new_width =  prg->win.width * prg->edition.offset_in;
	new_height =  prg->win.height * prg->edition.offset_in;
	old_pos.x = prg->edition.mouse_position.x / prg->edition.cell_size;
	old_pos.y = prg->edition.mouse_position.y / prg->edition.cell_size;
	new_pos.x = x / prg->edition.cell_size;
	new_pos.y = y / prg->edition.cell_size;

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
				update(prg);
	return (0);
}
