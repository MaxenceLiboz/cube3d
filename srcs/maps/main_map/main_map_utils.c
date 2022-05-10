/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:37:58 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 14:17:16 by tarchimb         ###   ########.fr       */
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
	t_point	pt1;
	t_point	pt2;
	int		y;

	(void)x;
	pt1.x = x;
	pt2.x = prg->win.width;
	y = 0;
	while (y < prg->win.height / 2)
	{
		pt1.y = y;
		pt2.y = y;
		draw_line(&prg->img, pt1, pt2, color_lerp(GRAY,
				prg->draw.sky_color, ft_inv_lerp_d(0, prg->win.height / 2, y)));
		y++;
	}
	y = prg->win.height / 2;
	while (y < prg->win.height)
	{
		pt1.y = y;
		pt2.y = y;
		draw_line(&prg->img, pt1, pt2, color_lerp(prg->draw.floor_color,
				GRAY, ft_inv_lerp_d(prg->win.height / 2, prg->win.height, y)));
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
