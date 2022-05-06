/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_edition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:36:23 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:36:53 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	refresh_edition(t_prg *prg, int keycode)
{
	if (keycode != 123 && keycode != 124 && keycode != 125 && keycode != 126)
		set_grid_cell(prg, prg->mouse.mouse_position.x,
			prg->mouse.mouse_position.y);
	draw_new_map(prg);
	draw_vertical_line_grid(prg);
	draw_horizontal_line_grid(prg);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win, prg->img.img, 0, 0);
	return (0);
}
