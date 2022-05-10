/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 08:29:52 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/10 10:37:37 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

void	free_2d_tab(char **tab)
{
	int		i;

	i = 0;
	if (!*tab)
		return ;
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

/*
	return_value: variable returned
	size: number of char * wrote
	str: first char *
	...: all the char * you want
*/
int	ft_error(int return_value, int size, char *str, ...)
{
	va_list	arg;

	va_start(arg, str);
	ft_putstr_fd("Error\n", 2);
	if (str)
	{
		ft_putstr_fd(str, 2);
		size--;
	}
	while (size--)
		ft_putstr_fd(va_arg(arg, char *), 2);
	ft_putstr_fd("\n", 2);
	va_end(arg);
	return (return_value);
}

int	ft_free(int return_value, int size, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, size);
	i = 0;
	while (i < size)
	{
		free(va_arg(arg, void *));
		i++;
	}
	va_end(arg);
	return (return_value);
}
