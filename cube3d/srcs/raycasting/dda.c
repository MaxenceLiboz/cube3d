/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:59:10 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 11:16:21 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	get_step_and_init_side_dist(t_dda *dda, t_player *player)
{
	if (dda->x_ray_direction < 0)
	{
		dda->x_step = -1;
		dda->x_side_ray_dist = (player->x_pos - dda->x_map_pos)
			* dda->x_side_delta_ray_dist;
	}
	else
	{
		dda->x_step = 1;
		dda->x_side_ray_dist = (dda->x_map_pos + 1.0 - player->x_pos)
			* dda->x_side_delta_ray_dist;
	}
	if (dda->y_ray_direction < 0)
	{
		dda->y_step = -1;
		dda->y_side_ray_dist = (player->y_pos - dda->y_map_pos)
			* dda->y_side_delta_ray_dist;
	}
	else
	{
		dda->y_step = 1;
		dda->y_side_ray_dist = (dda->y_map_pos + 1.0 - player->y_pos)
			* dda->y_side_delta_ray_dist;
	}
}

void	init_dda(t_player *player, t_win window, t_dda *dda, int x)
{
	dda->x_camera = 2 * x / (double)window.width - 1;
	dda->x_ray_direction = player->x_dir + player->x_plane * dda->x_camera;
	dda->y_ray_direction = player->y_dir + player->y_plane * dda->x_camera;
	dda->x_map_pos = (int)player->x_pos;
	dda->y_map_pos = (int)player->y_pos;
	if (dda->x_ray_direction == 0)
		dda->x_side_delta_ray_dist = 1e30;
	else
		dda->x_side_delta_ray_dist = fabs(1 / dda->x_ray_direction);
	if (dda->y_ray_direction == 0)
		dda->y_side_delta_ray_dist = 1e30;
	else
		dda->y_side_delta_ray_dist = fabs(1 / dda->y_ray_direction);
	get_step_and_init_side_dist(dda, player);
}

void	perform_dda(t_prg *prg, t_dda *dda, int **world_map)
{
	bool	hit;

	hit = false;
	(void)prg;
	while (hit == false)
	{
		if (dda->x_side_ray_dist < dda->y_side_ray_dist)
		{
			dda->x_side_ray_dist += dda->x_side_delta_ray_dist;
			dda->x_map_pos += dda->x_step;
			dda->side = 0;
		}
		else
		{
			dda->y_side_ray_dist += dda->y_side_delta_ray_dist;
			dda->y_map_pos += dda->y_step;
			dda->side = 1;
		}
		if (world_map[dda->y_map_pos][dda->x_map_pos] > 0)
			hit = true;
	}
	if (dda->side == 0)
		dda->wall_dist = dda->x_side_ray_dist - dda->x_side_delta_ray_dist;
	else
		dda->wall_dist = dda->y_side_ray_dist - dda->y_side_delta_ray_dist;
}
