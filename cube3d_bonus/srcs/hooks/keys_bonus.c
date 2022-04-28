/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 07:50:13 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	up(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos + prg->player.x_dir
			* (0.1 + 0.01))][(int)prg->player.y_pos] == 0)
				prg->player.x_pos += prg->player.x_dir * 0.1;
	if (prg->world_map[(int)(prg->player.x_pos)][(int)(prg->player.y_pos
			+ prg->player.y_dir * (0.1 + 0.01))] == 0)
			prg->player.y_pos += prg->player.y_dir * 0.1;
}

void	down(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos - prg->player.x_dir
			* (0.1 + 0.01))][(int)prg->player.y_pos] == 0)
		prg->player.x_pos -= prg->player.x_dir * 0.1;
	if (prg->world_map[(int)(prg->player.x_pos)][(int)(prg->player.y_pos
		- prg->player.y_dir * (0.1 + 0.01))] == 0)
		prg->player.y_pos -= prg->player.y_dir * 0.1;
}

void	left(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos - prg->player.y_dir
			* (0.1 + 0.01))][(int)prg->player.y_pos] == 0)
		prg->player.x_pos -= prg->player.y_dir * 0.1;
	if (prg->world_map[(int)(prg->player.x_pos)][(int)(prg->player.y_pos
		+ prg->player.x_dir * (0.1 + 0.01))] == 0)
		prg->player.y_pos += prg->player.x_dir * 0.1;
}

void	right(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos + prg->player.y_dir
			* (0.1 + 0.01))][(int)prg->player.y_pos] == 0)
		prg->player.x_pos += prg->player.y_dir * 0.1;
	if (prg->world_map[(int)(prg->player.x_pos)][(int)(prg->player.y_pos
		- prg->player.x_dir * (0.1 + 0.01))] == 0)
		prg->player.y_pos -= prg->player.x_dir * 0.1;
}

void	left_rot(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(prg->player.rotation_speed)
		- prg->player.y_dir * sin(prg->player.rotation_speed);
	prg->player.y_dir = old_x_dir * sin(prg->player.rotation_speed) + prg->player.y_dir * cos(prg->player.rotation_speed);
	prg->player.x_plane = prg->player.x_plane * cos(prg->player.rotation_speed)
		- prg->player.y_plane * sin(prg->player.rotation_speed);
	prg->player.y_plane = old_x_plane * sin(prg->player.rotation_speed)
		+ prg->player.y_plane * cos(prg->player.rotation_speed);
}

void	right_rot(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(-prg->player.rotation_speed)
		- prg->player.y_dir * sin(-prg->player.rotation_speed);
	prg->player.y_dir = old_x_dir * sin(-prg->player.rotation_speed) + prg->player.y_dir * cos(-prg->player.rotation_speed);
	prg->player.x_plane = prg->player.x_plane * cos(-prg->player.rotation_speed)
		- prg->player.y_plane * sin(-prg->player.rotation_speed);
	prg->player.y_plane = old_x_plane * sin(-prg->player.rotation_speed)
		+ prg->player.y_plane * cos(-prg->player.rotation_speed);
}
