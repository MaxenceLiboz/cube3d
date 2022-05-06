/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_pressed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:11:09 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 23:18:46 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int	edition_key_code(int keycode, t_prg *prg)
{
	if (keycode == 14)
		is_valid_new_map(prg);
	else if (keycode == 123)
	{
		if (prg->e_map.end_point.x - prg->e_map.max_cell_width > 0)
			prg->e_map.end_point.x -= 1;
	}
	else if (keycode == 124)
	{
		if (prg->e_map.end_point.x < prg->parser.width)
				prg->e_map.end_point.x += 1;
	}
	else if (keycode == 125 && prg->e_map.end_point.y < prg->parser.height)
		prg->e_map.end_point.y += 1;
	else if (keycode == 126 && prg->e_map.end_point.y
		- prg->e_map.max_cell_height > 0)
		prg->e_map.end_point.y -= 1;
	if (keycode != 14)
		refresh_edition(prg, keycode);
	return (0);
}

static void	set_keyboard_pressed(t_prg *prg, int keycode)
{
	if (keycode == KEY_W)
		prg->player.keyboard[KEY_W_TAB] = 1;
	else if (keycode == KEY_S)
		prg->player.keyboard[KEY_S_TAB] = 1;
	else if (keycode == KEY_A)
		prg->player.keyboard[KEY_A_TAB] = 1;
	else if (keycode == KEY_D)
		prg->player.keyboard[KEY_D_TAB] = 1;
	else if (keycode == KEY_LEFT)
		prg->player.keyboard[KEY_LEFT_TAB] = 1;
	else if (keycode == KEY_RIGHT)
		prg->player.keyboard[KEY_RIGHT_TAB] = 1;
}

int	keys_pressed(int keycode, t_prg *prg)
{
	if (keycode == KEY_ESC)
		exit_cube(prg);
	if (prg->edition_mode == true)
		edition_key_code(keycode, prg);
	else if (keycode == KEY_H)
	{
		prg->h_map.help_mode = !prg->h_map.help_mode;
		if (prg->h_map.help_mode == false)
			prg->h_map.is_printable = false;
	}
	else
	{
		set_keyboard_pressed(prg, keycode);
		if (keycode == KEY_E)
		{
			prg->e_map.cell_size = 40;
			prg->edition_mode = !prg->edition_mode;
			refresh_edition(prg, keycode);
			mlx_mouse_show();
		}
	}
	return (0);
}
