/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:14 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/29 09:02:00 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_line(t_data *data, t_point p1, t_point p2)
{
	for (float i = 0.0f; i < 1.0f; i += .005f)
	{
		int	x = p1.x + (p2.x - p1.x) * i;
		int y = p1.y + (p2.y - p1.y) * i;
		if (!(x < 0 || x >= 1920 || y < 0 || y >= 1080))
			my_mlx_pixel_put(data, x, y, WHITE);
	}
}

void	draw_grid(t_prg *prg)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;

	for (int y = 0; y < prg->parser.height; y++)
	{
		p1.y = y * prg->edition.cell_height;
		p2.y = p1.y + prg->edition.cell_height;
		p3.y = p1.y ;
		for (int x = 0; x < prg->parser.width; x++)
		{
			p1.x = x * prg->edition.cell_width;
			p2.x = p1.x;
			p3.x = p1.x + prg->edition.cell_width;
			draw_line(&prg->img, p1, p2);
			draw_line(&prg->img, p1, p3);
		}
	}
}

int	update(t_prg *prg)
{
	if (prg->edition_mode == 1)
	{
		clear_window(prg);
		set_grid_cell(prg, prg->edition.mouse_position.x,
				prg->edition.mouse_position.y);
		print_grid(prg);
		draw_grid(prg);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	}
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
		set_grid_cell(prg, x, y);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_prg *prg)
{
	prg->edition.mouse_pressed = 1;
	prg->edition.mouse_position.x = x;
	prg->edition.mouse_position.y = y;
	prg->edition.mouse_button = keycode;

	set_grid_cell(prg, x, y);

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

int	updated_mouse_pos(int x, int y, t_prg *prg)
{
	(void)prg;
	if (prg->edition_mode == 1)
	{
		if (prg->edition.mouse_pressed == 1)
		{
			dprintf(2, "x-->%d, y-->%d\n", x, y);
			prg->edition.mouse_position.x = x;
			prg->edition.mouse_position.y = y;
		}
	}
	return (0);
}