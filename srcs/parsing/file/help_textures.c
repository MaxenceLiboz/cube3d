/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:34:38 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 23:38:30 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	help_texture2(t_prg *prg)
{
	if (!init_texture(prg->win, &prg->help_keys[KEY_UP_TAB],
			"./pics/key_up.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_DOWN_TAB],
			"./pics/key_down.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_H_TAB],
			"./pics/key_h.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_E_TAB],
			"./pics/key_e.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_RMB_TAB],
			"./pics/RMB.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_LMB_TAB],
			"./pics/LMB.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_CMB_TAB],
			"./pics/CMB.xpm"))
		return (false);
	return (true);
}

bool	help_texture(t_prg *prg)
{
	if (!init_texture(prg->win, &prg->background, "./pics/background.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_W_TAB], "./pics/key_w.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_A_TAB], "./pics/key_a.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_S_TAB], "./pics/key_s.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_D_TAB], "./pics/key_d.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_LEFT_TAB],
			"./pics/key_left.xpm"))
		return (false);
	if (!init_texture(prg->win, &prg->help_keys[KEY_RIGHT_TAB],
			"./pics/key_right.xpm"))
		return (false);
	if (!help_texture2(prg))
		return (false);
	return (true);
}
