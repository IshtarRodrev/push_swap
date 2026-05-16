/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:46:20 by akechedz          #+#    #+#             */
/*   Updated: 2026/05/16 21:46:20 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

long	ft_atol(char *str)
{
	int		sign;
	long	num;

	if (!str)
		return (0);
	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (str[0] == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
