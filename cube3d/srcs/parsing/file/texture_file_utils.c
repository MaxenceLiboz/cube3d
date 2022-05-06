/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:09:37 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/07 00:26:38 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

bool	fill_texture(char *line, t_prg *prg)
{
	char	*tmp;
	char	*tmp1;
	bool	result;

	tmp1 = ft_substr(line, 3, ft_strlen(line) - 4);
	tmp = ft_strtrim(tmp1, " ");
	result = false;
	if (!tmp)
		return (ft_free(false, 1, tmp));
	if (open(tmp, O_RDONLY) == -1)
		return (ft_free(false, 2, tmp, tmp1));
	if (line[0] == 'N')
		result = init_texture(prg->win, &prg->texture[0], tmp);
	else if (line[0] == 'S')
		result = init_texture(prg->win, &prg->texture[1], tmp);
	else if (line[0] == 'W')
		result = init_texture(prg->win, &prg->texture[2], tmp);
	else if (line[0] == 'E')
		result = init_texture(prg->win, &prg->texture[3], tmp);
	ft_free(0, 2, tmp1, line);
	if (result == false)
		return (ft_error(false, 1, "MLX xpm to file error"));
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
