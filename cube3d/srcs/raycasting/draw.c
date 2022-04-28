/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/raycasting/raycasting.c
/*   Created: 2022/04/26 08:20:03 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 14:34:18 by tarchimb         ###   ########.fr       */
=======
/*   Created: 2022/04/27 09:02:14 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 08:25:53 by mliboz           ###   ########.fr       */
>>>>>>> 86f6068c1dc06de6414c0d8f0375bcf26792ef1b:cube3d/srcs/raycasting/draw.c
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

static void	draw_background(int x, t_prg *prg)
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

void	draw_img(t_prg *prg, int x)
{
	int		y;

	init_draw(prg, &prg->draw);
	y = prg->draw.draw_start_pixel;
	while (y < prg->draw.draw_end_pixel)
	{
		prg->draw.texture_y_pos = (int)prg->draw.texture_start_pos
			& (prg->texture[prg->draw.texture_index].height - 1);
		get_color(prg->texture, &prg->draw, prg->draw.texture_index);
		my_mlx_pixel_put(&prg->img, x, y, prg->draw.color.uint_color);
		prg->draw.texture_start_pos += prg->draw.texture_step;
		y++;
	}
<<<<<<< HEAD:srcs/raycasting/raycasting.c
}

void	write_map(t_prg *prg, int **world_map)
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
=======
	draw_background(x, prg);
>>>>>>> 86f6068c1dc06de6414c0d8f0375bcf26792ef1b:cube3d/srcs/raycasting/draw.c
}
