/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:20:03 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 08:47:45 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	draw_cross(t_prg *prg)
{
	int		x;
	int		y;

	x = prg->win.width / 2 - 5;
	y = prg->win.height / 2;
	while (x <= prg->win.width / 2 + 5)
	{
		my_mlx_pixel_put(&prg->img, x, y, 0x000000);
		my_mlx_pixel_put(&prg->img, x, y + 1, 0x000000);
		x++;
	}
	x = prg->win.width / 2;
	y = prg->win.height / 2 - 5;
	while (y <= prg->win.height / 2 + 5)
	{
		my_mlx_pixel_put(&prg->img, x, y, 0x000000);
		my_mlx_pixel_put(&prg->img, x + 1, y, 0x000000);
		y++;
	}
}

void	write_map(t_prg *prg, int **world_map)
{
	int		x;

	x = 0;
	while (x < prg->win.width)
	{
		init_dda(&prg->player, prg->win, &prg->dda, x);
		perform_dda(prg, &prg->dda, world_map);
		draw_img(prg, x);
		draw_background(x, prg);
		x++;
	}
	draw_cross(prg);
}
