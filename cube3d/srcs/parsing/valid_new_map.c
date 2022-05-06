/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:56 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 08:14:10 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	is_valid_new_map(t_prg *prg)
{
	prg->edition_mode = 2;
	if (is_valid_map(prg, 0) == true)
	{
		prg->map.cell_size = 10;
		prg->edition_mode = false;
		mlx_mouse_hide();
	}
	else
	{
		mlx_string_put(prg->win.mlx, prg->win.win, 1000, 900, RED, "TEST");
		printf("wrong map\n");
		prg->edition_mode = true;
	}
}
