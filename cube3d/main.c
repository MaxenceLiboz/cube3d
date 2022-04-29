/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/29 13:15:27 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int argc, char **argv)
{
	t_prg	prg;

	window_init(&prg.win);
	if (parsing(&prg, argv, argc) == false)
		return (0);
	prg.edition_mode = 0;
	prg.edition.offset_in = 0.7f;
	prg.edition.offset_out = 0.2f;
	prg.edition.cell_size = prg.win.height / prg.parser.height * prg.edition.offset_out;
	img_init(prg.win, &prg.img);
	prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			"Cube 3D");
	write_map(&prg, prg.world_map);
	mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	mlx_hook(prg.win.win, 2, 1L << 0, key_pressed, &prg);
	mlx_hook(prg.win.win, 4, 1L << 2, mouse_pressed, &prg);
	mlx_hook(prg.win.win, 5, 1L << 3, mouse_released, &prg);
	mlx_hook(prg.win.win, 6, 1L << 6, updated_mouse_pos, &prg);
	mlx_loop_hook(prg.win.mlx, refresh, &prg);
	mlx_hook(prg.win.win, 17, 1L << 2, exit_cube, &prg);
	mlx_loop(prg.win.mlx);
}
