/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:47 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:19:07 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structure.h"

/***************** UTILS **********************/
int		position_player(char position, int x, int y, t_prg *prg);
void	free_world_map(int **world_map, int size);
int		is_valid_position(t_prg *prg, int x, int y);
bool	parsing(t_prg *prg, char **argv, int argc);

/***************** FILE ***********************/
int		fill_background(char *line, t_prg *prg);
bool	is_background(char *line);
bool	is_color_num(char **str);
bool	cub_extension(char *file_path);
bool	parse_file(char *file_path, t_prg *prg);
bool	fill_texture(char *line, t_prg *prg);
bool	check_texture_and_color_init(t_texture *texture, t_draw draw);
bool	is_texture(char *line);
bool	init_texture(t_win window, t_texture *texture, char *filename);

#endif