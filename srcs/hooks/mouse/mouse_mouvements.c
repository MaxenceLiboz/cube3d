/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouvements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:57:56 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:23:22 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	mouse_left_rot(t_prg *prg, int x, int i)
{
	if (x < prg->mouse.mouse_position.x && prg->mouse.mouse_position.x - x > 4)
	{
		while (i < (prg->mouse.mouse_position.x - x - 4) / 2)
		{
			rotation_matrix(prg, -ROT_MOUSE_SPEED * prg->player.delta);
			i++;
		}
	}
}

static void	mouse_right_rot(t_prg *prg, int x, int i)
{
	if (x > prg->mouse.mouse_position.x && x - prg->mouse.mouse_position.x > 4)
	{
		while (i < (x - prg->mouse.mouse_position.x - 4) / 2)
		{
			rotation_matrix(prg, ROT_MOUSE_SPEED * prg->player.delta);
			i++;
		}
	}
}

void	mouse_mouvements(t_prg *prg)
{
	int		x;
	int		i;

	mlx_mouse_get_pos(prg->win.win, &x, &i);
	i = 0;
	mouse_left_rot(prg, x, i);
	mouse_right_rot(prg, x, i);
	mlx_mouse_move(prg->win.win, prg->win.width / 2, prg->win.height / 2);
	mlx_mouse_get_pos(prg->win.win, &prg->mouse.mouse_position.x,
		&prg->mouse.mouse_position.y);
}
