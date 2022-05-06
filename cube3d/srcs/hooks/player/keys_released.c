/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_released.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:15:30 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:16:01 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	keys_released(int keycode, t_prg *prg)
{
	if (keycode == KEY_W)
		prg->player.keyboard[KEY_W_TAB] = 0;
	else if (keycode == KEY_S)
		prg->player.keyboard[KEY_S_TAB] = 0;
	else if (keycode == KEY_A)
		prg->player.keyboard[KEY_A_TAB] = 0;
	else if (keycode == KEY_D)
		prg->player.keyboard[KEY_D_TAB] = 0;
	else if (keycode == KEY_LEFT)
		prg->player.keyboard[KEY_LEFT_TAB] = 0;
	else if (keycode == KEY_RIGHT)
		prg->player.keyboard[KEY_RIGHT_TAB] = 0;
	return (0);
}
