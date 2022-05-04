/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/04 15:04:19 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	up(t_prg *prg)
{
	if (prg->player.x_pos + prg->player.x_dir * prg->player.move_speed < prg->parser.width - 1
		&& prg->player.x_pos + prg->player.x_dir * prg->player.move_speed >= 1)
		prg->player.x_pos += prg->player.x_dir * prg->player.move_speed;
	if (prg->player.y_pos + prg->player.y_dir * prg->player.move_speed < prg->parser.height - 1
		&& prg->player.y_pos + prg->player.y_dir * prg->player.move_speed >= 1)
		prg->player.y_pos += prg->player.y_dir * prg->player.move_speed;
}

void	down(t_prg *prg)
{
	if (prg->player.x_pos - prg->player.x_dir * prg->player.move_speed < prg->parser.width - 1
		&& prg->player.x_pos - prg->player.x_dir * prg->player.move_speed >= 1)
		prg->player.x_pos -= prg->player.x_dir * prg->player.move_speed;
	if (prg->player.y_pos - prg->player.y_dir * prg->player.move_speed < prg->parser.height - 1
		&& prg->player.y_pos - prg->player.y_dir * prg->player.move_speed >= 1)
		prg->player.y_pos -= prg->player.y_dir * prg->player.move_speed;
}

void	right(t_prg *prg)
{
	if (prg->player.x_pos - prg->player.y_dir * prg->player.move_speed < prg->parser.width - 1
		&& prg->player.x_pos - prg->player.y_dir * prg->player.move_speed >= 1)
		prg->player.x_pos -= prg->player.y_dir * prg->player.move_speed;
	if (prg->player.y_pos + prg->player.x_dir * prg->player.move_speed < prg->parser.height - 1
		&& prg->player.y_pos + prg->player.x_dir * prg->player.move_speed >= 1)
		prg->player.y_pos += prg->player.x_dir * prg->player.move_speed;
}

void	left(t_prg *prg)
{
	if (prg->player.x_pos + prg->player.y_dir * prg->player.move_speed < prg->parser.width - 1
		&& prg->player.x_pos + prg->player.y_dir * prg->player.move_speed >= 1)
		prg->player.x_pos += prg->player.y_dir * prg->player.move_speed;
	if (prg->player.y_pos - prg->player.x_dir * prg->player.move_speed < prg->parser.height - 1
		&& prg->player.y_pos - prg->player.x_dir * prg->player.move_speed >= 1)
		prg->player.y_pos -= prg->player.x_dir * prg->player.move_speed;
}
