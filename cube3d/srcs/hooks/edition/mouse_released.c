/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_released.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:30:02 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:31:07 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	mouse_released(int keycode, int x, int y, t_prg *prg)
{
	(void)keycode;
	(void)x;
	(void)y;
	prg->mouse.mouse_pressed = 0;
	prg->mouse.mouse_keycode = 0;
	return (0);
}
