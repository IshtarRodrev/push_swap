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

static void	free_arr(char **arr)
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

static void	free_stk(t_stack *stack)
{
	t_node *curr;
	t_node *next;

	if (!stack)
		return ;
	curr = stack->first;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

static int	atoi_precheck(char *str)
{
	int	i;

	i = 0;
	while (str[i]) 
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
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

static t_stack *adjust_stack(t_stack *stack, int new_data)
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
		free_stk(stack);
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
int	fill_stk(char **arr, t_stack *a)
{
	int		i;
	long	num;

	i = 0;
	if (!a)
		return (0);
	/* don't re-initialize the stack here: parse_args may call fill_stk
	   for each argv entry; preserve previously pushed elements */
	while (arr[i])
	{
		if (!atoi_precheck(arr[i]))
			return (0);
		num = ft_atol(arr[i]);
		if (num < INT_MIN || num > INT_MAX || !adjust_stack(a, (int)num))
			return (0);
		i++;
	}
	/* `adjust_stack` updates `a->size` as elements are pushed.
	   Do not overwrite it here (fill_stk may be called multiple times). */
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
		if (!fill_stk(arr, a))
		{
			free_arr(arr);
			return (0);
		}
		free_arr(arr);
		i++;
	}
	return (1);
}
