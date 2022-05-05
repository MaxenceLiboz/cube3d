/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 08:29:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/05 11:13:32 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	free_2d_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	rotation_matrix(t_prg *prg, double rad)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = prg->player.x_dir;
	old_x_plane = prg->player.x_plane;
	prg->player.x_dir = prg->player.x_dir * cos(rad)
		- prg->player.y_dir * sin(rad);
	prg->player.y_dir = old_x_dir * sin(rad)
		+ prg->player.y_dir * cos(rad);
	prg->player.x_plane = prg->player.x_plane * cos(rad)
		- prg->player.y_plane * sin(rad);
	prg->player.y_plane = old_x_plane * sin(rad)
		+ prg->player.y_plane * cos(rad);
}
