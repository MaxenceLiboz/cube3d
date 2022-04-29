/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:49:09 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 18:40:40 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	position_player(char position, int x, int y, t_prg *prg)
{
	if (position == 'N')
	{
		prg->player.x_dir = -1;
		prg->player.y_dir = 0;
		prg->player.x_plane = 0;
		prg->player.y_plane = 0.66;
	}
	else if (position == 'S')
	{
		prg->player.x_dir = 1;
		prg->player.y_dir = 0;
		prg->player.x_plane = 0;
		prg->player.y_plane = -0.66;
	}
	else if (position == 'W')
	{
		prg->player.x_dir = 0;
		prg->player.y_dir = 1;
		prg->player.x_plane = 0.66;
		prg->player.y_plane = 0;
	}
	else if (position == 'E')
	{
		prg->player.x_dir = 0;
		prg->player.y_dir = 1;
		prg->player.x_plane = -0.66;
		prg->player.y_plane = 0;
	}
	else
		return (false);
	prg->player.x_pos = x;
	prg->player.y_pos = y;
	return (true);
}

int	is_valid_position(t_prg *prg, int x, int y)
{
	// dprintf(2,"%d %d %d %d\n", x, y, prg->parser.width, prg->parser.height);
	if (x == 0 || x == prg->parser.width - 1 || y == 0 || y == prg->parser.height - 1)
		return (false);
	if (prg->world_map[y - 1][x] == 2 || prg->world_map[y + 1][x] == 2 
		|| prg->world_map[y][x - 1] == 2 || prg->world_map[y][x + 1] == 2)
		return (false);
	return (true);
}

static void	fill_world_map(t_prg *prg)
{
	int		x;
	int		y;
	t_list	*tmp;

	x = 0;
	y = 0;
	while (y < prg->parser.height)
	{
		while (prg->lst->len--)
		{
			if (prg->lst->content[x] == '1' || prg->lst->content[x] == '0')
				prg->world_map[y][x] = prg->lst->content[x] - '0';
			else if (prg->lst->content[x] == ' ')
				prg->world_map[y][x] = 2;
			else
				prg->world_map[y][x] = prg->lst->content[x];
			x++;
		}
		while (x < prg->parser.width)
		{
			prg->world_map[y][x] = 2;
			x++;
		}
		tmp = prg->lst;
		prg->lst = prg->lst->next;
		ft_lstdelone(tmp, free);
		x = 0;
		y++;
	}
}

static int	print_wrong_position(t_prg *prg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < prg->parser.height)
	{
		while (i < prg->parser.width)
		{
			if (is_valid_position(prg, i, j) == false && prg->world_map[j][i] == 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

bool	is_valid_map(t_prg *prg, int player_check)
{
	int	x;
	int	y;

	y = 0;
	prg->parser.pos_player = 0;
	while (y < prg->parser.height)
	{
		x = 0;
		while (x < prg->parser.width)
		{
			if (x == 32)
				dprintf(2,"%d\n", y);
			if (prg->world_map[y][x] == 0 && is_valid_position(prg, x, y) == false)
				return (false);
			if (prg->world_map[y][x] != 1 && prg->world_map[y][x] != 0 
				&& prg->world_map[y][x] != 2 && player_check == 1)
			{
				if (position_player(prg->world_map[y][x], x, y, prg) == false)
					return (false);
				prg->parser.pos_player += 1;
				prg->world_map[y][x] = 3;
			}
			x++;
		}
		y++;
	}
	print_wrong_position(prg);
	if ((prg->parser.pos_player > 1 || prg->parser.pos_player == 0) && player_check == 1)
	{
		dprintf(2, "Wrong");
		return (false);
	}
	return (true);
}

static bool	init_map(t_prg *prg)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	prg->parser.pos_player = 0;
	prg->world_map = malloc(sizeof(int *) * prg->parser.height);
	if (!prg->world_map)
		return (-1);
	while (x < prg->parser.height)
	{
		prg->world_map[x] = malloc(sizeof(int) * prg->parser.width);
		if (!prg->world_map)
		{
			//Free all
			return (-1);
		}
		x++;
	}
	fill_world_map(prg);
	is_valid_map(prg, 1);
	return (true);
}

bool	parsing(t_prg *prg, char **argv, int argc)
{
	prg->parser.height = 0;
	prg->parser.pos_player = 0;
	prg->parser.start = 0;
	prg->parser.width = 0;
	if (argc != 2)
		return (false);
	if (!parse_file(argv[1], prg))
		return (false);
	if (!init_map(prg))
		return (false);
	prg->player.move_speed = 0.2;
	prg->player.rotation_speed = 0.05;
	return (true);
}