/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mliboz <mliboz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 08:01:43 by mliboz            #+#    #+#             */
/*   Updated: 2022/04/26 08:04:36 by mliboz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cube3d.h>

int	ft_error(char *str, int return_value)
{
	if (str == NULL)
		ft_error("Error, send empty string", false);
	write(2, str, sizeof(str));
	return (return_value);
}