/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:55:26 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 11:00:16 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	get_mini_map_pos2(t_prg *prg, t_point *index)
{
	if (index->x < prg->e_map.max_cell_width / 2 && index->x > 0)
	{
		prg->m_map.x_map = 0;
		index->x = 0;
	}
	if (index->y < prg->e_map.max_cell_height / 2 && index->y > 0)
	{
		prg->m_map.y_map = 0;
		index->y = 0;
	}
}

static void	get_mini_map_pos(t_prg *prg, t_point *index)
{
	if ((int)prg->player.x_pos
		== (prg->m_map.x_map + prg->e_map.max_cell_width) - 1
		&& prg->m_map.x_map + (prg->e_map.max_cell_width / 2)
		<= prg->parser.width)
		prg->m_map.x_map += prg->e_map.max_cell_width / 2;
	else if ((int)prg->player.x_pos == (prg->m_map.x_map)
		&& prg->m_map.x_map - (prg->e_map.max_cell_width / 2) >= 0)
		prg->m_map.x_map -= (prg->e_map.max_cell_width / 2);
	index->x = prg->m_map.x_map;
	if ((int)prg->player.y_pos
		== (prg->m_map.y_map + prg->e_map.max_cell_height) - 1
		&& prg->m_map.y_map + (prg->e_map.max_cell_height / 2)
		<= prg->parser.height)
		prg->m_map.y_map += (prg->e_map.max_cell_height / 2);
	else if ((int)prg->player.y_pos == (prg->m_map.y_map)
		&& prg->m_map.y_map - (prg->e_map.max_cell_height / 2) >= 0)
		prg->m_map.y_map -= (prg->e_map.max_cell_height / 2);
	index->y = prg->m_map.y_map;
	get_mini_map_pos2(prg, index);
}

static void	print_ray_view(t_prg *prg, t_point pt1, int cell_size)
{
	int		x;
	t_point	pt2;

	x = 0;
	while (x < prg->win.width)
	{
		pt2.x = prg->m_map.pt1.x + (prg->dda.ray_dir_table[x][0]
				* ((prg->dda.ray_table[x]) * cell_size));
		pt2.y = prg->m_map.pt1.y + (prg->dda.ray_dir_table[x][1]
				* ((prg->dda.ray_table[x]) * cell_size));
		draw_rayline(&prg->img, pt1, pt2, RED);
		x++;
	}
}

static void	draw_mini_map_position(t_prg *prg)
{
	prg->m_map.pt1.x = (prg->player.x_pos - prg->m_map.x_map)
		* prg->e_map.cell_size;
	prg->m_map.pt1.y = (prg->player.y_pos - prg->m_map.y_map)
		* prg->e_map.cell_size;
	print_ray_view(prg, prg->m_map.pt1, prg->e_map.cell_size);
	draw_circle(&prg->img, prg->m_map.pt1);
}

void	create_mini_map(t_prg *prg)
{
	t_point	index_map;
	t_point	index;

	index.y = -1;
	get_mini_map_pos(prg, &index_map);
	while (++index.y < prg->parser.height && index.y
		< prg->e_map.max_cell_height && index_map.y < prg->parser.height)
	{
		index.x = -1;
		while (++index.x < prg->parser.width && index.x
			< prg->e_map.max_cell_width && index_map.x < prg->parser.width)
		{
			position_point(prg, &index);
			cell_up(prg, &prg->m_map.pt1, &prg->m_map.pt2, &index_map);
			index_map.x++;
		}
		index_map.x = prg->m_map.x_map;
		index_map.y++;
	}
	draw_mini_map_position(prg);
}
