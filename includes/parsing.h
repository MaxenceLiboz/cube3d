/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:47 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:40:57 by tarchimb         ###   ########.fr       */
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
bool	help_texture(t_prg *prg);

/***************** INIT ***********************/
void	init_edition_map_var(t_prg *prg);
void	init_edition_map_var2(t_prg *prg);
bool	is_valid_map(t_prg *prg, int player_check);
bool	init_map(t_prg *prg);
void	init_mini_map(t_prg *prg);
bool	window_init(t_win *window);
bool	img_init(t_win window, t_data *img);
bool	is_valid_map_char(int position);

#endif