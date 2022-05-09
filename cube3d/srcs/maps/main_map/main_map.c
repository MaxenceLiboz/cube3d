/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:40:10 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 14:16:08 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	create_main_map(t_prg *prg, int **world_map)
{
	int		x;

	if (prg->h_map.help_mode == true)
		x = prg->h_map.max_size;
	else
		x = 0;
	draw_background(x, prg);
	while (x < prg->win.width)
	{
		init_dda(&prg->player, prg->win, &prg->dda, x);
		perform_dda(prg, &prg->dda, world_map);
		draw_wall(prg, x);
		x++;
	}
	draw_cross(prg);
	if (prg->h_map.help_mode == false)
		create_mini_map(prg);
}
