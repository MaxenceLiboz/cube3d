/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 11:05:47 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	get_map(t_prg *prg)
{
	int		fd;
	char	*str;
	int		x;

	x = 0;
	fd = open("map_test", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		for (int i = 0; i < ft_strlen(str); i++)
			prg->world_map[x][i] = str[i] - '0';
		free(str);
		str = get_next_line(fd);
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	get_map(&prg);
	initialization(&prg);
	prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			"Cube 3D");
	write_map(&prg, prg.world_map);
	mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	mlx_hook(prg.win.win, 2, 1L << 0, key_pressed, &prg);
	mlx_loop(prg.win.mlx);
	(void)argc;
	(void)argv;
	// (void)world_map;
}
