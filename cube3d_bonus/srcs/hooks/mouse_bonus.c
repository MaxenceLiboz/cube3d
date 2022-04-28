/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:42:37 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/27 13:47:34 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	rotate_left_w_mouse(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(0.08)
		- prg->player.y_dir * sin(0.08);
	prg->player.y_dir = old_x_dir * sin(0.08)
		+ prg->player.y_dir * cos(0.08);
	prg->player.x_plane = prg->player.x_plane
		* cos(0.08)
		- prg->player.y_plane * sin(0.08);
	prg->player.y_plane = old_x_plane * sin(0.08)
		+ prg->player.y_plane * cos(0.08);
}

void	rotate_right_w_mouse(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(-0.08)
		- prg->player.y_dir * sin(-0.08);
	prg->player.y_dir = old_x_dir * sin(-0.08)
		+ prg->player.y_dir * cos(-0.08);
	prg->player.x_plane = prg->player.x_plane
		* cos(-0.08)
		- prg->player.y_plane * sin(-0.08);
	prg->player.y_plane = old_x_plane * sin(-0.08)
		+ prg->player.y_plane * cos(-0.08);
}

void	check_mouse_pos(t_prg *prg, int x, int y)
{
	if (x <= 0)
		prg->player.x_mouse_pos = prg->win.width;
	else if (x >= prg->win.width)
		prg->player.x_mouse_pos = 0;
	else
		prg->player.x_mouse_pos = x;
	mlx_mouse_move(prg->win.win, prg->player.x_mouse_pos, prg->win.height / 2);
	(void)y;
}
