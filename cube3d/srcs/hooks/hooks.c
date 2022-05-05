/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:15:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 14:20:26 by mliboz           ###   ########.fr       */
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
static int	edition_key_code(int keycode, t_prg *prg)
{
	if (keycode == 14)
		is_valid_new_map(prg);
	else if (keycode == 123)
	{
		if (prg->map.end_point.x - prg->map.max_cell_width > 0)
			prg->map.end_point.x -= 1;
	}
	else if (keycode == 124)
	{
		if (prg->map.end_point.x < prg->parser.width)
				prg->map.end_point.x += 1;
	}
	else if (keycode == 125 && prg->map.end_point.y < prg->parser.height)
		prg->map.end_point.y += 1;
	else if (keycode == 126 && prg->map.end_point.y - prg->map.max_cell_height
		> 0)
		prg->map.end_point.y -= 1;
	if (keycode != 14)
		update(prg, keycode);
	return (0);
}

int	key_released(int keycode, t_prg *prg)
{
	if (keycode == KEY_W)
		prg->player.keyboard[KEY_W_TAB] = 0;
	else if (keycode == KEY_S)
		prg->player.keyboard[KEY_S_TAB] = 0;
	else if (keycode == KEY_A)
		prg->player.keyboard[KEY_A_TAB] = 0;
	else if (keycode == KEY_D)
		prg->player.keyboard[KEY_D_TAB] = 0;
	else if (keycode == KEY_LEFT)
		prg->player.keyboard[KEY_LEFT_TAB] = 0;
	else if (keycode == KEY_RIGHT)
		prg->player.keyboard[KEY_RIGHT_TAB] = 0;
	// printf("RELEASE: %d\n", keycode);
	return (0);
}

int	key_pressed(int keycode, t_prg *prg)
{
	// printf("PRESS: %d\n", keycode);
	if (keycode == 53)
		exit_cube(prg);
	if (prg->edition_mode == true)
		edition_key_code(keycode, prg);
	else
	{
		if (keycode == KEY_W)
			prg->player.keyboard[KEY_W_TAB] = 1;
		else if (keycode == KEY_S)
			prg->player.keyboard[KEY_S_TAB] = 1;
		else if (keycode == KEY_A)
			prg->player.keyboard[KEY_A_TAB] = 1;
		else if (keycode == KEY_D)
			prg->player.keyboard[KEY_D_TAB] = 1;
		else if (keycode == KEY_LEFT)
			prg->player.keyboard[KEY_LEFT_TAB] = 1;
		else if (keycode == KEY_RIGHT)
			prg->player.keyboard[KEY_RIGHT_TAB] = 1;
		if (keycode == 14)
		{
			prg->map.cell_size = 40;
			prg->edition_mode = !prg->edition_mode;
			update(prg, keycode);
		}
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

void	move_player(t_prg *prg)
{
	if (prg->player.keyboard[KEY_W_TAB] == 1)
		up(prg);
	if (prg->player.keyboard[KEY_S_TAB] == 1)
		down(prg);
	if (prg->player.keyboard[KEY_A_TAB] == 1)
		left(prg);
	if (prg->player.keyboard[KEY_D_TAB] == 1)
		right(prg);
	if (prg->player.keyboard[KEY_LEFT_TAB] == 1)
		left_rot(prg);
	if (prg->player.keyboard[KEY_RIGHT_TAB] == 1)
		right_rot(prg);
}

int	refresh(t_prg *prg)
{
	struct timeval	start;
	double			time_sec;
	char			*str;

	gettimeofday(&start, NULL);
	if (prg->edition_mode == false)
	{
		move_player(prg);
		prg->map.cell_size = 10;
		write_map(prg, prg->world_map);
		draw_new_mini_map(prg);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
		time_sec = (double)time_diff(start) / 1000;
		prg->player.delta = time_sec;
		str = ft_itoa(1 / time_sec);
		mlx_string_put(prg->win.mlx, prg->win.win, 1855, 15, 0xFFFFFF, str);
		mlx_string_put(prg->win.mlx, prg->win.win, 1880, 15, 0xFFFFFF, "fps");
		free(str);
	}
	return (0);
}
