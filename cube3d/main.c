/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 12:24:41 by tarchimb         ###   ########.fr       */
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
	t_prg	prg;

	window_init(&prg.win);
	init_textures_color(&prg);
	if (parsing(&prg, argv, argc) == false)
		exit(0);
	img_init(prg.win, &prg.img);
	prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			"Cube 3D");
	write_map(&prg, prg.world_map);
	mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	mlx_hook(prg.win.win, 2, 1L << 0, key_pressed, &prg);
	mlx_hook(prg.win.win, 3, 1L << 1, key_released, &prg);
	mlx_hook(prg.win.win, 4, 1L << 2, mouse_pressed, &prg);
	mlx_hook(prg.win.win, 5, 1L << 3, mouse_released, &prg);
	mlx_hook(prg.win.win, 6, 1L << 6, updated_mouse_pos, &prg);
	mlx_loop_hook(prg.win.mlx, refresh, &prg);
	mlx_hook(prg.win.win, 17, 1L << 2, exit_cube, &prg);
	mlx_loop(prg.win.mlx);
}
