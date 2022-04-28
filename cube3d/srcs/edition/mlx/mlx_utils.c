/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:50:27 by tarchimb          #+#    #+#             */
/*   Updated: 2022/04/28 17:32:11 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// static bool	init_map_cell(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->cell_size = 30;
// 	data->map_height = 40;
// 	data->map_width = 40;
// 	data->cell_map = malloc(sizeof(int *) * data->map_height);
// 	if (!data->cell_map)
// 		return (0);
// 	while (i < data->map_height)
// 	{
// 		data->cell_map[i] = ft_calloc(data->map_width, sizeof(int));
// 		if (!data->cell_map[i])
// 		{
// 			// Need to free everything
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

bool	run_window(t_prg *prg)
{
	// init_map_cell(data);
	prg->edition.cell_height = prg->win.height / prg->parser.height * 0.4;
	prg->edition.cell_width = prg->win.width / prg->parser.width * 0.4;
	mlx_hook(prg->win.win, 4, 1L << 2, mouse_hook, prg);
	mlx_hook(prg->win.win, 4, 1L << 2, mouse_pressed, prg);
	mlx_hook(prg->win.win, 5, 1L << 3, mouse_released, prg);
	mlx_hook(prg->win.win, 6, 1L << 6, updated_mouse_pos, prg);
	mlx_loop_hook(prg->win.mlx, update, prg);
	mlx_loop(prg->win.mlx);
	return (1);
}