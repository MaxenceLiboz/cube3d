/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:48:36 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/04 15:51:37 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	position_player(char position, int x, int y, t_prg *prg)
{
	prg->player.x_dir = 0;
	prg->player.y_dir = -1;
	prg->player.x_plane = 0.66;
	prg->player.y_plane = 0;
	if (position == 'E')
		rotation_matrix(prg, 2);
	if (position == 'S')
		rotation_matrix(prg, 1);
	if (position == 'W')
		rotation_matrix(prg, -2);
	prg->player.x_pos = x + 0.5;
	prg->player.y_pos = y + 0.5;
	return (true);
}

int	is_valid_position(t_prg *prg, int x, int y)
{
	if (prg->world_map[y][x] == 0)
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

void	fill_with_2(t_prg *prg, int y, int x)
{
	while (x < prg->parser.width)
	{
		prg->world_map[y][x] = 2;
		x++;
	}
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
