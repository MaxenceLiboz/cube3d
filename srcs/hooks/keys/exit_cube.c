/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:12:12 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:20:12 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	exit_cube(t_prg *prg)
{
	free_world_map(prg->world_map, prg->parser.height);
	mlx_destroy_window(prg->win.mlx, prg->win.win);
	exit(1);
	return (1);
}
