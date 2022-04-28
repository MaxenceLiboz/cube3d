/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:59:10 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 08:57:48 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	fill_texture(char *line, t_prg *prg)
{
	char	*tmp;

	tmp = ft_substr(line, 3, ft_strlen(line) - 2);
	tmp = ft_strtrim(tmp, " ");
	// if (!tmp || open(tmp, O_RDONLY) == -1)
	// 	return (-1);
	if (line[0] == 'N')
		prg->texture[0].relative_path = tmp;
	else if (line[0] == 'S')
		prg->texture[1].relative_path = tmp;
	else if (line[0] == 'W')
		prg->texture[2].relative_path = tmp;
	else if (line[0] == 'E')
		prg->texture[3].relative_path = tmp;
	return (0);
}

int fill_FC(char *line, t_prg *prg)
{
	char	**tmp;
	int		color;
	int		value[3];
	(void)prg;

	color = 0;
	tmp = ft_split(line, ',');
	if (!tmp || !tmp[1] || !tmp[2])
	{
		//Free everything
		return (-1);
	}
	value[0] = ft_atoi(&tmp[0][1]);
	value[1] = ft_atoi(tmp[1]);
	value[2] = ft_atoi(tmp[2]);
	if (value[0] < 0 || value[0] > 255 || value[1] < 0 || value[1] > 255
		|| value[2] < 0 || value[2] > 255)
		return (-1);
	color = value[0] << 16 | value[1] << 8 | value[2];
	//Free tmp
	return (0);
}

int	parse_line(char *line, t_prg *prg, int len)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (!line || line[i] == '\0' || line[0] == '\n')
		return (0);
	line = ft_strtrim(line, " ");
	if (line[0] == 'F' || line[0] == 'C')
		return (fill_FC(line, prg));
	else if (prg->parser.start <= 6)
	{
		if (fill_texture(line, prg) == -1)
		{
			//Error to open texture file
			return (-1);
		}
		return (0);
	}
	if (len > prg->parser.width)
			prg->parser.width = len;
	prg->parser.height += 1;
	return (1);
}

bool	parse_file(char *argv, t_prg *prg)
{
	int		fd;
	t_list	*tmp;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (!fd)
		return(ft_error("Can't open infile", false));
	line = get_next_line(fd);
	tmp = ft_lstnew(line);
	while (line)
	{
		tmp = ft_lstnew(line);
		prg->parser.start += 1;
		if (parse_line(tmp->content, prg, tmp->len) == 1)
			ft_lstadd_back(&prg->lst, tmp);
		else
			ft_lstdelone(tmp, free);
		line = get_next_line(fd);
	}
	close(fd);
	return (true);
}