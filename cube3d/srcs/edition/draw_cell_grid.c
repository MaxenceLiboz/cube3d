/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cell_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:24:37 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/03 15:41:49 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	x -= prg->map.center.x;
	y -= prg->map.center.y;
	cell_pos.x = x / prg->map.cell_size
		+ (prg->map.end_point.x - prg->map.max_cell_width);
	cell_pos.y = y / prg->map.cell_size
		+ (prg->map.end_point.y - prg->map.max_cell_height);
	if (cell_pos.x >= prg->parser.width || cell_pos.y >= prg->parser.height
		|| cell_pos.x < 0 || cell_pos.y < 0)
		return ;
	if (prg->edition.mouse_keycode == 2 && ((int)prg->player.x_pos != cell_pos.x
			|| (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 0;
	else if (prg->edition.mouse_keycode == 1 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 1;
	else if (prg->edition.mouse_keycode == 3 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 2;
}

static void	get_circle_position(t_prg *prg, t_map *map)
{
	t_point	pt1;

	pt1.x = 0;
	pt1.y = 0;
	if (map->cell_size != 10 && (int)prg->player.x_pos == map->x_map
		&& (int)prg->player.y_pos == map->y_map)
	{
		pt1.x = prg->player.x_pos * map->cell_size
				+ map->center.x - ((map->end_point.x
					- map->max_cell_width) * map->cell_size);
		pt1.y = prg->player.y_pos * map->cell_size
			+ map->center.y - ((map->end_point.y
					- map->max_cell_height) * map->cell_size);	
	}
	// else
	// {

	// 	pt1.x = (prg->player.x_pos - (prg->player.x_pos - prg->map.max_cell_width)) * prg->mini_map.cell_size;
	// 	pt1.y = prg->player.y_pos * map->cell_size;
	// }
	draw_circle(&prg->img, pt1);
}

static void	cell_up(t_prg *prg, t_point pt1, t_point pt2,
	t_map *map)
{
	if (prg->world_map[map->y_map][map->x_map] == 0)
	{
		if (is_valid_position(prg, map->x_map, map->y_map) == true)
		{
			draw_square_cell(prg, pt1, pt2, BLACK);
			get_circle_position(prg, map);
		}
		else
			draw_square_cell(prg, pt1, pt2, RED);
	}
	else if (prg->world_map[map->y_map][map->x_map] == 1)
		draw_square_cell(prg, pt1, pt2, BLUE);
	else
		draw_square_cell(prg, pt1, pt2, GREEN);
}


void	draw_new_map(t_prg *prg)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	prg->map.y_map = prg->map.end_point.y - prg->map.max_cell_height;
	while (y < prg->parser.height && y < prg->map.max_cell_height
		&& prg->map.y_map < prg->parser.height)
	{
		prg->map.x_map = prg->map.end_point.x - prg->map.max_cell_width;
		while (x < prg->parser.width && x < prg->map.max_cell_width
			&& prg->map.x_map < prg->parser.width)
		{
			prg->map.pt1.x = x * prg->map.cell_size + prg->map.center.x;
			prg->map.pt1.y = y * prg->map.cell_size + prg->map.center.y;
			prg->map.pt2.x = prg->map.pt1.x + prg->map.cell_size;
			prg->map.pt2.y = prg->map.pt1.y + prg->map.cell_size;
			cell_up(prg, prg->map.pt1, prg->map.pt2, &prg->map);
			x++;
			prg->map.x_map++;
		}
		y++;
		prg->map.y_map++;
		x = 0;
	}
}

void	draw_new_mini_map(t_prg *prg, int x, int y)
{
	prg->mini_map.y_map = prg->player.y_pos - (prg->map.max_cell_height / 2);
	if (prg->mini_map.y_map < 0)
		prg->mini_map.y_map = 0;
	if (prg->mini_map.y_map + prg->map.max_cell_height > prg->parser.height)
			prg->mini_map.y_map = prg->parser.height - prg->map.max_cell_height;
	while (++y < prg->parser.height && y < prg->map.max_cell_height 
		&& prg->mini_map.y_map < prg->parser.height)
	{
		prg->mini_map.x_map = prg->player.x_pos - (prg->map.max_cell_width / 2);
		if (prg->mini_map.x_map < 0)
			prg->mini_map.x_map = 0;
		if (prg->mini_map.x_map + prg->map.max_cell_width > prg->parser.width)
			prg->mini_map.x_map = prg->parser.width - prg->map.max_cell_width;
		while (++x < prg->parser.width && x < prg->map.max_cell_width
			&& prg->mini_map.x_map < prg->parser.width)
		{
			prg->mini_map.pt1.x = x * prg->map.cell_size;
			prg->mini_map.pt1.y = y * prg->map.cell_size;
			prg->mini_map.pt2.x = prg->mini_map.pt1.x + prg->map.cell_size;
			prg->mini_map.pt2.y = prg->mini_map.pt1.y + prg->map.cell_size;
			cell_up(prg, prg->mini_map.pt1, prg->mini_map.pt2, &prg->mini_map);
			prg->mini_map.x_map++;
		}
		prg->mini_map.y_map++;
		x = -1;
	}
	prg->mini_map.pt1.x = (prg->player.x_pos - (prg->player.x_pos - prg->mini_map.max_cell_width / 2)) * prg->mini_map.cell_size;
		
	prg->mini_map.pt1.y = (prg->player.y_pos - (prg->player.y_pos 
			- prg->mini_map.max_cell_height / 2)) * prg->mini_map.cell_size;
	// dprintf(2,"%d %d\n", prg->mini_map.x_map, prg->mini_map.y_map);
	draw_circle(&prg->img, prg->mini_map.pt1);
}
