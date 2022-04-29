/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:50:27 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/29 09:06:45 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	run_window(t_prg *prg)
{
	prg->edition.cell_height = prg->win.height / prg->parser.height * 0.3;
	prg->edition.cell_width = prg->win.width / prg->parser.width * 0.3;
	mlx_hook(prg->win.win, 4, 1L << 2, mouse_hook, prg);
	mlx_hook(prg->win.win, 4, 1L << 2, mouse_pressed, prg);
	mlx_hook(prg->win.win, 5, 1L << 3, mouse_released, prg);
	mlx_hook(prg->win.win, 6, 1L << 6, updated_mouse_pos, prg);
	mlx_loop_hook(prg->win.mlx, update, prg);
	mlx_loop(prg->win.mlx);
	return (1);
}