/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:42:40 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 14:59:31 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	get_texture_x_pos(t_draw *draw, t_dda dda, t_texture *texture,
	t_win window)
{
	draw->line_height = (int)(window.height / dda.wall_dist);
	if (dda.side == 0)
		draw->wall_hit_pos = dda.y_map_pos + dda.wall_dist
			* dda.y_ray_direction;
	else
		draw->wall_hit_pos = dda.x_map_pos + dda.wall_dist
			* dda.x_ray_direction;
	draw->wall_hit_pos -= floor((draw->wall_hit_pos));
	draw->texture_x_pos = (int)(draw->wall_hit_pos * (texture[0].width));
	if (dda.side == 0 && dda.x_ray_direction > 0)
		draw->texture_x_pos = texture[0].width - draw->texture_x_pos - 1;
	if (dda.side == 1 && dda.y_ray_direction < 0)
		draw->texture_x_pos = texture[0].width - draw->texture_x_pos - 1;
}

static void	get_start_end_pixel(t_draw *draw, t_win window)
{
	draw->draw_start_pixel = -draw->line_height / 2 + window.height / 2;
	draw->draw_end_pixel = draw->line_height / 2 + window.height / 2;
	if (draw->draw_start_pixel < 0)
		draw->draw_start_pixel = 0;
	if (draw->draw_end_pixel >= window.height)
		draw->draw_end_pixel = window.height - 1;
}

/*
	Check if the wall hit is seen from North South WEST EAST respctivly in
	the if statement
*/
static void	get_texture_index(t_draw *draw, t_dda dda)
{
	if (dda.side == 0 && (int)dda.x_step == 1)
		draw->texture_index = 1;
	else if (dda.side == 0 && (int)dda.x_step == -1)
		draw->texture_index = 0;
	else if (dda.side == 1 && (int)dda.y_step == -1)
		draw->texture_index = 2;
	else if (dda.side == 1 && (int)dda.y_step == 1)
		draw->texture_index = 3;
}

void	init_draw(t_draw *draw, t_dda dda, t_win window, t_texture *texture)
{
	get_texture_x_pos(draw, dda, texture, window);
	get_start_end_pixel(draw, window);
	get_texture_index(draw, dda);
	draw->texture_step = 1.0 * texture[0].height
		/ draw->line_height;
	draw->texture_start_pos = (draw->draw_start_pixel - window.height / 2
			+ draw->line_height / 2) * draw->texture_step;
}
