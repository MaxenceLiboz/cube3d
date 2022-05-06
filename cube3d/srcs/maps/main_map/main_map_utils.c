/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:37:58 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 22:50:09 by tarchimb         ###   ########.fr       */
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

void	draw_background(int x, t_prg *prg)
{
	int		y;

	y = 0;
	while (y < prg->draw.draw_start_pixel)
	{
		my_mlx_pixel_put(&prg->img, x, y, prg->draw.sky_color);
		y++;
	}
	y = prg->draw.draw_end_pixel;
	while (y < prg->win.height)
	{
		my_mlx_pixel_put(&prg->img, x, y, prg->draw.floor_color);
		y++;
	}
}

static void	get_color(t_texture *texture, t_draw *draw, int index)
{
	char	*str;

	str = &texture[index].addr[draw->texture_y_pos * texture[index].line_length
		+ draw->texture_x_pos * (texture[index].bits_per_pixel / 8)];
	draw->color.ustr_color[0] = str[0];
	draw->color.ustr_color[1] = str[1];
	draw->color.ustr_color[2] = str[2];
	draw->color.ustr_color[3] = str[3];
}

void	draw_wall(t_prg *prg, int x)
{
	int		y;

	init_draw(prg, &prg->draw);
	y = prg->draw.draw_start_pixel;
	while (y < prg->draw.draw_end_pixel)
	{
		prg->draw.texture_y_pos = (int)prg->draw.texture_start_pos;
		get_color(prg->texture, &prg->draw, prg->draw.texture_index);
		my_mlx_pixel_put(&prg->img, x, y, prg->draw.color.uint_color);
		prg->draw.texture_start_pos += prg->draw.texture_step;
		y++;
	}
}
