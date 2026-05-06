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
#include "../push_swap.h"
#include "../libft/libft.h"

static int	digit_check(char *checkme)// here must be called an error if nuber is more than INT_MAX
/*
digit_check(): 
	rejects leading + signs and allows a lone - to pass initial check but then 
	fails on empty string — cover + and - properly and reject strings like "+" 
	or "-" (no digits). Use isdigit for the rest.*/
{
	int i = 0;
	if (!checkme)
		return (0);
	if (checkme[i] == '-')
		i++;
	if (checkme[i] == '\0')
		return (0);
	while (checkme[i])
	{
		if (!ft_isdigit(checkme[i]))
			return (0);
		i++;
	}
	return (1);
}

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

/* parser-local stack helpers */
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
	if (!dub_check(stack, new_data)) // duplicate found
	{
		write(1, "Error\n", 6);
		free_stk(stack);
		return (NULL);
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

int	parse_args(int argc, char **argv, t_stack *a)
{
	int i;
	char **arr;
	int j;
	int num;

	if (!a)
		return (0);
	i = 1;
	while (i < argc)
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			return (0);
		j = 0;
		while (arr[j])
		{
			if (!digit_check(arr[j]))
			{
				free_arr(arr);
				ft_printf("Error\n");
				return (0);
			}
			num = ft_atoi(arr[j]);
			if (!adjust_stack(a, num))
			{
				free_arr(arr);
				return (0);
			}
			j++;
		}
		free_arr(arr);
		i++;
	}
	return (1);
}
