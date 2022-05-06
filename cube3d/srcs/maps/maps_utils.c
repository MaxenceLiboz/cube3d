/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:36:12 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/07 00:35:09 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	position_point(t_prg *prg, t_point *index)
{
	if (prg->edition_mode == true)
	{
		prg->e_map.pt1.x = index->x * prg->e_map.cell_size
			+ prg->e_map.center.x;
		prg->e_map.pt1.y = index->y * prg->e_map.cell_size
			+ prg->e_map.center.y;
		prg->e_map.pt2.x = prg->e_map.pt1.x + prg->e_map.cell_size;
		prg->e_map.pt2.y = prg->e_map.pt1.y + prg->e_map.cell_size;
	}
	else
	{
		prg->m_map.pt1.x = index->x * prg->e_map.cell_size;
		prg->m_map.pt1.y = index->y * prg->e_map.cell_size;
		prg->m_map.pt2.x = prg->m_map.pt1.x + prg->e_map.cell_size;
		prg->m_map.pt2.y = prg->m_map.pt1.y + prg->e_map.cell_size;
	}
}

void	get_circle_position(t_prg *prg, t_edition_map *map, int x_map)
{
	t_point	pt1;

	pt1.x = 0;
	pt1.y = 0;
	if (prg->edition_mode == true && (int)prg->player.x_pos == x_map
		&& (int)prg->player.y_pos == map->y_map)
	{
		pt1.x = prg->player.x_pos * map->cell_size
			+ map->center.x - ((map->end_point.x
					- map->max_cell_width) * map->cell_size);
		pt1.y = prg->player.y_pos * map->cell_size
			+ map->center.y - ((map->end_point.y
					- map->max_cell_height) * map->cell_size);
		draw_circle(&prg->img, pt1);
	}
}

void	cell_up(t_prg *prg, t_point *pt1, t_point *pt2, t_point *index)
{
	if (prg->world_map[index->y][index->x] == 0)
	{
		if (is_valid_position(prg, index->x, index->y) == true)
			draw_square_cell(prg, pt1, pt2, BLACK);
		else
			draw_square_cell(prg, pt1, pt2, RED);
	}
	else if (prg->world_map[index->y][index->x] == 1)
		draw_square_cell(prg, pt1, pt2, BLUE);
	else if (prg->edition_mode == true)
		draw_square_cell(prg, pt1, pt2, BACKGROUND);
	if (prg->edition_mode == true)
		get_circle_position(prg, &prg->e_map, index->x);
}
