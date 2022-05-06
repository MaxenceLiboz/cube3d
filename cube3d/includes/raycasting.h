/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:50 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:19:10 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "structure.h"

void	init_draw(t_prg *prg, t_draw *draw);
void	init_dda(t_player *player, t_win window, t_dda *dda, int x);
void	perform_dda(t_prg *prg, t_dda *dda, int **world_map);

#endif