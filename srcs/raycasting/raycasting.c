/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:20:03 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 15:01:06 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;
	int		pixel;

	pixel = (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (pixel < 0)
		return ;
	dst = data->addr + pixel;
	*(unsigned int *)dst = color;
}

void	get_color(t_texture *texture, t_draw *draw, int index)
{
	char	*str;

	str = &texture[index].addr[draw->texture_y_pos * texture[index].line_length
		+ draw->texture_x_pos * (texture[index].bits_per_pixel / 8)];
	draw->color.ustr_color[0] = str[0];
	draw->color.ustr_color[1] = str[1];
	draw->color.ustr_color[2] = str[2];
	draw->color.ustr_color[3] = str[3];
}

void	draw_img(t_prg *prg, int x)
{
	t_draw	draw;
	int		y;

	init_draw(&draw, prg->dda, prg->win, prg->texture);
	y = draw.draw_start_pixel;
	while (y < draw.draw_end_pixel)
	{
		draw.texture_y_pos = (int)draw.texture_start_pos
			& (prg->texture[draw.texture_index].height - 1);
		get_color(prg->texture, &draw, draw.texture_index);
		my_mlx_pixel_put(&prg->img, x, y, draw.color.uint_color);
		draw.texture_start_pos += draw.texture_step;
		if (x == prg->win.width / 2)
		{
			my_mlx_pixel_put(&prg->img, x, y, 0x000000);
			if (y == draw.draw_end_pixel - 1)
			{
				dprintf(2, "Wall dist: %f\n", prg->dda.wall_dist);
				dprintf(2, "%d\n", draw.color.uint_color);
			}
		}
		y++;
	}
}

void	write_map(t_prg *prg, int world_map[24][24])
{
	int		x;

	x = 0;
	while (x < prg->win.width)
	{
		init_dda(&prg->player, prg->win, &prg->dda, x);
		perform_dda(&prg->dda, world_map);
		draw_img(prg, x);
		x++;
	}
}
