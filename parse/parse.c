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

static void	free_tokens(char **tokens)
{
	int i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
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
	if (!dub_check(stack, new_data))//FIXME:duplicate handling is incorrect; 

/*TODO: ft_atoi no integer overflow/range checking; 
int overflow / range: 
	ft_atoi() returns an int with undefined behavior on overflow. 
	Replace/augment with strtoll/ft_atoll and explicitly check the parsed value 
	is within INT_MIN..INT_MAX. On out-of-range, print "Error" and stop.*/
/*TODO: numeric parsing misses + and overflow detection.
digit_check(): 
	rejects leading + signs and allows a lone - to pass initial check but then 
	fails on empty string — cover + and - properly and reject strings like "+" 
	or "-" (no digits). Use isdigit for the rest.*/
	{
		ft_printf("Error\n");
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
	char **tokens;
	int j;
	int num;

	if (!a)
		return (0);
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		j = 0;
		while (tokens[j])
		{
			if (!digit_check(tokens[j]))
			{
				free_tokens(tokens);
				ft_printf("Error\n");
				return (0);
			}
			num = ft_atoi(tokens[j]);
			if (!adjust_stack(a, num))
			{
				free_tokens(tokens);
				return (0);
			}
			j++;
		}
		free_tokens(tokens);
		i++;
	}
	return (1);
}
