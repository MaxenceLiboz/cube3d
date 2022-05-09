/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:38 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/09 13:21:16 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structure.h"

void	init_edition_map_var(t_prg *prg);
void	init_edition_map_var2(t_prg *prg);
bool	is_valid_map(t_prg *prg, int player_check);
bool	init_map(t_prg *prg);
void	init_mini_map(t_prg *prg);
bool	window_init(t_win *window);
bool	img_init(t_win window, t_data *img);

#endif