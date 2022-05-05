/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:55:26 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/05 12:07:10 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_map_pos_init(t_prg *prg)
{
	prg->mini_map.cell_size = 10;
	prg->mini_map.x_map = prg->player.x_pos - (prg->map.max_cell_width / 2);
	if (prg->mini_map.x_map < 0)
		prg->mini_map.x_map = 0;
	if (prg->mini_map.x_map + prg->map.max_cell_width > prg->parser.width)
		prg->mini_map.x_map = prg->parser.width - prg->map.max_cell_width;
	prg->mini_map.y_map = prg->player.y_pos - (prg->map.max_cell_height / 2);
	if (prg->mini_map.y_map < 0)
		prg->mini_map.y_map = 0;
	if (prg->mini_map.y_map + prg->map.max_cell_height > prg->parser.height)
			prg->mini_map.y_map = prg->parser.height - prg->map.max_cell_height;
}

void	get_map_pos(t_prg *prg, t_point *index)
{
	if ((int)prg->player.x_pos
		== (prg->mini_map.x_map + prg->map.max_cell_width) - 1
		&& prg->mini_map.x_map + (prg->map.max_cell_width / 2)
		<= prg->parser.width)
		prg->mini_map.x_map += prg->map.max_cell_width / 2;
	else if ((int)prg->player.x_pos == (prg->mini_map.x_map)
		&& prg->mini_map.x_map - (prg->map.max_cell_width / 2) >= 0)
		prg->mini_map.x_map -= (prg->map.max_cell_width / 2);
	index->x = prg->mini_map.x_map;
	if ((int)prg->player.y_pos
		== (prg->mini_map.y_map + prg->map.max_cell_height) - 1
		&& prg->mini_map.y_map + (prg->map.max_cell_height / 2)
		<= prg->parser.height)
		prg->mini_map.y_map += (prg->map.max_cell_height / 2);
	else if ((int)prg->player.y_pos == (prg->mini_map.y_map)
		&& prg->mini_map.y_map - (prg->map.max_cell_height / 2) >= 0)
		prg->mini_map.y_map -= (prg->map.max_cell_height / 2);
	index->y = prg->mini_map.y_map;
}

static void	draw_position(t_prg *prg)
{
	prg->mini_map.pt1.x = (prg->player.x_pos - prg->mini_map.x_map)
		* prg->mini_map.cell_size;
	prg->mini_map.pt1.y = (prg->player.y_pos - prg->mini_map.y_map)
		* prg->mini_map.cell_size;
	draw_circle(&prg->img, prg->mini_map.pt1);
}

void	draw_new_mini_map(t_prg *prg)
{
	t_point	index_map;
	t_point	index;

	index.y = -1;
	get_map_pos(prg, &index_map);
	while (++index.y < prg->parser.height && index.y < prg->map.max_cell_height
		&& index_map.y < prg->parser.height)
	{
		index.x = -1;
		while (++index.x < prg->parser.width && index.x < prg->map.max_cell_width
			&& index_map.x < prg->parser.width)
		{
			position_point(prg, &index);
			cell_up(prg, &prg->mini_map.pt1, &prg->mini_map.pt2, &index_map);
			index_map.x++;
		}
		index_map.x = prg->mini_map.x_map;
		index_map.y++;
	}
	draw_position(prg);
}
