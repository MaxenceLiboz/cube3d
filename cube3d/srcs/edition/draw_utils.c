/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:24:28 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/03 10:29:44 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_circle(t_data *data, t_point center)
{
	t_point	pos;
	int 	radius;
	int		x;
	int		y;

	radius = 5;
	x = center.x - radius;
	y = center.y - radius;
	while (y < center.y + radius)
	{
		while (x < center.x + radius)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			if ((float)(pos.x + pos.y) - (radius * radius) < 0.1f)
				my_mlx_pixel_put(data, x, y, YELLOW);
			x++;
		}
		x = center.x - radius;
		y++;
	}
}


void	draw_square_cell(t_prg *prg, t_point point1, t_point point2, int color)
{
	int	x;
	int	y;

	x = point1.x;
	y = point1.y;
	while (y < point2.y)
	{
		while (x < point2.x)
		{
			my_mlx_pixel_put(&prg->img, x, y, color);
			x++;
		}
		y++;
		x = point1.x;
	}
}