/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_mouse_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:34:56 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:43:35 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static bool	new_cell_pos(t_prg *prg, int x, int y)
{
	t_point	old_pos;
	t_point	new_pos;

	old_pos.x = prg->mouse.mouse_position.x / prg->map.cell_size;
	old_pos.y = prg->mouse.mouse_position.y / prg->map.cell_size;
	new_pos.x = x / prg->map.cell_size;
	new_pos.y = y / prg->map.cell_size;
	prg->mouse.mouse_position.x = x;
	prg->mouse.mouse_position.y = y;
	if (old_pos.x == new_pos.x && old_pos.y == new_pos.y)
		return (false);
	return (true);
}

int	updated_mouse_pos(int x, int y, t_prg *prg)
{
	if (prg->edition_mode == true)
		if (prg->mouse.mouse_pressed == 1)
			if (new_cell_pos(prg, x, y) == true)
				refresh_edition(prg, 0);
	return (0);
}
