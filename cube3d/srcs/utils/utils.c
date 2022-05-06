/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 08:29:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 08:53:32 by mliboz           ###   ########.fr       */
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

int	time_diff(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000
		+ 1e-3 * (end.tv_usec - start.tv_usec));
}
