/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouvements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 16:05:45 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	up(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos + prg->player.x_dir * MOVE_SPEED
		* prg->player.delta;
	new_y_pos = prg->player.y_pos + prg->player.y_dir * MOVE_SPEED
		* prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		+ prg->player.x_dir * (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			== 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos + prg->player.y_dir
			* (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

static void	down(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos - prg->player.x_dir * MOVE_SPEED
		* prg->player.delta;
	new_y_pos = prg->player.y_pos - prg->player.y_dir * MOVE_SPEED
		* prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		- prg->player.x_dir * (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			== 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos - prg->player.y_dir
			* (MOVE_SPEED * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

static void	right(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos - prg->player.y_dir * MOVE_SPEED / 2
		* prg->player.delta;
	new_y_pos = prg->player.y_pos + prg->player.x_dir * MOVE_SPEED / 2
		* prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		- prg->player.y_dir * (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			== 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos + prg->player.x_dir
			* (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

static void	left(t_prg *prg)
{
	double	new_x_pos;
	double	new_y_pos;

	new_x_pos = prg->player.x_pos + prg->player.y_dir * MOVE_SPEED / 2
		* prg->player.delta;
	new_y_pos = prg->player.y_pos - prg->player.x_dir * MOVE_SPEED / 2
		* prg->player.delta;
	if (prg->world_map[(int)prg->player.y_pos][(int)(prg->player.x_pos
		+ prg->player.y_dir * (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			== 0)
		prg->player.x_pos = new_x_pos;
	if (prg->world_map[(int)(prg->player.y_pos - prg->player.x_dir
			* (MOVE_SPEED / 2 * prg->player.delta + SAFE_COL))]
			[(int)prg->player.x_pos] == 0)
		prg->player.y_pos = new_y_pos;
}

void	keys_mouvements(t_prg *prg)
{
	if (prg->player.keyboard[KEY_W_TAB] == 1)
		up(prg);
	if (prg->player.keyboard[KEY_S_TAB] == 1)
		down(prg);
	if (prg->player.keyboard[KEY_A_TAB] == 1)
		left(prg);
	if (prg->player.keyboard[KEY_D_TAB] == 1)
		right(prg);
	if (prg->player.keyboard[KEY_LEFT_TAB] == 1)
		rotation_matrix(prg, -ROT_SPEED * prg->player.delta);
	if (prg->player.keyboard[KEY_RIGHT_TAB] == 1)
		rotation_matrix(prg, ROT_SPEED * prg->player.delta);
}
