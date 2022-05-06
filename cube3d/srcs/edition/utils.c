/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:40:28 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/05 22:40:58 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_info(t_prg *prg)
{
	t_point	pt1;
	t_point	pt2;

	pt1.x = prg->win.width * 0.20f;
	pt1.y = prg->win.height * 0.05f;
	pt2.x = pt1.x + prg->map.cell_size;
	pt2.y = pt1.y + prg->map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BLACK);
	pt1.x = prg->win.width * 0.35f;
	pt2.x = pt1.x + prg->map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BLUE);
	pt1.x = prg->win.width * 0.50f;
	pt2.x = pt1.x + prg->map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, RED);
	pt1.x = prg->win.width * 0.65f;
	pt2.x = pt1.x + prg->map.cell_size;
	draw_square_cell(prg, &pt1, &pt2, BACKGROUND);
	pt1.x = prg->win.width * 0.80f;
	pt1.y += prg->map.cell_size / 2;
	draw_circle(&prg->img, pt1);
}

void	indications_strings(t_prg *prg)
{
	int	y;

	y = (prg->win.height + prg->win.height / 2) * 0.05f;
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.20f + 20
		+ prg->map.cell_size, y , WHITE, "= Ground cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.35f+ 20
		+ prg->map.cell_size,y , WHITE, "= Wall cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.50f+ 20
		+ prg->map.cell_size, y , WHITE, "= Wrong empty cube position");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.65f+ 20
		+ prg->map.cell_size, y , WHITE, "= Empty cube");
	mlx_string_put(prg->win.mlx, prg->win.win, prg->win.width * 0.80f+ 20
		+ prg->map.cell_size, y , WHITE, "= Player position");
}