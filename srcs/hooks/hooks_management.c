/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:54:34 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:40:01 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	mlx_hooks_management(t_prg *prg)
{
	mlx_hook(prg->win.win, 2, 1L << 0, keys_pressed, prg);
	mlx_hook(prg->win.win, 3, 1L << 1, keys_released, prg);
	mlx_hook(prg->win.win, 4, 1L << 2, mouse_pressed, prg);
	mlx_hook(prg->win.win, 5, 1L << 3, mouse_released, prg);
	mlx_hook(prg->win.win, 6, 1L << 6, updated_mouse_pos, prg);
	mlx_hook(prg->win.win, 17, 1L << 2, exit_cube, prg);
	mlx_loop_hook(prg->win.mlx, refresh_map, prg);
}
