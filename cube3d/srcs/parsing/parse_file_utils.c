/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:34:18 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/03 14:00:43 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

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

bool	check_texture_and_color_init(t_texture *texture, t_draw draw)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (texture[i].relative_path == NULL)
			return (false);
		i++;
	}
	if (draw.sky_color == -1)
		return (false);
	if (draw.floor_color == -1)
		return (false);
	return (true);
}

bool	is_texture(char *line)
{
	if (ft_strncmp(line, "EA", 2) == 0 && line[2] == ' ')
		return (true);
	if (ft_strncmp(line, "NO", 2) == 0 && line[2] == ' ')
		return (true);
	if (ft_strncmp(line, "SO", 2) == 0 && line[2] == ' ')
		return (true);
	if (ft_strncmp(line, "WE", 2) == 0 && line[2] == ' ')
		return (true);
	return (false);
}

bool	is_fc(char *line)
{
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (true);
	return (false);
}

bool	init_texture(t_win window, t_texture *texture, char *filename)
{
	texture->relative_path = filename;
	texture->img = mlx_xpm_file_to_image(window.mlx, texture->relative_path,
			&texture->width, &texture->height);
	if (texture->img == NULL)
		return (false);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (true);
}
