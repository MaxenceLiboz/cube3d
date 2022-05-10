/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_file_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:11:21 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:07:07 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

static int	get_background_color(t_prg *prg, char **tmp, char *line)
{
	int		value[3];

	value[0] = ft_atoi(&tmp[0][1]);
	value[1] = ft_atoi(tmp[1]);
	value[2] = ft_atoi(tmp[2]);
	if (value[0] < 0 || value[0] > 255 || value[1] < 0 || value[1] > 255
		|| value[2] < 0 || value[2] > 255)
	{
		free_2d_tab(tmp);
		return (ft_free(ft_error(-1, 1, "Wrong color format"), 1, line));
	}
	if (line[0] == 'F')
		prg->draw.floor_color = value[0] << 16 | value[1] << 8 | value[2];
	else
		prg->draw.sky_color = value[0] << 16 | value[1] << 8 | value[2];
	return (0);
}

int	fill_background(char *line, t_prg *prg)
{
	char	**tmp;

	if (prg->draw.floor_color != -1 && line[0] == 'F')
		return (ft_error(ft_free(-1, 1, line), 1, "Multiple floor color"));
	if (prg->draw.sky_color != -1 && line[0] == 'C')
		return (ft_error(ft_free(-1, 1, line), 1, "Multiple ceiling color"));
	tmp = ft_split(line + 1, ',');
	if (!tmp || !tmp[1] || !tmp[2] || is_color_num(tmp) == false || tmp[3])
	{
		free_2d_tab(tmp);
		return (ft_free(ft_error(-1, 1, "Wrong color format"), 1, line));
	}
	if (get_background_color(prg, tmp, line) == -1)
		return (-1);
	free_2d_tab(tmp);
	return (ft_free(0, 1, line));
}

bool	is_color_num(char **str)
{
	int		i;
	int		y;

	y = 0;
	while (y < 3)
	{
		i = 0;
		while (i < ft_strlen(str[y]))
		{
			if (ft_isdigit(str[y][i]) == false && str[y][i] != ' '
				&& str[y][i] != '\n' && str[y][i] != '\t'
				&& str[y][i] != '\v' && str[y][i] != '\f'
				&& str[y][i] != '\r')
				return (false);
			i++;
		}
		y++;
	}
	return (true);
}

bool	is_background(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (true);
	return (false);
}
