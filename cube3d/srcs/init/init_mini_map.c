/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:43:01 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 23:31:21 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	init_mini_map(t_prg *prg)
{
	prg->e_map.cell_size = 10;
	prg->m_map.x_map = prg->player.x_pos - (prg->e_map.max_cell_width / 2);
	if (prg->m_map.x_map < 0)
		prg->m_map.x_map = 0;
	if (prg->m_map.x_map + prg->e_map.max_cell_width > prg->parser.width)
		prg->m_map.x_map = prg->parser.width - prg->e_map.max_cell_width;
	prg->m_map.y_map = prg->player.y_pos - (prg->e_map.max_cell_height / 2);
	if (prg->m_map.y_map < 0)
		prg->m_map.y_map = 0;
	if (prg->m_map.y_map + prg->e_map.max_cell_height > prg->parser.height)
			prg->m_map.y_map = prg->parser.height - prg->e_map.max_cell_height;
}
