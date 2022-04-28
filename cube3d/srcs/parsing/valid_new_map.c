/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:39:56 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 17:54:57 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

void	is_valid_new_map(t_prg *prg)
{
	prg->edition_mode = 2;
	if (is_valid_map(prg, 0) == true)
		prg->edition_mode = 0;
	else
	{
		
		mlx_string_put(prg->win.mlx, prg->win.win, 1000, 500, RED, "Fuck Off\n");
		printf("wrong map\n");
		prg->edition_mode = 1;
	}
}