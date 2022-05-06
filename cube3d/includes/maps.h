/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:45 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:19:03 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "structure.h"

/***************** MINI_MAP **********************/
void	position_point(t_prg *prg, t_point *index);
void	cell_up(t_prg *prg, t_point *pt1, t_point *pt2, t_point *index);

/***************** EDITION_MAP *******************/
void	set_grid_cell(t_prg *prg, int x, int y);
void	create_edition_map(t_prg *prg);
void	draw_info(t_prg *prg);
void	indications_strings(t_prg *prg);
void	is_valid_new_map(t_prg *prg);

/***************** MAIN_MAP **********************/
void	draw_cross(t_prg *prg);
void	draw_background(int x, t_prg *prg);
void	draw_wall(t_prg *prg, int x);
void	create_main_map(t_prg *prg, int **world_map);

/***************** MINI_MAP **********************/
void	create_mini_map(t_prg *prg);

#endif