/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:48:20 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 19:06:55 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	help_mode_str(t_prg *prg)
{
	if (prg->h_map.is_printable == true)
	{
		mlx_string_put(prg->win.mlx, prg->win.win, 150, 50 , BLACK,
			"===HELP MENU===");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 130 , BLACK,
			"= Move Forward");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 275 , BLACK,
			"= Move Backward");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 425 , BLACK,
			"= Move Left");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 575 , BLACK,
			"= Move Right");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 725 , BLACK,
			"= View Left");
		mlx_string_put(prg->win.mlx, prg->win.win, 230, 875 , BLACK,
			"= View Right");	
	}
	else if (prg->edition_mode == false)
	{
		mlx_string_put(prg->win.mlx, prg->win.win, 510, 35, BLACK,
			"= Help Menu");
		mlx_string_put(prg->win.mlx, prg->win.win, 510, 95, BLACK,
			"= Edition Mode");
	}
}

void	draw_help_to_image(t_prg *prg)
{
	if (prg->h_map.is_printable == true)
	{
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_W_TAB].img, 50, 100);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_S_TAB].img, 50, 250);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_A_TAB].img, 50, 400);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_D_TAB].img, 50, 550);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_LEFT_TAB].img, 50, 700);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_RIGHT_TAB].img, 50, 850);
	}
	else if (prg->edition_mode == false)
	{
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_H_TAB].img, 450, 10);
		mlx_put_image_to_window(prg->win.mlx, prg->win.win,
			prg->help_keys[KEY_E_TAB].img, 450, 70);
	}
	help_mode_str(prg);
}

void	print_help_map(t_prg *prg)
{
	t_point	index;

	index.y = 0;
	while (index.y < prg->win.height && prg->h_map.max_size
		<= prg->win.width / 4)
	{
		index.x = 0;
		while (index.x <= prg->h_map.max_size)
		{
			my_mlx_pixel_put(&prg->img, index.x, index.y, DARKLY_GRAY + index.y * index.x);
			index.x++;
		}
		index.y++;
	}
	prg->h_map.max_size += 100;
	if (prg->h_map.max_size >= prg->win.width / 4)
	{
		prg->h_map.max_size -= 100;
		prg->h_map.is_printable = true;
	}
}

void	hide_help_map(t_prg *prg)
{
	t_point	index;

	index.y = 0;
	while (index.y < prg->win.height && prg->h_map.max_size >= 0)
	{
		index.x = 0;
		while (index.x <= prg->h_map.max_size)
		{
			my_mlx_pixel_put(&prg->img, index.x, index.y, DARK_GRAY);
			index.x++;
		}
		index.y++;
	}
	if (prg->h_map.max_size > 0)
		prg->h_map.max_size -= 100;
}