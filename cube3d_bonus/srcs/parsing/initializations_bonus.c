/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 07:39:35 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 10:11:01 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
	Init the standard variable of the window
*/
bool	window_init(t_win *window)
{
	window->width = 1920;
	window->height = 1080;
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (false);
	return (true);
}

/*
	Create the main image and get the addr to be able to change pixel inside
*/
bool	img_init(t_win window, t_data *img)
{
	img->img = mlx_new_image(window.mlx, window.width, window.height);
	if (img->img == NULL)
		return (false);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (true);
}

/*
	Create a single texture
*/
bool	init_texture(t_win window, t_texture *texture, char *filename)
{
	texture->width = 64;
	texture->height = 64;
	texture->relative_path = filename;
	texture->img = mlx_xpm_file_to_image(window.mlx, texture->relative_path,
			&texture->width, &texture->height);
	if (texture->img == NULL)
		return (false);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_length, &texture->endian);
	return (true);
}

/*
	Hardcoding this function for now, before the parsing
*/
bool	initialization(t_prg *prg)
{
	if (window_init(&prg->win) == false)
		ft_error("Window initialization error\n", false);
	if (img_init(prg->win, &prg->img) == false)
		ft_error("Image initialization error\n", false);
	if (init_texture(prg->win, &prg->texture[0], "./pics/gw110.xpm")
		== false)
		ft_error("Texture initialization error\n", false);
	if (init_texture(prg->win, &prg->texture[1], "./pics/bluestone.xpm")
		== false)
		ft_error("Texture initialization error\n", false);
	if (init_texture(prg->win, &prg->texture[2], "./pics/eagle.xpm")
		== false)
		ft_error("Texture initialization error\n", false);
	if (init_texture(prg->win, &prg->texture[3], "./pics/mossy.xpm")
		== false)
		ft_error("Texture initialization error\n", false);
	prg->player.x_pos = 11;
	prg->player.y_pos = 12;
	prg->player.x_dir = -1;
	prg->player.y_dir = 0;
	prg->player.x_plane = 0;
	prg->player.y_plane = 0.66;
	prg->draw.sky_color = 0x000080;
	prg->draw.floor_color = 0x808080;
	prg->player.use_mouse = 1;
	return (true);
}
