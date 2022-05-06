/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:40:10 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 23:19:21 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	create_main_map(t_prg *prg, int **world_map)
{
	int		x;

	x = 0;
	while (x < prg->win.width)
	{
		init_dda(&prg->player, prg->win, &prg->dda, x);
		perform_dda(prg, &prg->dda, world_map);
		draw_wall(prg, x);
		draw_background(x, prg);
		x++;
	}
	draw_cross(prg);
	create_mini_map(prg);
}
