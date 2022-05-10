/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degraded_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:10:01 by tarchimb          #+#    #+#             */
/*   Updated: 2022/05/09 13:17:04 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_lerp_d(int min, int max, float timestamp)
{
	return ((max - min) * timestamp + min);
}

float	ft_inv_lerp_d(int min, int max, int curr)
{
	return (((float)curr - (float)min) / ((float)max - (float)min));
}

int	color_lerp(int color1, int color2, float timestamp)
{
	int	r;
	int	g;
	int	b;

	if (timestamp > 1.0f)
		timestamp = 1.0f;
	r = ft_lerp_d((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, timestamp);
	g = ft_lerp_d((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, timestamp);
	b = ft_lerp_d(color1 & 0xFF, color2 & 0xFF, timestamp);
	return (1 << 24 | r << 16 | g << 8 | b);
}
