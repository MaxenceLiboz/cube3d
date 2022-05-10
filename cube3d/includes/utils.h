/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:19:56 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"

void	free_2d_tab(char **tab);
void	rotation_matrix(t_prg *prg, double rad);
int		ft_error(int return_value, int size, char *str, ...);
int		ft_free(int return_value, int size, ...);

#endif