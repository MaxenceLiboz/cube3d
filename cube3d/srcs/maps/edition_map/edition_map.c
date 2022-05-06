/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:55:31 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/07 00:35:06 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	set_grid_cell(t_prg *prg, int x, int y)
{
	t_point	cell_pos;

	x -= prg->e_map.center.x;
	y -= prg->e_map.center.y;
	cell_pos.x = x / prg->e_map.cell_size
		+ (prg->e_map.end_point.x - prg->e_map.max_cell_width);
	cell_pos.y = y / prg->e_map.cell_size
		+ (prg->e_map.end_point.y - prg->e_map.max_cell_height);
	if (cell_pos.x >= prg->parser.width || cell_pos.y >= prg->parser.height
		|| cell_pos.x < 0 || cell_pos.y < 0)
		return ;
	if (prg->mouse.mouse_keycode == 2 && ((int)prg->player.x_pos != cell_pos.x
			|| (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 0;
	else if (prg->mouse.mouse_keycode == 1 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 1;
	else if (prg->mouse.mouse_keycode == 3 && ((int)prg->player.x_pos
			!= cell_pos.x || (int)prg->player.y_pos != cell_pos.y))
		prg->world_map[cell_pos.y][cell_pos.x] = 2;
}

void	create_edition_map(t_prg *prg)
{
	t_point		index_map;
	t_point		index;

	index.y = -1;
	prg->e_map.x_map = prg->e_map.end_point.x - prg->e_map.max_cell_width;
	prg->e_map.y_map = prg->e_map.end_point.y - prg->e_map.max_cell_height;
	while (++index.y < prg->parser.height && index.y
		< prg->e_map.max_cell_height && prg->e_map.y_map < prg->parser.height)
	{
		index.x = 0;
		index_map.x = prg->e_map.x_map;
		index_map.y = prg->e_map.y_map;
		while (index.x < prg->parser.width && index.x
			< prg->e_map.max_cell_width && index_map.x < prg->parser.width)
		{
			position_point(prg, &index);
			cell_up(prg, &prg->e_map.pt1, &prg->e_map.pt2, &index_map);
			index.x++;
			index_map.x++;
		}
		prg->e_map.y_map++;
	}
}
