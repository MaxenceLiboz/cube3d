/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:55:16 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/27 08:27:52 by mliboz           ###   ########.fr       */
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
	if (prg->world_map[(int)(prg->player.x_pos + prg->player.x_dir * 0.22)]
			[(int)prg->player.y_pos] == 0)
				prg->player.x_pos += prg->player.x_dir * 0.2;
	if (prg->world_map[(int)(prg->player.x_pos)]
			[(int)(prg->player.y_pos + prg->player.y_dir * 0.22)] == 0)
			prg->player.y_pos += prg->player.y_dir * 0.2;
}

void	down(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos - prg->player.x_dir * 0.22)]
			[(int)prg->player.y_pos] == 0)
		prg->player.x_pos -= prg->player.x_dir * 0.2;
	if (prg->world_map[(int)(prg->player.x_pos)]
			[(int)(prg->player.y_pos - prg->player.y_dir * 0.22)] == 0)
		prg->player.y_pos -= prg->player.y_dir * 0.2;
}

void	left(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos - prg->player.y_dir * 0.22)]
			[(int)prg->player.y_pos] == 0)
		prg->player.x_pos -= prg->player.y_dir * 0.2;
	if (prg->world_map[(int)(prg->player.x_pos)]
			[(int)(prg->player.y_pos + prg->player.x_dir * 0.22)] == 0)
		prg->player.y_pos += prg->player.x_dir * 0.2;
}

void	right(t_prg *prg)
{
	if (prg->world_map[(int)(prg->player.x_pos + prg->player.y_dir * 0.22)]
			[(int)prg->player.y_pos] == 0)
		prg->player.x_pos += prg->player.y_dir * 0.2;
	if (prg->world_map[(int)(prg->player.x_pos)]
			[(int)(prg->player.y_pos - prg->player.x_dir * 0.22)] == 0)
		prg->player.y_pos -= prg->player.x_dir * 0.2;
}

void	left_rot(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(0.04)
		- prg->player.y_dir * sin(0.04);
	prg->player.y_dir = old_x_dir * sin(0.04) + prg->player.y_dir * cos(0.04);
	prg->player.x_plane = prg->player.x_plane * cos(0.04)
		- prg->player.y_plane * sin(0.04);
	prg->player.y_plane = old_x_plane * sin(0.04)
		+ prg->player.y_plane * cos(0.04);
}

void	right_rot(t_prg *prg)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(-0.04)
		- prg->player.y_dir * sin(-0.04);
	prg->player.y_dir = old_x_dir * sin(-0.04) + prg->player.y_dir * cos(-0.04);
	prg->player.x_plane = prg->player.x_plane * cos(-0.04)
		- prg->player.y_plane * sin(-0.04);
	prg->player.y_plane = old_x_plane * sin(-0.04)
		+ prg->player.y_plane * cos(-0.04);
}

/*
	keycode == 13  => w
	keycode == 1   => s
	keycode == 0   => a
	keycode == 2   => d
	keycode == 126 => up
	keycode == 125 => down
	keycode == 123 => left
	keycode == 124 => right
	1: For each keycode press move on the position related to the arrow.
	2: Add some condition to never let the image leave the entire screen
*/
int	key_pressed(int keycode, t_prg *prg)
{
	// printf("%d\n", keycode);
	if (keycode == 53)
		exit_cube(prg);
	else if (keycode == 13)
		up(prg);
	else if (keycode == 1)
		down(prg);
	else if (keycode == 0)
		left(prg);
	else if (keycode == 2)
		right(prg);
	else if (keycode == 123)
		left_rot(prg);
	else if (keycode == 124)
		right_rot(prg);
	reset(prg->win, &prg->img);
	write_map(prg, prg->world_map);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	return (0);
}
