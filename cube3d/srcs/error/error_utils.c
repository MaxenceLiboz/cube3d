/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:01:43 by mliboz            #+#    #+#             */
/*   Updated: 2022/05/04 09:18:57 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

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
