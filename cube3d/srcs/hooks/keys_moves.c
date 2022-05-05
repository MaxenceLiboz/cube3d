/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 14:03:45 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

// dprintf(2, "xpos: %f, ypos: %f, newxpos: %f, newypos: %f\n", prg->player.x_pos, prg->player.y_pos, new_x_pos, new_y_pos);
// dprintf(2, "wallx: %d, ", prg->world_map[(int)prg->player.y_pos][(int)(new_x_pos + x_safe_value)]);
// dprintf(2, "wally: %d, ", prg->world_map[(int)(new_y_pos + y_safe_value)][(int)prg->player.x_pos]);
// dprintf(2, "wmx: %f, wmy: %f, ", (new_x_pos + x_safe_value), (new_y_pos + y_safe_value));
// dprintf(2, "wmx: %d, wmy: %d\n", (int)(new_x_pos + x_safe_value), (int)(new_y_pos + y_safe_value));
// dprintf(2, "xsafe: %f, ysafe: %f\n", prg->player.y_dir, prg->player.x_dir);
void	up(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos + prg->player.x_dir * MOVE_SPEED * prg->player.delta;
	new_y_pos = prg->player.y_pos + prg->player.y_dir * MOVE_SPEED * prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		+ prg->player.x_dir * (MOVE_SPEED * prg->player.delta + SAFE_COL))] == 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos + prg->player.y_dir
			* (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

void	down(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos - prg->player.x_dir * MOVE_SPEED * prg->player.delta;
	new_y_pos = prg->player.y_pos - prg->player.y_dir * MOVE_SPEED * prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		- prg->player.x_dir * (MOVE_SPEED * prg->player.delta + SAFE_COL))] == 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos - prg->player.y_dir
			* (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

void	right(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos - prg->player.y_dir * MOVE_SPEED / 2 * prg->player.delta;
	new_y_pos = prg->player.y_pos + prg->player.x_dir * MOVE_SPEED / 2 * prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		- prg->player.y_dir * (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))] == 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos + prg->player.x_dir
			* (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

void	left(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos + prg->player.y_dir * MOVE_SPEED / 2 * prg->player.delta;
	new_y_pos = prg->player.y_pos - prg->player.x_dir * MOVE_SPEED / 2 * prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		+ prg->player.y_dir * (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))] == 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos - prg->player.x_dir
			* (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}
