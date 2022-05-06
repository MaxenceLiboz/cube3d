/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:55:38 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 11:33:33 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	refresh_map(t_prg *prg)
{
	struct timeval	start;
	double			time_sec;
	char			*str;

	gettimeofday(&start, NULL);
	if (prg->edition_mode == false)
	{
		keys_mouvements(prg);
		mouse_mouvements(prg);
		prg->e_map.cell_size = 10;
		create_main_map(prg, prg->world_map);
		create_mini_map(prg);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
		time_sec = (double)time_diff(start) / 1000;
		prg->player.delta = time_sec;
		str = ft_itoa(1 / time_sec);
		if (str == NULL)
			exit(1);
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
	draw_info(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->background.img, 0, 0);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	indications_strings(prg);
	return (0);
}

