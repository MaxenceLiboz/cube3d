/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:49:09 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 15:06:40 by tarchimb         ###   ########.fr       */
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

static int	is_valid_position(t_prg *prg, int x, int y)
{
	if (x == 0 || x == prg->parser.width || y == 0 || y == prg->parser.height - 1)
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

# define TERM_END "\x1b[0m"
# define TERM_RED "\x1b[31m"
# define TERM_GREEN "\x1b[32m"
# define TERM_BLUE "\x1b[34m"
# define TERM_ERASE "\033[2K\r"
# define TERM_BCKG_END "\x1b[0m"
# define TERM_BCKG_RED "\x1b[41m"
# define TERM_BCKG_GREEN "\x1b[42m"
# define TERM_BCKG_YELLOW "\x1b[43m"
# define TERM_BCKG_BLUE "\x1b[44m"
# define TERM_BCKG_MAGENTA "\x1b[45m"
# define TERM_BCKG_CYAN "\x1b[46m"
# define TERM_BCKG_WHITE "\x1b[47m"

static void	print_wrong_position(t_prg *prg)
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
				printf("\x1b[41m  \x1b[0m");
			else if (prg->world_map[j][i] == 0)
				printf("\x1b[42m  \x1b[0m");
			else if (prg->world_map[j][i] == 1)
				printf("\x1b[44m  \x1b[0m");
			else if (prg->world_map[j][i] == 3)
				printf("\x1b[43m  \x1b[0m");
			else if (prg->world_map[j][i] == 2)
				printf("  ");
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

static bool	is_valid_map(t_prg *prg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	prg->parser.pos_player = 0;
	while (y < prg->parser.height)
	{
		while (x < prg->parser.width)
		{
			// if (prg->world_map[y][x] == 0)
			// {
				// if (is_valid_position(prg, x, y) == false)
				// {
					// print_wrong_position(prg);
					// dprintf(2,"\nError: Value-->%d x-->%d y-->%d\n", prg->world_map[y][x], x ,y);
				// }
			// }
			if (prg->world_map[y][x] != 1 && prg->world_map[y][x] != 0 
				&& prg->world_map[y][x] != 2)
			{
				if (position_player(prg->world_map[y][x], x, y, prg) == false)
					return (false);
				prg->parser.pos_player += 1;
				prg->world_map[y][x] = 3;
			}
			x++;
		}
		x = 0;
		y++;
	}
	print_wrong_position(prg);
	if (prg->parser.pos_player > 1 || prg->parser.pos_player == 0)
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
	is_valid_map(prg);
	return (true);
}

bool	parsing(t_prg *prg, char **argv, int argc)
{
	if (argc != 2)
		return (false);
	if (!parse_file(argv[1], prg))
		return (false);
	if (!init_map(prg))
		return (false);
	prg->player.move_speed = 0.2;
	prg->player.rotation_speed = 0.05;
	// for (int y = 0; y < prg->parser.height; y++)
	// {
	// 	for (int x = 0; x < prg->parser.width; x++)
	// 	{
	// 		dprintf(2, "%d, ", x);
	// 	}
	// 	dprintf(2, "\n");
	// }
	// sleep(1);
	// if (!init_tab_map(prg, prg->parser.height, prg->parser.width))
	// 	return(false);
	return (true);
}