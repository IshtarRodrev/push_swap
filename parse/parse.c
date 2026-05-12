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
	int i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	atoi_precheck(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i]) 
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	dub_check(t_stack *stack, int new_data)
{
	t_node *tmp;

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

static t_stack *push_back_2_stk(t_stack *stack, int new_data)
{
	t_node *element;

	if (!stack)
		return (NULL);
	if (!stack->first)
	{
		element = malloc(sizeof(t_node));
		if (!element)
			return (NULL);
		element->data = new_data;
		element->next = NULL;
		element->prev = NULL;
		stack->first = element;
		stack->last = element;
		stack->size = 1;
		return (stack);
	}
	if (!dub_check(stack, new_data)) // if duplicate found throw err_msg()
	{
		stk_free(stack);
		return (0);
	}
	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->data = new_data;
	element->next = stack->first;
	stack->first->prev = element;
	element->prev = NULL;
	stack->first = element;
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
	/* don't re-initialize the stack here: parse_args may call stk_fill
	   for each argv entry; preserve previously pushed elements */
	while (arr[i])
	{
		if (!atoi_precheck(arr[i]))
			return (0);
		num = ft_atol(arr[i]);
		if (num < INT_MIN || num > INT_MAX || !push_back_2_stk(a, (int)num))
			return (0);
		i++;
	}
	/* `push_back_2_stk` updates `a->size` as elements are pushed.
	   Do not overwrite it here (stk_fill may be called multiple times). */
	/* TODO: indexes must be atributed here.  */
	stk_normalize(a);
	return (1);
}

//TODO: Change this to atol to avoid integer overflow
int	parse_args(int argc, char **argv, t_stack *a) 
{
	int i;
	char **arr;

	if (!a)
		return (0);
	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			return (0);
		if (!stk_fill(arr, a))
		{
			arr_free(arr);
			return (0);
		}
		arr_free(arr);
		i++;
	}
	return (1);
}
