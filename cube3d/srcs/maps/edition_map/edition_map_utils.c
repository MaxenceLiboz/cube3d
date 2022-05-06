/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:40:28 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/06 23:30:16 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_image_bot(t_prg *prg)
{
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_DOWN_TAB].img, 100, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_UP_TAB].img, 350, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_LEFT_TAB].img, 600, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_RIGHT_TAB].img, 850, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_LMB_TAB].img, 1100, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_RMB_TAB].img, 1350, 980);
	mlx_put_image_to_window(prg->win.mlx, prg->win.win,
		prg->help_keys[KEY_CMB_TAB].img, 1600, 980);
}

void	draw_image_top(t_prg *prg)
{
	t_point	pt1;
	t_point	pt2;

	pt1.x = prg->win.width * 0.20f;
	pt1.y = prg->win.height * 0.05f;
	pt2.x = pt1.x + prg->e_map.cell_size;
	pt2.y = pt1.y + prg->e_map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BLACK);
	grid_for_unit_cell(prg, pt1);
	pt1.x = prg->win.width * 0.35f;
	pt2.x = pt1.x + prg->e_map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BLUE);
	grid_for_unit_cell(prg, pt1);
	pt1.x = prg->win.width * 0.50f;
	pt2.x = pt1.x + prg->e_map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, RED);
	grid_for_unit_cell(prg, pt1);
	pt1.x = prg->win.width * 0.65f;
	pt2.x = pt1.x + prg->e_map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BACKGROUND);
	grid_for_unit_cell(prg, pt1);
	pt1.x = prg->win.width * 0.80f;
	pt1.y += prg->e_map.cell_size / 2;
	draw_circle(&prg->img, pt1);
}

void	edition_mode_str(t_prg *prg)
{
	int	y;

	y = (prg->win.height + prg->win.height / 2) * 0.05f;
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.20f + 20
		+ prg->e_map.cell_size, y, WHITE, "= Ground cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.35f + 20
		+ prg->e_map.cell_size, y, WHITE, "= Wall cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.50f + 20
		+ prg->e_map.cell_size, y, WHITE, "= Wrong empty cube position");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.65f + 20
		+ prg->e_map.cell_size, y, WHITE, "= Empty cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.80f + 20
		+ prg->e_map.cell_size, y, WHITE, "= Position Player");
	mlx_string_put(prg->win.mlx, prg->win.win, 210, 1010, WHITE, "= Move Down");
	mlx_string_put(prg->win.mlx, prg->win.win, 460, 1010, WHITE, "= Move Up");
	mlx_string_put(prg->win.mlx, prg->win.win, 710, 1010, WHITE, "= Move Left");
	mlx_string_put(prg->win.mlx, prg->win.win, 960, 1010, WHITE,
		"= Move Right");
	mlx_string_put(prg->win.mlx, prg->win.win, 1150, 1010, WHITE,
		"= Draw Wall Cell");
	mlx_string_put(prg->win.mlx, prg->win.win, 1400, 1010, WHITE,
		"= Draw Ground Cell");
	mlx_string_put(prg->win.mlx, prg->win.win, 1650, 1010, WHITE,
		"= Draw empty Cell");
}

void	is_valid_new_map(t_prg *prg)
{
	prg->edition_mode = 2;
	if (is_valid_map(prg, 0) == true)
	{
		prg->e_map.cell_size = 10;
		prg->edition_mode = false;
		mlx_mouse_hide();
	}
	else
		prg->edition_mode = true;
}
