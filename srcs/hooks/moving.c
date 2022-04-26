/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 11:06:35 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	reset(t_win mlx, t_data *data)
{
	for(int x = 0; x < mlx.width; x++)
	{
		for(int y = 0; y < mlx.height; y++)
		{
			my_mlx_pixel_put(data, x, y, 0x000000);
		}
	}
}

void	exit_cube(t_prg *prg)
{
	mlx_destroy_window(prg->win.mlx, prg->win.win);
	exit(1);
}

void	up(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos + prg->player.x_dir)]
			[(int)prg->player.y_pos] == 0)
			prg->player.x_pos += prg->player.x_dir;
	if (prg->world_map[(int)(prg->player.x_pos)]
			[(int)(prg->player.y_pos + prg->player.y_dir)] == 0)
			prg->player.x_pos -= prg->player.y_dir;
}

/*
	keycode == 126 => up
	keycode == 125 => down
	keycode == 123 => left
	keycode == 124 => right
	1: For each keycode press move on the position related to the arrow.
	2: Add some condition to never let the image leave the entire screen
*/
int	key_pressed(int keycode, t_prg *prg)
{
	if (keycode == 53)
		exit_cube(prg);
	if (keycode == 126)
		up(prg);
	reset(prg->win, &prg->img);
	write_map(prg, prg->world_map);
	return (0);
}
