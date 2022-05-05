/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:55:31 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/04 17:05:25 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	get_circle_position(t_prg *prg, t_map *map, int x_map)
{
	t_point	pt1;

	pt1.x = 0;
	pt1.y = 0;
	if (prg->edition_mode == 1 && (int)prg->player.x_pos == x_map
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
	else
		draw_square_cell(prg, pt1, pt2, GREEN);
	if (prg->edition_mode == 1)
		get_circle_position(prg, &prg->map, index->x);
}

void	draw_new_map(t_prg *prg)
{
	int			x;
	int			y;
	t_point		index;

	y = -1;
	prg->map.x_map = prg->map.end_point.x - prg->map.max_cell_width;
	prg->map.y_map = prg->map.end_point.y - prg->map.max_cell_height;
	while (++y < prg->parser.height && y < prg->map.max_cell_height
		&& prg->map.y_map < prg->parser.height)
	{
		x = 0;
		index.x = prg->map.x_map;
		index.y = prg->map.y_map;
		while (x < prg->parser.width && x < prg->map.max_cell_width
			&& index.x < prg->parser.width)
		{
			prg->map.pt1.x = x * prg->map.cell_size + prg->map.center.x;
			prg->map.pt1.y = y * prg->map.cell_size + prg->map.center.y;
			prg->map.pt2.x = prg->map.pt1.x + prg->map.cell_size;
			prg->map.pt2.y = prg->map.pt1.y + prg->map.cell_size;
			cell_up(prg, &prg->map.pt1, &prg->map.pt2, &index);
			x++;
			index.x++;
		}
		prg->map.y_map++;
	}
}
