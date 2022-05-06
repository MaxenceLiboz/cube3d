/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 14:56:19 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_textures_color(t_prg *prg)
{
	prg->texture[0].relative_path = NULL;
	prg->texture[1].relative_path = NULL;
	prg->texture[2].relative_path = NULL;
	prg->texture[3].relative_path = NULL;
	prg->draw.sky_color = -1;
	prg->draw.floor_color = -1;
}

int	main(int argc, char **argv)
{
	char	relative_path[100] = "./pics/cube6.xpm";
	t_prg	prg;

	ft_bzero(&prg, sizeof(t_prg));
	window_init(&prg.win);
	init_textures_color(&prg);
	if (parsing(&prg, argv, argc) == false)
		exit(0);
	prg.background.img = mlx_xpm_file_to_image(&prg.win.mlx, relative_path,
		&prg.win.width, &prg.win.height);
	prg.background.addr = mlx_get_data_addr(&prg.img.img,
		&prg.img.bits_per_pixel,&prg.img.line_length, &prg.img.endian);
	img_init(prg.win, &prg.img);
	prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			"Cube 3D");
	init_hooks(&prg);
	write_map(&prg, prg.world_map);
	mlx_mouse_move(prg.win.win, prg.win.width / 2, prg.win.height / 2);
	mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	mlx_loop_hook(prg.win.mlx, refresh, &prg);
	mlx_loop(prg.win.mlx);
}
