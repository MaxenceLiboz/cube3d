/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:36:20 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 11:39:19 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	init_edition_map_var(t_prg *prg)
{
	prg->edition_mode = false;
	prg->e_map.cell_size = 40;
	if (prg->parser.width <= 40)
		prg->e_map.max_cell_width = prg->parser.width;
	else
		prg->e_map.max_cell_width = 40;
	if (prg->parser.height <= 20)
		prg->e_map.max_cell_height = prg->parser.height;
	else
		prg->e_map.max_cell_height = 20;
}

void	init_edition_map_var2(t_prg *prg)
{
	if (prg->parser.height <= prg->e_map.max_cell_height)
		prg->e_map.center.y = (prg->win.height / 2) - ((prg->parser.height / 2)
				* prg->e_map.cell_size);
	else
		prg->e_map.center.y = (prg->win.height / 2)
			- ((prg->e_map.max_cell_height / 2) * prg->e_map.cell_size);
	if (prg->parser.width <= prg->e_map.max_cell_width)
		prg->e_map.center.x = (prg->win.width / 2) - ((prg->parser.width / 2)
				* prg->e_map.cell_size);
	else
		prg->e_map.center.x = (prg->win.width / 2)
			- ((prg->e_map.max_cell_width / 2) * prg->e_map.cell_size);
	if (prg->parser.height <= prg->e_map.max_cell_height)
		prg->e_map.end_point.y = prg->parser.height;
	else
		prg->e_map.end_point.y = prg->e_map.max_cell_height;
	if (prg->parser.width <= prg->e_map.max_cell_width)
		prg->e_map.end_point.x = prg->parser.width;
	else
		prg->e_map.end_point.x = prg->e_map.max_cell_width;
}
