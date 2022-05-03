/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:22:54 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/03 15:01:22 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool	fill_texture(char *line, t_prg *prg)
{
	char	*tmp;
	char	*tmp1;
	bool	result;

	tmp1 = ft_substr(line, 3, ft_strlen(line) - 4);
	tmp = ft_strtrim(tmp1, " ");
	result = false;
	if (!tmp || open(tmp, O_RDONLY) == -1)
		return (false);
	if (line[0] == 'N')
		result = init_texture(prg->win, &prg->texture[0], tmp);
	else if (line[0] == 'S')
		result = init_texture(prg->win, &prg->texture[1], tmp);
	else if (line[0] == 'W')
		result = init_texture(prg->win, &prg->texture[2], tmp);
	else if (line[0] == 'E')
		result = init_texture(prg->win, &prg->texture[3], tmp);
	free(tmp);
	free(tmp1);
	free(line);
	if (result == false)
		return (ft_error("MLX xpm to file error", false));
	return (true);
}

static int	fill_fc(char *line, t_prg *prg)
{
	char	**tmp;
	int		value[3];

	tmp = ft_split(line + 1, ',');
	if (!tmp || !tmp[1] || !tmp[2] || is_color_num(tmp) == false)
		return (ft_error("Wrong color format", -1));
	value[0] = ft_atoi(&tmp[0][1]);
	value[1] = ft_atoi(tmp[1]);
	value[2] = ft_atoi(tmp[2]);
	if (value[0] < 0 || value[0] > 255 || value[1] < 0 || value[1] > 255
		|| value[2] < 0 || value[2] > 255)
		return (ft_error("Wrong color format", -1));
	if (line[0] == 'F')
		prg->draw.floor_color = value[0] << 16 | value[1] << 8 | value[2];
	else
		prg->draw.sky_color = value[0] << 16 | value[1] << 8 | value[2];
	free_2d_tab(tmp);
	free(value);
	free(line);
	return (0);
}

static int	parse_line(char *line, t_prg *prg, int len)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line || line[i] == '\0' || line[0] == '\n')
		return (0);
	line = ft_strtrim(line, " ");
	if (is_fc(line) == true)
		return (fill_fc(line, prg));
	else if (is_texture(line) == true)
	{
		if (fill_texture(line, prg) == false)
		{
			dprintf(2, "Wrong texture path: %s", line);
			return (-1);
		}
		return (0);
	}
	if (len > prg->parser.width)
			prg->parser.width = len;
	prg->parser.height += 1;
	return (1);
}

static bool	loop_parse_file(t_prg *prg, int fd)
{
	int		parse_line_result;
	char	*line;
	t_list	*tmp;

	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	while (line)
	{
		tmp = ft_lstnew(line);
		if (tmp == NULL)
			return (false);
		prg->parser.start += 1;
		parse_line_result = parse_line(tmp->content, prg, tmp->len);
		if (parse_line_result == 1)
			ft_lstadd_back(&prg->lst, tmp);
		else if (parse_line_result == -1)
			return (false);
		else
			ft_lstdelone(tmp, free);
		line = get_next_line(fd);
	}
	return (true);
}

bool	parse_file(char *file_path, t_prg *prg)
{
	int		fd;
	bool	result;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_error("Can't open map", false));
	prg->lst = NULL;
	result = loop_parse_file(prg, fd);
	close(fd);
	if (result == false)
		return (false);
	if (check_texture_and_color_init(prg->texture, prg->draw) == false)
		return (ft_error("Wrong file format", false));
	return (true);
}
