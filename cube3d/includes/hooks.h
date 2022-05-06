/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:18:48 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "structure.h"


/***************** MAIN ********************/

void	mlx_hooks_management(t_prg *prg);
int		refresh_map(t_prg *prg);
int		refresh_edition(t_prg *prg, int keycode);

/***************** KEYS ********************/
int		exit_cube(t_prg *prg);
void	keys_mouvements(t_prg *prg);
int		keys_released(int keycode, t_prg *prg);
int		keys_pressed(int keycode, t_prg *prg);

/***************** MOUSE ********************/
void	mouse_mouvements(t_prg *prg);
int		updated_mouse_pos(int x, int y, t_prg *prg);
int		mouse_released(int keycode, int x, int y, t_prg *prg);
int		mouse_pressed(int keycode, int x, int y, t_prg *prg);

#endif