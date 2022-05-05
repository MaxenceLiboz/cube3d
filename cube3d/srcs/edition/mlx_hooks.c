/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:14 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/04 14:33:20 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	update(t_prg *prg, int keycode)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		set_grid_cell(prg, prg->mouse.mouse_position.x,
			prg->mouse.mouse_position.y);
	draw_new_map(prg);
	draw_vertical_line_grid(prg);
	draw_horizontal_line_grid(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	return (0);
}

int	mouse_pressed(int keycode, int x, int y, t_prg *prg)
{
	(void)keycode;
	if (prg->edition_mode == 1)
	{
		dprintf(2, "x: %d, y: %d\n", x, y);
		prg->mouse.mouse_pressed = 1;
		prg->mouse.mouse_position.x = x;
		prg->mouse.mouse_position.y = y;
		prg->mouse.mouse_keycode = keycode;
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
		prg->mouse.mouse_pressed = 0;
	return (0);
}

bool	new_cell_pos(t_prg *prg, int x, int y)
{
	t_point	old_pos;
	t_point	new_pos;

	old_pos.x = prg->mouse.mouse_position.x / prg->map.cell_size;
	old_pos.y = prg->mouse.mouse_position.y / prg->map.cell_size;
	new_pos.x = x / prg->map.cell_size;
	new_pos.y = y / prg->map.cell_size;
	prg->mouse.mouse_position.x = x;
	prg->mouse.mouse_position.y = y;
	if (old_pos.x == new_pos.x && old_pos.y == new_pos.y)
		return (false);
	return (true);
}

int	updated_mouse_pos(int x, int y, t_prg *prg)
{
	if (prg->edition_mode == 1)
		if (prg->mouse.mouse_pressed == 1)
			if (new_cell_pos(prg, x, y) == true)
				update(prg, 0);
	return (0);
}
