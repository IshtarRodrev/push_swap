/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 22:00:00 by akechedz          #+#    #+#             */
/*   Updated: 2026/10/27 22:00:00 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	atoi_precheck(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dub_check(t_stack *stack, int new_data)
{
	t_node	*tmp;

	if (!stack || !stack->first)
		return (1);
	tmp = stack->last;
	while (tmp)
	{
		if (tmp->data == new_data)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}
