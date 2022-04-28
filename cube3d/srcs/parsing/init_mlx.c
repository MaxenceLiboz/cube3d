/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 09:45:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/28 11:33:07 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

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