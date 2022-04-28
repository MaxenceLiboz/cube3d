/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:01:14 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 15:02:58 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	update(t_prg *prg)
{
	if (prg->edition_mode == 1)
	{
		// clear_window(data);
		set_grid_cell(prg, prg->edition.mouse_position.x,
				prg->edition.mouse_position.y);
		print_grid(prg);
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
		printf("x %d y %d \n", x, y);
		set_grid_cell(prg, x, y);
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

int	updated_mouse_pos(int x, int y, t_prg *prg)
{
	(void)prg;
	if (prg->edition_mode == 1)
	{
		dprintf(2, "x-->%d, y-->%d\n", x, y);
		prg->edition.mouse_position.x = x;
		prg->edition.mouse_position.y = y;
	}
	return (0);
}