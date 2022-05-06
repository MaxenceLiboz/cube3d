/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/06 12:23:22 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"

void	free_2d_tab(char **tab);
void	rotation_matrix(t_prg *prg, double rad);
int		time_diff(struct timeval start);
int		ft_error(int return_value, int size, char *str, ...);
int		ft_free(int return_value, int size, ...);

#endif