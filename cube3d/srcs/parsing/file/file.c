/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 15:22:54 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 17:12:33 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	parse_line(char *line, t_prg *prg, int len)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line || line[i] == '\0' || line[0] == '\n')
		return (0);
	line = ft_strtrim(line, " ");
	if (is_background(line) == true)
		return (fill_background(line, prg));
	if (is_texture(line) == true)
	{
		if (fill_texture(line, prg) == false)
		{
			ft_error(-1, 2, "Wrong texture path: ", line);
			free(line);
			return (-1);
		}
		return (0);
	}
	else
		free(line);
	if (len > prg->parser.width)
			prg->parser.width = len;
	prg->parser.height += 1;
	return (1);
}

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
		{
			ft_lstdelone(tmp, free);
			return (false);
		}
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
		return (ft_error(false, 1, "Can't open map"));
	prg->lst = NULL;
	result = loop_parse_file(prg, fd);
	close(fd);
	if (result == false)
		return (false);
	if (!help_texture(prg))
		return (false);
	if (check_texture_and_color_init(prg->texture, prg->draw) == false)
	{
		ft_lstclear(&prg->lst, free);
		return (ft_error(false, 1, "Wrong file format"));
	}
	return (true);
}
