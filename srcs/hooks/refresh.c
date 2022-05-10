/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:55:38 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:11:03 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int	time_diff(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000
		+ 1e-3 * (end.tv_usec - start.tv_usec));
}

static char	*get_fps(t_prg *prg, struct timeval start)
{
	double			time_sec;
	char			*str;

	time_sec = (double)time_diff(start) / 1000;
	prg->player.delta = time_sec;
	str = ft_itoa(1 / time_sec);
	if (str == NULL)
		exit(1);
	return (str);
}

int	refresh_map(t_prg *prg)
{
	struct timeval	start;
	char			*str;

	gettimeofday(&start, NULL);
	if (prg->edition_mode == false)
	{
		keys_mouvements(prg);
		mouse_mouvements(prg);
		create_main_map(prg, prg->world_map);
		if (prg->h_map.help_mode == true && prg->h_map.is_printable == false)
			print_help_map(prg);
		else if (prg->h_map.help_mode == false)
			hide_help_map(prg);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
		draw_help_to_image(prg);
		str = get_fps(prg, start);
		mlx_string_put(prg->win.mlx, prg->win.win, 1855, 15, 0xFFFFFF, str);
		mlx_string_put(prg->win.mlx, prg->win.win, 1880, 15, 0xFFFFFF, "fps");
		free(str);
	}
	return (0);
}

int	refresh_edition(t_prg *prg, int keycode)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
	{
		set_grid_cell(prg, prg->mouse.mouse_position.x,
			prg->mouse.mouse_position.y);
		clear_window(prg);
	}
	create_edition_map(prg);
	draw_vertical_line_grid(prg);
	draw_horizontal_line_grid(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->background.img, 0, 0);
	draw_image_top(prg);
	draw_image_bot(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	edition_mode_str(prg);
	return (0);
}
