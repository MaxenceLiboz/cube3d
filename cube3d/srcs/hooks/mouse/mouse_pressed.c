/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pressed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:29:10 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 23:30:56 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	mouse_pressed(int keycode, int x, int y, t_prg *prg)
{
	(void)keycode;
	if (prg->edition_mode == true)
	{
		prg->mouse.mouse_pressed = 1;
		prg->mouse.mouse_position.x = x;
		prg->mouse.mouse_position.y = y;
		prg->mouse.mouse_keycode = keycode;
		refresh_edition(prg, keycode);
	}
	return (0);
}
