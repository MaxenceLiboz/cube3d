/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 17:17:53 by tarchimb         ###   ########.fr       */
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

	ft_bzero(&prg, sizeof(t_prg));
	prg.h_map.help_mode = 0;
	prg.h_map.max_size = 0;
	prg.h_map.help_mode = 0;
	window_init(&prg.win);
	init_textures_color(&prg);
	if (parsing(&prg, argv, argc) == false)
		exit(0);
	img_init(prg.win, &prg.img);
	prg.win.win = mlx_new_window(prg.win.mlx, prg.win.width, prg.win.height,
			"Cube 3D");
	mlx_mouse_hide();
	mlx_mouse_move(prg.win.win, prg.win.width / 2, prg.win.height / 2);
	mlx_mouse_get_pos(prg.win.win, &prg.mouse.mouse_position.x,
		&prg.mouse.mouse_position.y);
	mlx_hooks_management(&prg);
	mlx_put_image_to_window(prg.win.mlx, prg.win.win, prg.img.img, 0, 0);
	mlx_loop(prg.win.mlx);
}
