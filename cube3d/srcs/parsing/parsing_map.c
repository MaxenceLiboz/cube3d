/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:49:09 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/10 07:30:35 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	position_player(char position, int x, int y, t_prg *prg)
{
	prg->player.x_dir = 0;
	prg->player.y_dir = -1;
	prg->player.x_plane = 0.66;
	prg->player.y_plane = 0;
	if (position == 'E')
		rotation_matrix(prg, M_PI / 2);
	if (position == 'S')
		rotation_matrix(prg, M_PI);
	if (position == 'W')
		rotation_matrix(prg, -M_PI / 2);
	prg->player.x_pos = x + 0.5;
	prg->player.y_pos = y + 0.5;
	return (true);
}

void	free_world_map(int **world_map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(world_map[i]);
		i++;
	}
	free(world_map);
}

int	is_valid_position(t_prg *prg, int x, int y)
{
	if (prg->world_map[y][x] == 0 || prg->world_map[y][x] == 'N'
		|| prg->world_map[y][x] == 'E' || prg->world_map[y][x] == 'S'
		|| prg->world_map[y][x] == 'W')
	{
		if (x == 0 || x == prg->parser.width - 1 || y == 0
			|| y == prg->parser.height - 1)
			return (false);
		if (prg->world_map[y - 1][x] == 2 || prg->world_map[y + 1][x] == 2
			|| prg->world_map[y][x - 1] == 2 || prg->world_map[y][x + 1] == 2)
			return (false);
	}
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
	return (true);
}
