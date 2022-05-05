/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:36:20 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 11:12:35 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	init_map_variable(t_prg *prg)
{
	prg->edition_mode = false;
	prg->map.cell_size = 40;
	if (prg->parser.width <= 40)
		prg->map.max_cell_width = prg->parser.width;
	else
		prg->map.max_cell_width = 40;
	if (prg->parser.height <= 20)
		prg->map.max_cell_height = prg->parser.height;
	else
		prg->map.max_cell_height = 20;
}

void	init_map_variable2(t_prg *prg)
{
	if (prg->parser.height <= prg->map.max_cell_height)
		prg->map.center.y = (prg->win.height / 2) - ((prg->parser.height / 2)
				* prg->map.cell_size);
	else
		prg->map.center.y = (prg->win.height / 2)
			- ((prg->map.max_cell_height / 2) * prg->map.cell_size);
	if (prg->parser.width <= prg->map.max_cell_width)
		prg->map.center.x = (prg->win.width / 2) - ((prg->parser.width / 2)
				* prg->map.cell_size);
	else
		prg->map.center.x = (prg->win.width / 2)
			- ((prg->map.max_cell_width / 2) * prg->map.cell_size);
	if (prg->parser.height <= prg->map.max_cell_height)
		prg->map.end_point.y = prg->parser.height;
	else
		prg->map.end_point.y = prg->map.max_cell_height;
	if (prg->parser.width <= prg->map.max_cell_width)
		prg->map.end_point.x = prg->parser.width;
	else
		prg->map.end_point.x = prg->map.max_cell_width;
}
