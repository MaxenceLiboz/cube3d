/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:20:42 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/04 15:54:57 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	right_rot(t_prg *prg)
{
	rotation_matrix(prg, prg->player.rotation_speed);
	dprintf(2, "xd: %f, yd: %f, xp: %f, yp: %f\n", prg->player.x_dir, prg->player.y_dir, prg->player.x_plane, prg->player.y_plane);
}

void	left_rot(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(-prg->player.rotation_speed)
		- prg->player.y_dir * sin(-prg->player.rotation_speed);
	prg->player.y_dir = old_x_dir * sin(-prg->player.rotation_speed)
		+ prg->player.y_dir * cos(-prg->player.rotation_speed);
	prg->player.x_plane = prg->player.x_plane * cos(-prg->player.rotation_speed)
		- prg->player.y_plane * sin(-prg->player.rotation_speed);
	prg->player.y_plane = old_x_plane * sin(-prg->player.rotation_speed)
		+ prg->player.y_plane * cos(-prg->player.rotation_speed);
}
