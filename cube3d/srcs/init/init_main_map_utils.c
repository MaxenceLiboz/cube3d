/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:11:55 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 08:57:51 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

bool	is_valid_map_char(int position)
{
	if (position != 'N' && position != 'S' && position != 'E' && position != 'W'
		&& position != ' ')
		return (false);
	return (true);
}
