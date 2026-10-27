/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:44:24 by akechedz          #+#    #+#             */
/*   Updated: 2026/03/01 14:44:24 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "../push_swap.h"
#include "../libft/libft.h"

void	arr_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static t_stack	*push_back_2_stk(t_stack *stack, int new_data)
{
	t_node	*element;

	if (!stack || !dub_check(stack, new_data))
		return (NULL);
	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->data = new_data;
	element->next = NULL;
	element->prev = stack->last;
	if (stack->last)
		stack->last->next = element;
	else
		stack->first = element;
	stack->last = element;
	stack->size += 1;
	return (stack);
}

int	stk_fill(char **arr, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	if (!a)
		return (0);
	while (arr[i])
	{
		if (!atoi_precheck(arr[i]))
			return (0);
		num = ft_atol(arr[i]);
		if (num < INT_MIN || num > INT_MAX || !push_back_2_stk(a, (int)num))
			return (0);
		i++;
	}
	stk_normalize(a);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**arr;

	if (!a)
		return (0);
	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			return (0);
		if (!arr[0] || !stk_fill(arr, a))
		{
			arr_free(arr);
			return (0);
		}
		arr_free(arr);
		i++;
	}
	return (1);
}
