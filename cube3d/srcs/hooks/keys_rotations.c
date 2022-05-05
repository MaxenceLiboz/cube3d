/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 08:20:42 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 14:05:43 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

// dprintf(2, "xd: %f, yd: %f, xp: %f, yp: %f\n", prg->player.x_dir, prg->player.y_dir, prg->player.x_plane, prg->player.y_plane);
void	right_rot(t_prg *prg)
{
	rotation_matrix(prg, ROT_SPEED * prg->player.delta);
}

void	left_rot(t_prg *prg)
{
	rotation_matrix(prg, -ROT_SPEED * prg->player.delta);
}
