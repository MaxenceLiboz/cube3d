/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:15:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/02 10:45:29 by tarchimb         ###   ########.fr       */
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
	if (keycode == 14)
	{
		if (prg->edition_mode == 0)
		{
			prg->map.cell_size = 40;
			prg->edition_mode = !prg->edition_mode;
			update(prg, keycode);
		}
		else if (prg->edition_mode == 1)
			is_valid_new_map(prg);
	}
	if (keycode == 53)
		exit_cube(prg);
	else if (keycode == 13 && prg->edition_mode == 0)
		up(prg);
	else if (keycode == 1 && prg->edition_mode == 0)
		down(prg);
	else if (keycode == 123)
	{
		if (prg->edition_mode == 0)
			left_rot(prg);
		if (prg->edition_mode == 1)
			update(prg, keycode);
	}
	else if (keycode == 124)
	{
		if (prg->edition_mode == 0)
			right_rot(prg);
		if (prg->edition_mode == 1)
			update(prg, keycode);
	}
	else if ((keycode == 125 || keycode == 126) && prg->edition_mode == 1)
		update(prg, keycode);
	else if (keycode == 0 && prg->edition_mode == 0)
		left(prg);
	else if (keycode == 2 && prg->edition_mode == 0)
		right(prg);
	else if (keycode == 24)
	{
		// prg->map.max_cell_width += 2;
		// prg->map.max_cell_height += 1;
		// prg->map.cell_size -=  1;
		// update(prg, keycode);
	}
	else if (keycode == 27)
	{
		//Dezoom
	}
	refresh(prg);
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
	if (prg->edition_mode == 0)
	{
		prg->map.cell_size = 10;
		write_map(prg, prg->world_map);
		draw_new_mini_map(prg);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
		time_sec = (double)time_diff(start) / 1000;
		str = ft_itoa(1 / time_sec);
		mlx_string_put(prg->win.mlx, prg->win.win, 15, 15, 0xFFFFFF, str);
		mlx_string_put(prg->win.mlx, prg->win.win, 50, 15, 0xFFFFFF, "fps");
		free(str);
	}
	return (0);
}
