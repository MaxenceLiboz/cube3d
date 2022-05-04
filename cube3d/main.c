/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:36:27 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/04 10:17:44 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	init_map2(t_prg *prg)
{
	prg->map.cell_size = 40;
	if (prg->parser.width <= 40)
		prg->map.max_cell_width = prg->parser.width;
	else
		prg->map.max_cell_width = 40;
	if (prg->parser.height <= 20)
		prg->map.max_cell_height = prg->parser.height;
	else
		prg->map.max_cell_height = 20;
	if (prg->parser.height <= prg->map.max_cell_height)
		prg->map.big_map_height = false;
	else
		prg->map.big_map_height = true;
	if (prg->parser.width <= prg->map.max_cell_width)
		prg->map.big_map_width = false;
	else
		prg->map.big_map_width = true;
	if (prg->map.big_map_height == false)
		prg->map.center.y = (prg->win.height / 2) - ((prg->parser.height / 2)
			* prg->map.cell_size);
	else
		prg->map.center.y = (prg->win.height / 2) - ((prg->map.max_cell_height / 2)
			* prg->map.cell_size);
	if (prg->map.big_map_width == false)
		prg->map.center.x = (prg->win.width / 2)- ((prg->parser.width / 2)
			* prg->map.cell_size);
	else
		prg->map.center.x = (prg->win.width / 2) - ((prg->map.max_cell_width / 2)
			* prg->map.cell_size);
	if (prg->map.big_map_height == false)
		prg->map.end_point.y = prg->parser.height;
	else
		prg->map.end_point.y = prg->map.max_cell_height;
	if (prg->map.big_map_width == false)
		prg->map.end_point.x = prg->parser.width;
	else
		prg->map.end_point.x = prg->map.max_cell_width;
	prg->mini_map.big_map_height = prg->map.big_map_height;
	prg->mini_map.big_map_width = prg->map.big_map_width;
	prg->mini_map.cell_size = 10;
	prg->mini_map.center = prg->map.center;
	prg->mini_map.max_cell_height = prg->map.max_cell_height;
	prg->mini_map.max_cell_width = prg->map.max_cell_width;
	prg->mini_map.end_point.x = prg->mini_map.max_cell_width;
	prg->mini_map.end_point.y = prg->mini_map.max_cell_height;
	
}

void	init_edition(t_prg *prg)
{
	prg->edition_mode = 0;
	prg->edition.offset_in = 0.7f;
	prg->edition.offset_out = 0.2f;
	prg->edition.cell_size = prg->win.height / prg->parser.height
		* prg->edition.offset_out;
}

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
	init_edition(&prg);
	init_map2(&prg);
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
