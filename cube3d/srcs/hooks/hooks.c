/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:15:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 08:52:52 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	exit_cube(t_prg *prg)
{
	mlx_destroy_window(prg->win.mlx, prg->win.win);
	exit(1);
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
*/
int	key_pressed(int keycode, t_prg *prg)
{
	if (keycode == 53)
		exit_cube(prg);
	else if (keycode == 13)
		up(prg);
	else if (keycode == 1)
		down(prg);
	else if (keycode == 123)
		left_rot(prg);
	else if (keycode == 124)
		right_rot(prg);
	else if (keycode == 0)
		left(prg);
	else if (keycode == 2)
		right(prg);
	return (0);
}

int	time_diff(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000
		+ 1e-3 * (end.tv_usec - start.tv_usec));
}

int	refresh(t_prg *prg)
{
	struct timeval	start;
	double			time_sec;
	char			*str;

	gettimeofday(&start, NULL);
	write_map(prg, prg->world_map);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	time_sec = (double)time_diff(start) / 1000;
	str = ft_itoa(1 / time_sec);
	mlx_string_put(prg->win.mlx, prg->win.win, 15, 15, 0xFFFFFF, str);
	mlx_string_put(prg->win.mlx, prg->win.win, 50, 15, 0xFFFFFF, "fps");
	free(str);
	return (0);
}
