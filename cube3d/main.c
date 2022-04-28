/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 15:19:08 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_prg	prg;

	window_init(&prg.win);
	prg.edition_mode = 0;
	if (parsing(&prg, argv, argc) == false)
		return (0);
	// img_init(prg.win, &prg.img);
	// prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			// "Cube 3D");
	// write_map(&prg, prg.world_map);
	// mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	// mlx_hook(prg.win.win, 2, 1L << 0, key_pressed, &prg);
	// mlx_hook(prg.win.win, 2, 1L << 0, key_pressed, &prg);
	// mlx_loop_hook(prg.win.mlx, refresh, &prg);
	// mlx_hook(prg.win.win, 17, 1L << 2, exit_cube, &prg);
	// mlx_loop(prg.win.mlx);
}
