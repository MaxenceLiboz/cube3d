/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:15:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/27 15:53:26 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

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
	printf("%d\n", keycode);
	if (keycode == 53)
		exit_cube(prg);
	else if (keycode == 13)
		up(prg);
	else if (keycode == 1)
		down(prg);
	else if (keycode == 122)
		prg->player.use_mouse *= -1;
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

int	mouse_move(int x, int y, t_prg *prg)
{
	if (prg->player.use_mouse == 1)
	{
		if (x < prg->player.x_mouse_pos)
			rotate_left_w_mouse(prg);
		if (x > prg->player.x_mouse_pos)
			rotate_right_w_mouse(prg);
		check_mouse_pos(prg, x, y);
		mlx_mouse_hide();
	}
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
	prg->player.move_speed = (1 / (time_sec * 1000)) * 5;
	prg->player.rotation_speed = (1 / (time_sec * 1000)) * 2;
	str = ft_itoa(1 / time_sec);
	mlx_string_put(prg->win.mlx, prg->win.win, 15, 15, 0xFFFFFF, str);
	mlx_string_put(prg->win.mlx, prg->win.win, 50, 15, 0xFFFFFF, "fps");
	if (prg->player.use_mouse == -1)
		mlx_mouse_show();
	free(str);
	return (0);
}
