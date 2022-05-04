/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:49:09 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/04 15:55:24 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

bool	cub_extension(char *file_path)
{
	char	*extension;

	if (ft_strlen(file_path) < 6
		|| ft_isalnum(file_path[ft_strlen(file_path) - 5]) == false)
		return (false);
	extension = file_path + ft_strlen(file_path) - 4;
	if (ft_strncmp(extension, ".cub", 5) != 0)
		return (false);
	return (true);
}

bool	parsing(t_prg *prg, char **argv, int argc)
{
	prg->parser.height = 0;
	prg->parser.pos_player = 0;
	prg->parser.start = 0;
	prg->parser.width = 0;
	if (argc != 2)
		return (ft_error(false, 1, "Use: ./cube [MAP_PATH]"));
	if (cub_extension(argv[1]) == false)
		return (ft_error(false, 1, "Wrong map extension"));
	if (parse_file(argv[1], prg) == false)
		return (false);
	if (init_map(prg) == false)
		return (false);
	prg->player.move_speed = 0.2;
	prg->player.rotation_speed = 30;
	return (true);
}
