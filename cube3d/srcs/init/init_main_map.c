/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:47:59 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 11:46:14 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static void	fill_with_2(t_prg *prg, int y, int x)
{
	while (x < prg->parser.width)
	{
		prg->world_map[y][x] = 2;
		x++;
	}
}

static bool	fill_world_map(t_prg *prg)
{
	int		x;
	int		y;
	t_list	*tmp;

	y = 0;
	while (y < prg->parser.height)
	{
		x = 0;
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
		fill_with_2(prg, y, x);
		tmp = prg->lst;
		prg->lst = prg->lst->next;
		ft_lstdelone(tmp, free);
		y++;
	}
	return (true);
}

static bool	check_pos(t_prg *prg, int y, int *x, int player_check)
{
	if (is_valid_position(prg, *x, y) == false)
		return (ft_error(false, 1, "Map not surrended by wall"));
	if (prg->world_map[y][*x] != 1 && prg->world_map[y][*x] != 0
		&& prg->world_map[y][*x] != 2 && player_check == 1)
	{
		if (position_player(prg->world_map[y][*x], *x, y, prg) == false)
			return (ft_error(false, 1,
					"Map invalid use: 0, 1, ' ', N, S, W, E"));
		prg->parser.pos_player += 1;
		prg->world_map[y][*x] = 0;
	}
	*x += 1;
	return (true);
}

bool	is_valid_map(t_prg *prg, int player_check)
{
	int	x;
	int	y;

	y = 0;
	while (y < prg->parser.height)
	{
		x = 0;
		while (x < prg->parser.width)
			if (check_pos(prg, y, &x, player_check) == false)
				return (false);
		y++;
	}
	if ((prg->parser.pos_player > 1
			|| prg->parser.pos_player == 0) && player_check == 1)
		return (ft_error(false, 1, "Wrong player position"));
	return (true);
}

bool	init_map(t_prg *prg)
{
	int		x;

	x = 0;
	prg->world_map = malloc(sizeof(int *) * prg->parser.height);
	if (!prg->world_map)
		return (false);
	while (x < prg->parser.height)
	{
		prg->world_map[x] = malloc(sizeof(int) * prg->parser.width);
		if (prg->world_map[x] == NULL)
		{
			free_world_map(prg->world_map, x);
			return (false);
		}
		x++;
	}
	if (fill_world_map(prg) == false)
		return (false);
	if (is_valid_map(prg, 1) == false)
		return (false);
	init_edition_map_var(prg);
	init_edition_map_var2(prg);
	init_mini_map(prg);
	return (true);
}
