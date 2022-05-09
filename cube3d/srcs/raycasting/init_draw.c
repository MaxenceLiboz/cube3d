/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 09:42:40 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 12:59:10 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	get_texture_x_pos(t_draw *draw, t_prg *prg, int i)
{
	if (prg->dda.side == 0)
		draw->wall_hit_pos = prg->player.y_pos + prg->dda.wall_dist
			* prg->dda.y_ray_direction;
	else
		draw->wall_hit_pos = prg->player.x_pos + prg->dda.wall_dist
			* prg->dda.x_ray_direction;
	draw->wall_hit_pos -= floor((draw->wall_hit_pos));
	draw->texture_x_pos = (int)(draw->wall_hit_pos * (prg->texture[i].width));
	if (prg->dda.side == 0 && prg->dda.x_ray_direction > 0)
		draw->texture_x_pos = prg->texture[i].width - draw->texture_x_pos - 1;
	if (prg->dda.side == 1 && prg->dda.y_ray_direction < 0)
		draw->texture_x_pos = prg->texture[i].width - draw->texture_x_pos - 1;
}

static void	get_start_end_pixel(t_draw *draw, t_win window, t_dda dda)
{
	draw->line_height = (int)(window.height / dda.wall_dist);
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
		draw->texture_index = 0;
	else if (dda.side == 0 && (int)dda.x_step == -1)
		draw->texture_index = 1;
	else if (dda.side == 1 && (int)dda.y_step == -1)
		draw->texture_index = 2;
	else if (dda.side == 1 && (int)dda.y_step == 1)
		draw->texture_index = 3;
}

void	init_draw(t_prg *prg, t_draw *draw)
{
	get_start_end_pixel(draw, prg->win, prg->dda);
	get_texture_index(draw, prg->dda);
	get_texture_x_pos(draw, prg, prg->draw.texture_index);
	draw->texture_step = 1.0 * prg->texture[draw->texture_index].height
		/ draw->line_height;
	draw->texture_start_pos = (draw->draw_start_pixel - prg->win.height / 2
			+ draw->line_height / 2) * draw->texture_step;
}
