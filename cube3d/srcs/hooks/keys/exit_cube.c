/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:12:12 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 09:12:39 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

// FREE EVERYTHING
int	exit_cube(t_prg *prg)
{
	mlx_destroy_window(prg->win.mlx, prg->win.win);
	exit(1);
}
